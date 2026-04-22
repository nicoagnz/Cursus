#include "../CommandHandler.hpp"

void CommandHandler::handlePart(Client& client, const Message& message, std::vector<Client*>& annular) {
    (void)annular;
    std::vector<std::string> params = message.getParameters();

    if (params.size() < 1) {
        client.appendWriteBuffer(redMessage(":ircserv 461 " + client.getNickname() + " PART :Not enough parameters"));
        return;
    }

    std::string channelName = params.front();
    std::string partMsg;

    if (params.size() > 1)
        partMsg = params.back();
    
    std::map<std::string, Channel*>::iterator it = _channels.find(channelName);
    Channel* currentChannel;

    if (it != _channels.end()) {
        currentChannel = it->second;
        std::map<int, Client*>::const_iterator itc = currentChannel->getAllChanel().find(client.getFd());
        if (itc == currentChannel->getAllChanel().end()) {
            client.appendWriteBuffer(redMessage(":ircserv 442 " + client.getNickname() + " " + channelName + " :You're not on that channel"));
            return;
        }
    } else {
        client.appendWriteBuffer(redMessage(":ircserv 403 " + client.getNickname() + " " + channelName + " :No such channel"));
        return;
    }

    std::map<int, Client*>::const_iterator firstClient = currentChannel->getAllChanel().begin();
    std::map<int, Client*>::const_iterator lastClient = currentChannel->getAllChanel().end();

    while (firstClient != lastClient) {
        firstClient->second->appendWriteBuffer(greenMessage(":" + client.getNickname() + " PART " + channelName + (!partMsg.empty() ? " :" + partMsg : "")));
        
        firstClient++;
    }

    currentChannel->removeClient(client.getFd());

    if (currentChannel->getAllChanel().empty()) {
        _channels.erase(channelName);
        delete currentChannel;
    }
}
