#include "../CommandHandler.hpp"

void CommandHandler::handleModeTopicRestricted(Channel* channel, bool set, Client& client) {
    channel->topicRestricted = set;
    client.appendWriteBuffer(greenMessage(":ircserv MODE " + channel->getNameChannel() + (set ? " +t" : " -t")));
}
