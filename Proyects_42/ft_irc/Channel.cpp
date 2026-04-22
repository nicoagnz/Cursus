#include "Channel.hpp"

Channel::Channel(const std::string &name)
	: _name(name), inviteOnly(false), topicRestricted(true), userLimit(-1) {}

const std::string &Channel::getName() const { return _name; }

const std::string &Channel::getNameChannel() const { return _name; }

void Channel::addClient(Client& client) {
	_clients[client.getFd()] = &client;
}

void Channel::removeClient(int fd) {
	std::map<int, Client*>::iterator it = _clients.find(fd);
	if (it != _clients.end()) {
		operators.erase(it->second);
		invited.erase(it->second);
		_clients.erase(it);
	}
}

bool Channel::isClient(int fd) const {
	return _clients.find(fd) != _clients.end();
}

const std::map<int, Client*>& Channel::getAllChanel() const {
	return _clients;
}

void Channel::addOperator(Client *client) { operators.insert(client); }

void Channel::getAllOperator() { 
	std::set<Client*>::iterator it = operators.begin();
	std::set<Client*>::iterator ite = operators.end();

	while (it != ite)
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}

void Channel::removeOperator(Client *client) { operators.erase(client); }

bool Channel::isOperator(Client *client) const { return operators.find(client) != operators.end(); }

void Channel::invite(Client *client) { invited.insert(client); }

void Channel::uninvite(Client *client) { invited.erase(client); }

bool Channel::isInvited(Client *client) const { return invited.find(client) != invited.end(); }

bool Channel::empty() const { return _clients.empty(); }

size_t Channel::memberCount() const { return _clients.size(); }
