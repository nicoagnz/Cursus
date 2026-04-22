#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#include <iostream>
#include <set>
#include <string>
#include <map>
#include "Client.hpp"

class Channel {
	private:
		std::map<int, Client*> _clients;
		std::set<Client *> operators;
		std::set<Client *> invited;
		std::string _name;
	public:
		explicit Channel(const std::string &name = "");

		const std::string &getName() const;
		const std::string &getNameChannel() const;

		void addClient(Client& client);
		void removeClient(int fd);
		bool isClient(int fd) const;
		const std::map<int, Client*>& getAllChanel() const;

		void addOperator(Client *client);
		void removeOperator(Client *client);
		bool isOperator(Client *client) const;
		void getAllOperator();

		void invite(Client *client);
		void uninvite(Client *client);
		bool isInvited(Client *client) const;

		bool empty() const;
		size_t memberCount() const;

		std::string topic;
		bool inviteOnly;
		bool topicRestricted;
		std::string key;
		int userLimit;
};

#endif
