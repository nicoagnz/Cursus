#include "../CommandHandler.hpp"

void CommandHandler::handleModeInviteOnly(Channel* channel, bool set, Client& client) {
	channel->inviteOnly = set;
	client.appendWriteBuffer(greenMessage(":ircserv MODE " + channel->getNameChannel() + (set ? " +i" : " -i")));
}
