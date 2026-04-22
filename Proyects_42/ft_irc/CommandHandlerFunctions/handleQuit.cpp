#include "../CommandHandler.hpp"

void CommandHandler::handleQuit(Client& client, const Message& message, std::vector<Client*>& annular) {
    (void)annular;
    std::vector<std::string> params = message.getParameters();
    std::string quitMsg;

    if (params.size() >= 1)
        quitMsg = params.front();
    
    std::map<std::string, Channel*>::iterator it = _channels.begin();

    while (it != _channels.end()) {
        std::map<std::string, Channel*>::iterator itCopy = it;
        it++; 

        Channel* currentChannel = itCopy->second;
        
        std::map<int, Client*>::const_iterator searchClient = currentChannel->getAllChanel().find(client.getFd());

        if (searchClient != currentChannel->getAllChanel().end()) {
            
            std::map<int, Client*>::const_iterator firstClient = currentChannel->getAllChanel().begin();
            std::map<int, Client*>::const_iterator lastClient = currentChannel->getAllChanel().end();

            while (firstClient != lastClient) {
                firstClient->second->appendWriteBuffer(blueMessage(":" + client.getNickname() + " QUIT :Quit: " + quitMsg));
                firstClient++;
            }
            
            currentChannel->removeClient(client.getFd());

            if (currentChannel->getAllChanel().empty()) {
                delete currentChannel;
                _channels.erase(itCopy);
            }
        }
    }
    
    client.appendWriteBuffer(greenMessage(":ircserv NOTICE " + client.getNickname() + " :Closing Link: " + client.getIp() + " (Quit)"));
    client.setToBeDisconnected(true);
}