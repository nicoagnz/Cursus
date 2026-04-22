#include "../CommandHandler.hpp"

void CommandHandler::handleModeKey(Channel* channel, bool set, Client& client, const std::string& key) {
    if (set) {
        channel->key = key;
        client.appendWriteBuffer(greenMessage(":ircserv MODE " + channel->getNameChannel() + " +k"));
    } else {
        channel->key.clear();
        client.appendWriteBuffer(greenMessage(":ircserv MODE " + channel->getNameChannel() + " -k"));
    }
}
