#include "../CommandHandler.hpp"

void CommandHandler::handleUser(Client& client, const Message& message, std::vector<Client*>& annular) {
    (void)annular;
    std::vector<std::string> params = message.getParameters();

    if (params.size() == 4) {
        client.setUsername(params.front());
        client.setRealname(params.back());
        client.setHasUser(true);
        checkRegistration(client);
    } else
        client.appendWriteBuffer(redMessage(":ircserv 461 " + client.getNickname() + " USER :Not enough parameters"));
}
