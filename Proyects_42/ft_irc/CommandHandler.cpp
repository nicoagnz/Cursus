#include "CommandHandler.hpp"

CommandHandler::CommandHandler(std::string serverPassword): _serverPassword(serverPassword) {
    _commands.insert(std::make_pair("PASS", &CommandHandler::handlePassword));
    _commands.insert(std::make_pair("NICK", &CommandHandler::handlePseudo));
    _commands.insert(std::make_pair("USER", &CommandHandler::handleUser));
    _commands.insert(std::make_pair("PRIVMSG", &CommandHandler::handlePrivmsg));
    _commands.insert(std::make_pair("PING", &CommandHandler::handlePing));
    _commands.insert(std::make_pair("QUIT", &CommandHandler::handleQuit));
    _commands.insert(std::make_pair("JOIN", &CommandHandler::handleJoin));
    _commands.insert(std::make_pair("PART", &CommandHandler::handlePart));
    _commands.insert(std::make_pair("WHO", &CommandHandler::handleWho));
    _commands.insert(std::make_pair("TOPIC", &CommandHandler::handleTopic));
    _commands.insert(std::make_pair("KICK", &CommandHandler::handleKick));
    _commands.insert(std::make_pair("INVITE", &CommandHandler::handleInvite));
    _commands.insert(std::make_pair("MODE", &CommandHandler::handleMode));
    _commands.insert(std::make_pair("NAMES", &CommandHandler::handleNames));
}

CommandHandler::~CommandHandler() {
    std::map<std::string, Channel*>::iterator it = _channels.begin();
    std::map<std::string, Channel*>::iterator ite = _channels.end();

    while (it != ite)
    {
        std::map<std::string, Channel*>::iterator copyIt = it;
        it++;
        delete copyIt->second;
    }
    _channels.clear();
}

std::string CommandHandler::colorMessage(const std::string& message, const std::string& color) const {
    std::string ansiColor;

    if (color == "04")
        ansiColor = "\033[31m";
    else if (color == "03")
        ansiColor = "\033[32m";
    else if (color == "02")
        ansiColor = "\033[34m";
    else
        return message;

    return ansiColor + message + "\033[0m";
}

std::string CommandHandler::redMessage(const std::string& message) const {
    return colorMessage(message, "04");
}

std::string CommandHandler::greenMessage(const std::string& message) const {
    return colorMessage(message, "03");
}

std::string CommandHandler::blueMessage(const std::string& message) const {
    return colorMessage(message, "02");
}

void CommandHandler::execute(Client& client, const Message& message, std::vector<Client*>& annular) {
    std::string CommandWord = message.getCommand();

    if (CommandWord == "CAP") {
        client.setUseAnsiColors(!client.useAnsiColors());
        return;
    }

    std::map<std::string, CommandFn>::iterator it = _commands.find(CommandWord);
    if (it != _commands.end())
        (this->*(it->second))(client, message, annular);
    else
        client.appendWriteBuffer(redMessage(":ircserv 421 " + client.getNickname() + " " + CommandWord + " :Unknown command"));
}

void CommandHandler::checkRegistration(Client& client) {
	if (client.isRegistered())
		return;

    if (client.hasUser() && client.hasNickname() && client.hasPassed()) {
        client.setRegistered(true);
        client.appendWriteBuffer(greenMessage(":ircserv 001 " + client.getNickname() + " :Welcome to the ft_irc network!"));
    }
}

