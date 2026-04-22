#include "Server.hpp"

static bool parsePort(const std::string& text, int& port) {
    if (text.empty())
        return false;

    long value = 0;
    for (size_t i = 0; i < text.size(); ++i) {
        if (!std::isdigit(static_cast<unsigned char>(text[i])))
            return false;

        value = value * 10 + (text[i] - '0');
        if (value > 65535)
            return false;
    }

    if (value < 1024)
        return false;

    port = static_cast<int>(value);
    return true;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        std::cerr << "Usage: ./ircserv <port> <password>\n";
        return 1;
    }

    int port = 0;
    if (!parsePort(argv[1], port)) {
        std::cerr << "Invalid port. Use a numeric value between 1024 and 65535.\n";
        return 1;
    }

    std::string password = argv[2];
    if (password.empty()) {
        std::cerr << "Password cannot be empty.\n";
        return 1;
    }

    Server server(port, password);

    server.initServer();
    server.run();

    return 0;
}