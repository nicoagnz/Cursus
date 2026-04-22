#include "../CommandHandler.hpp"

void CommandHandler::handleJoin(Client& client, const Message& message, std::vector<Client*>& annular) {
	(void)annular;
	std::vector<std::string> params = message.getParameters();
	
	if (params.size() < 1) {
		client.appendWriteBuffer(redMessage(":ircserv 461 " + client.getNickname() + " JOIN :Not enough parameters"));
		return;
	}

	std::string channelName = params.front();
	std::string password = "";
	if (params.size() == 2)
		password = params.back();
	
	if (channelName.empty() || channelName[0] != '#')
	{
		client.appendWriteBuffer(redMessage(":ircserv 403 " + client.getNickname() + " " + channelName + " :No such channel"));
		return ;
	}
	
	std::map<std::string, Channel*>::iterator it = _channels.find(channelName);
	Channel* currentChannel;

	if (it != _channels.end()) {
		currentChannel = it->second;
		if (currentChannel->userLimit != -1)
		{
			if (currentChannel->userLimit <= (int)currentChannel->getAllChanel().size())
			{
				client.appendWriteBuffer(redMessage(":ircserv 471 " + client.getNickname() + " " + currentChannel->getNameChannel() + " :Cannot join channel (+l)"));
				return ;
			}
		}
		if (currentChannel->inviteOnly)
		{
			if (!currentChannel->key.empty())
			{
				if (password != currentChannel->key)
				{
					client.appendWriteBuffer(redMessage(":ircserv 475 " + client.getNickname() + " " + currentChannel->getNameChannel() +" :Cannot join channel (+k)"));
					return ;
				}
			}
			if (currentChannel->isInvited(&client))
				it->second->addClient(client);
			else
			{
				client.appendWriteBuffer(redMessage(":ircserv 473 " + client.getNickname() + " " + currentChannel->getNameChannel() + " :Cannot join channel (+i)"));
				return ;
			}
	
		} else {
			if (!currentChannel->key.empty())
			{
				if (password != currentChannel->key)
				{
					client.appendWriteBuffer(redMessage(":ircserv 475 " + client.getNickname() + " " + currentChannel->getNameChannel() +" :Cannot join channel (+k)"));
					return ;
				}
			}
			it->second->addClient(client);
		}
	} else {
		currentChannel = new Channel(channelName);

		currentChannel->addOperator(&client);
		currentChannel->addClient(client);
		_channels.insert(std::make_pair(channelName, currentChannel));
	}

	std::map<int, Client*> allClients = currentChannel->getAllChanel();
	std::map<int, Client*>::const_iterator firstClient = allClients.begin();
	std::map<int, Client*>::const_iterator lastClient = allClients.end();
	std::string listNicks = "";

	while (firstClient != lastClient) {
		firstClient->second->appendWriteBuffer(greenMessage(":" + client.getNickname() + " JOIN " + channelName));
		std::string isOperator = currentChannel->isOperator(firstClient->second) ? "@" : "";
		listNicks += isOperator + firstClient->second->getNickname() + " ";
		firstClient++;
	}
	

	client.appendWriteBuffer(greenMessage(":ircserv 353 " + client.getNickname() + " = " + currentChannel->getNameChannel() + " :" + listNicks));
	client.appendWriteBuffer(greenMessage(":ircserv 366 " + client.getNickname() + " " + currentChannel->getNameChannel() + " :End of /NAMES list"));
}