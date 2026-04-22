#include "../CommandHandler.hpp"

void CommandHandler::handlePrivmsg(Client& client, const Message& message, std::vector<Client*>& annular) {
	std::vector<std::string> params = message.getParameters();

	if (params.size() < 2) {
		client.appendWriteBuffer(redMessage(":ircserv 461 " + client.getNickname() + " PRIVMSG :Not enough parameters"));
		return;
	}

	std::string recipient = params.front();
	std::string msgText = params.back();
	if (recipient[0] == '#') {
		std::map<std::string, Channel *>::iterator it = _channels.find(recipient);

		if (it == _channels.end()) {
			client.appendWriteBuffer(redMessage(":ircserv 403 " + client.getNickname() + " " + recipient + " :No such channel"));
			return;
		}

		if (it->second->getAllChanel().find(client.getFd()) == it->second->getAllChanel().end()) {
			client.appendWriteBuffer(redMessage(":ircserv 404 " + client.getNickname() + " " + recipient + " :Cannot send to channel"));
			return;
		}

		std::map<int, Client*>::const_iterator itc = it->second->getAllChanel().begin();
		std::map<int, Client*>::const_iterator itce = it->second->getAllChanel().end();
		
		while (itc != itce)
		{
			std::string isOperator = it->second->isOperator(&client) ? "@" : "";
			if (itc->second->getFd() != client.getFd())
				itc->second->appendWriteBuffer(greenMessage(":" + isOperator + client.getNickname() + " PRIVMSG " + recipient + " :" + msgText));
			itc++;
		}
	} else {
		for (size_t i = 0; i < annular.size(); i++) {
			if (annular[i]->getNickname() == recipient) {
				annular[i]->appendWriteBuffer(blueMessage(":" + client.getNickname() + " PRIVMSG " + recipient + " :" + msgText));
				return;
			}
		}
		client.appendWriteBuffer(redMessage(":ircserv 401 " + client.getNickname() + " " + recipient + " :No such nick/channel"));
	}
}
