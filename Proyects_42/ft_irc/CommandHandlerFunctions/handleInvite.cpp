#include "../CommandHandler.hpp"

void CommandHandler::handleInvite(Client& client, const Message& message, std::vector<Client*>& annular) {
	std::vector<std::string> params = message.getParameters();
	if (params.size() < 2) {
		client.appendWriteBuffer(redMessage(":ircserv 461 " + client.getNickname() + " INVITE :Not enough parameters"));
		return;
	}
	std::string channelName = params[0];
	std::string targetNick = params[1];

	std::map<std::string, Channel*>::iterator it = _channels.find(channelName);
	if (it == _channels.end()) {
		client.appendWriteBuffer(redMessage(":ircserv 403 " + client.getNickname() + " " + channelName + " :No such channel"));
		return;
	}
	Channel* channel = it->second;
	if (!channel->isClient(client.getFd())) {
		client.appendWriteBuffer(redMessage(":ircserv 442 " + client.getNickname() + " " + channelName + " :You're not on that channel"));
		return;
	}
	if (channel->inviteOnly && !channel->isOperator(&client)) {
		client.appendWriteBuffer(redMessage(":ircserv 482 " + client.getNickname() + " " + channelName + " :You're not channel operator"));
		return;
	}
	Client* target = NULL;
	for (size_t i = 0; i < annular.size(); ++i) {
		if (annular[i]->getNickname() == targetNick) {
			target = annular[i];
			break;
		}
	}
	if (!target) {
		client.appendWriteBuffer(redMessage(":ircserv 401 " + client.getNickname() + " " + targetNick + " :No such nick"));
		return;
	}
	if (channel->isClient(target->getFd())) {
		client.appendWriteBuffer(redMessage(":ircserv 443 " + client.getNickname() + " " + targetNick + " " + channelName + " :is already on channel"));
		return;
	}
	channel->invite(target);
	target->appendWriteBuffer(blueMessage(":" + client.getNickname() + "!" + client.getUsername() + "@" + client.getIp() + " INVITE " + targetNick + " " + channelName));
	client.appendWriteBuffer(greenMessage(":ircserv 341 " + client.getNickname() + " " + targetNick + " " + channelName));
}
