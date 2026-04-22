#include "../CommandHandler.hpp"
#include <cstdlib>
#include "handleModeInviteOnly.cpp"
#include "handleModeTopicRestricted.cpp"
#include "handleModeKey.cpp"
#include "handleModeOperator.cpp"
#include "handleModeLimit.cpp"


void CommandHandler::handleMode(Client& client, const Message& message, std::vector<Client*>& annular) {
	std::vector<std::string> params = message.getParameters();

	if (params.size() < 2) {
		client.appendWriteBuffer(redMessage(":ircserv 461 " + client.getNickname() + " MODE :Not enough parameters"));
		return;
	}
	std::string channelName = params[0];
	std::string modes = params[1];
	std::vector<std::string> modeParams(params.begin() + 2, params.end());

	std::map<std::string, Channel*>::iterator it = _channels.find(channelName);
	if (it == _channels.end()) {
		client.appendWriteBuffer(redMessage(":ircserv 403 " + client.getNickname() + " " + channelName + " :No such channel"));
		return;
	}

	Channel* channel = it->second;
	if (!channel->isOperator(&client)) {
		client.appendWriteBuffer(redMessage(":ircserv 482 " + client.getNickname() + " " + channelName + " :You're not channel operator"));
		return;
	}
	bool set = true;
	size_t paramIdx = 0;
	for (size_t i = 0; i < modes.size(); ++i) {
		char mode = modes[i];
		if (mode == '+') { set = true; continue; }
		if (mode == '-') { set = false; continue; }

		switch (mode) {
			case 'i':
				handleModeInviteOnly(channel, set, client);
				break;
			case 't':
				handleModeTopicRestricted(channel, set, client);
				break;
			case 'k':
				if (set && paramIdx < modeParams.size())
					handleModeKey(channel, set, client, modeParams[paramIdx++]);
				else if (!set)
					handleModeKey(channel, set, client, "");
				break;
			case 'o':
				if (paramIdx < modeParams.size())
					handleModeOperator(channel, set, client, modeParams[paramIdx++], annular);
				break;
			case 'l':
				if (set && paramIdx < modeParams.size())
					handleModeLimit(channel, set, client, std::atoi(modeParams[paramIdx++].c_str()));
				else if (!set)
					handleModeLimit(channel, set, client, -1);
				break;
			default:
				client.appendWriteBuffer(redMessage(":ircserv 472 " + client.getNickname() + " " + mode + " :is unknown mode char to me"));
				break;
		}
	}
}
