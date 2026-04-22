#ifndef SERVER_HPP
#define SERVER_HPP

#include <iostream>
#include <cstring>
#include <cerrno>
#include <cstdlib>
#include <unistd.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <vector>
#include <string>
#include <poll.h>
#include "Client.hpp"
#include "CommandHandler.hpp"

class Server {
    
    public:
        Server(int port, const std::string& password);
        ~Server();

        void initServer();
        void run();

    private:
        int _port;
        std::string _password;
        int _serverFd;
        int _nextClientId;
        std::vector<pollfd> _fds;
        std::vector<Client*> _clients;

        CommandHandler _handler;

        void acceptClient();
        void handleClientRead(size_t i);
        void handleClientWrite(size_t i);
        void flushPendingWrites();
        void disconnectClient(size_t i);
        Client* getClientByFd(int fd);
};

#endif