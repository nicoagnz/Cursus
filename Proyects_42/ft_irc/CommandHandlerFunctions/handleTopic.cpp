#include "../CommandHandler.hpp"

void CommandHandler::handleTopic(Client& client, const Message& message, std::vector<Client*>& annular) {
    (void)annular;
    std::vector<std::string> params = message.getParameters();

    if (params.size() < 1) {
        client.appendWriteBuffer(redMessage(":ircserv 461 " + client.getNickname() + " TOPIC :Not enough parameters"));
        return;
    }
    std::string channelName = params[0];
    std::string newTopic = (params.size() > 1) ? params[1] : "";

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
    if (newTopic.empty()) {
        if (channel->topic.empty()) {
            client.appendWriteBuffer(greenMessage(":ircserv 331 " + client.getNickname() + " " + channelName + " :No topic is set"));
        } else {
            client.appendWriteBuffer(greenMessage(":ircserv 332 " + client.getNickname() + " " + channelName + " :" + channel->topic));
        }
        return;
    }
    if (channel->topicRestricted && !channel->isOperator(&client)) {
        client.appendWriteBuffer(redMessage(":ircserv 482 " + client.getNickname() + " " + channelName + " :You're not channel operator"));
        return;
    }
    channel->topic = newTopic;
    std::map<int, Client*> members = channel->getAllChanel();
    std::string topicMsg = ":" + client.getNickname() + "!" + client.getUsername() + "@" + client.getIp() + " TOPIC " + channelName + " :" + newTopic;
    for (std::map<int, Client*>::iterator mit = members.begin(); mit != members.end(); ++mit) {
        mit->second->appendWriteBuffer(greenMessage(topicMsg));
    }
}
