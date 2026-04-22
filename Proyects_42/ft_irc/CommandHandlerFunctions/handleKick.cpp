#include "../CommandHandler.hpp"

void CommandHandler::handleKick(Client& client, const Message& message, std::vector<Client*>& annular) {
    (void)annular;
    std::vector<std::string> params = message.getParameters();

    if (params.size() < 2) {
        client.appendWriteBuffer(redMessage(":ircserv 461 " + client.getNickname() + " KICK :Not enough parameters"));
        return;
    }
    std::string channelName = params[0];
    std::string targetNick = params[1];
    std::string reason = (params.size() > 2) ? params[2] : "";

    std::map<std::string, Channel*>::iterator it = _channels.find(channelName);
    if (it == _channels.end()) {
        client.appendWriteBuffer(redMessage(":ircserv 403 " + client.getNickname() + " " + channelName + " :No such channel"));
        return;
    }
    Channel* channel = it->second;
    if (!channel->isOperator(&client)) {
        client.appendWriteBuffer(redMessage(":ircserv 482 " + client.getNickname() + " " + channelName + " :You're not channel operator"));
        return;
    }
    Client* target = NULL;
    std::map<int, Client*> members = channel->getAllChanel();
    for (std::map<int, Client*>::iterator mit = members.begin(); mit != members.end(); ++mit) {
        if (mit->second->getNickname() == targetNick) {
            target = mit->second;
            break;
        }
    }
    if (!target) {
        client.appendWriteBuffer(redMessage(":ircserv 441 " + client.getNickname() + " " + targetNick + " " + channelName + " :They aren't on that channel"));
        return;
    }
    std::string kickMsg = ":" + client.getNickname() + "!" + client.getUsername() + "@" + client.getIp() + " KICK " + channelName + " " + targetNick + (reason.empty() ? "" : " :" + reason);
    std::map<int, Client*>::iterator mit = members.begin();
    for (; mit != members.end(); ++mit) {
        mit->second->appendWriteBuffer(greenMessage(kickMsg));
    }
    channel->removeClient(target->getFd());
    if (channel->empty()) {
        _channels.erase(channelName);
        delete channel;
    }
}
