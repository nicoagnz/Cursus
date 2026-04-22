#include "../CommandHandler.hpp"

void CommandHandler::handleNames(Client& client, const Message& message, std::vector<Client*>& annular) {
	(void)annular;
	std::vector<std::string> params = message.getParameters();

	if (params.size() < 1) {
		client.appendWriteBuffer(redMessage(":ircserv 461 " + client.getNickname() + " NAMES :Not enough parameters"));
		return;
	}

	std::string channelName = params.front();
	std::map<std::string, Channel*>::iterator it = _channels.find(channelName);
	if (it == _channels.end()) {
		client.appendWriteBuffer(redMessage(":ircserv 403 " + client.getNickname() + " " + channelName + " :No such channel"));
		return;
	}


	std::map<int, Client*> allClients =  it->second->getAllChanel();
	std::map<int, Client*>::const_iterator firstClient = allClients.begin();
	std::map<int, Client*>::const_iterator lastClient = allClients.end();
	std::string listNicks = "";

	while (firstClient != lastClient) {
		std::string isOperator = it->second->isOperator(firstClient->second) ? "@" : "";
		listNicks += isOperator + firstClient->second->getNickname() + " ";
		firstClient++;
	}

	client.appendWriteBuffer(greenMessage(":ircserv 353 " + client.getNickname() + " = " + it->second->getNameChannel() + " :" + listNicks));
	client.appendWriteBuffer(greenMessage(":ircserv 366 " + client.getNickname() + " " + it->second->getNameChannel() + " :End of /NAMES list"));
}

