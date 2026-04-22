#include "../CommandHandler.hpp"

void CommandHandler::handlePseudo(Client& client, const Message& message, std::vector<Client*>& annular) {
    std::vector<std::string> params = message.getParameters();

    if (params.size() >= 1) {
        if (!params.front().empty()) {
            std::string pseudo = params.front();

            for (size_t i = 0; i < annular.size(); i++) {
                if (annular[i]->getNickname() == pseudo && annular[i] != &client) {
                    client.appendWriteBuffer(redMessage(":ircserv 433 * " + pseudo + " :Nickname is already in use"));
                    return;
                }
            }
            client.setHasNickname(true);
            client.setNickname(pseudo);
            checkRegistration(client);
        }
    } else
        client.appendWriteBuffer(redMessage(":ircserv 461 " + client.getNickname() + " NICK :Not enough parameters"));
}