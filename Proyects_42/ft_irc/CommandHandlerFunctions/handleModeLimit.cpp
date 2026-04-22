#include "../CommandHandler.hpp"
#include <sstream>

void CommandHandler::handleModeLimit(Channel* channel, bool set, Client& client, int limit) {
	if (set && limit > 0) {
		channel->userLimit = limit;
		std::ostringstream oss;
		oss << limit;
		client.appendWriteBuffer(greenMessage(":ircserv MODE " + channel->getNameChannel() + " +l " + oss.str()));
	} else {
		channel->userLimit = -1;
		client.appendWriteBuffer(greenMessage(":ircserv MODE " + channel->getNameChannel() + " -l"));
	}
}
