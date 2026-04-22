#include "../CommandHandler.hpp"
#include <vector>

void CommandHandler::handleModeOperator(Channel* channel, bool set, Client& client, const std::string& targetNick, std::vector<Client*>& annular) {
    (void)annular;
    Client* target = NULL;
    std::map<int, Client*> members = channel->getAllChanel();
    
    for (std::map<int, Client*>::iterator mit = members.begin(); mit != members.end(); ++mit) {
        if (mit->second->getNickname() == targetNick) {
            target = mit->second;
            break;
        }
    }
    if (!target) {
        client.appendWriteBuffer(redMessage(":ircserv 441 " + client.getNickname() + " " + targetNick + " " + channel->getNameChannel() + " :They aren't on that channel"));
        return;
    }
    if (set) {
        channel->addOperator(target);
        client.appendWriteBuffer(greenMessage(":ircserv MODE " + channel->getNameChannel() + " +o " + targetNick));
    } else {
        channel->removeOperator(target);
        client.appendWriteBuffer(greenMessage(":ircserv MODE " + channel->getNameChannel() + " -o " + targetNick));
    }
}
