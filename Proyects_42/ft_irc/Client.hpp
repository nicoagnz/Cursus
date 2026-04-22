#ifndef CLIENT
#define CLIENT

#include <string>

class Client {
    private:
        int _id;
        int _fd;
        std::string _ip;
        std::string _readBuffer;
        std::string _writeBuffer;
        std::string _nickname;
        std::string _username;
        std::string _realname;
        bool _isRegistered;
        bool _hasPassed;
        bool _hasNickname;
        bool _hasUser;
        bool _toDisconnected;
        bool _useAnsiColors;

    public:
        Client(int id, int fd, std::string ip);
        ~Client();
        int getId() const;
        int getFd() const;
        std::string getIp() const;
        std::string getReadBuffer() const;
        std::string getWriteBuffer() const;
        std::string getNickname() const;
        std::string getUsername() const;
        std::string getRealname() const;
        bool isRegistered() const;
        bool hasPassed() const;
        bool hasNickname() const;
        bool hasUser() const;
        bool isToBeDisconnected() const;
        void setReadBuffer(const std::string& buffer);
        void setWriteBuffer(const std::string& buffer);
        void setNickname(const std::string& nickname);
        void setUsername(const std::string& username);
        void setRealname(const std::string& realname);
        void setRegistered(bool isRegistered);
        void setHasPassed(bool hasPassed);
        void setHasNickname(bool hasNickname);
        void setHasUser(bool hasUser);
        void setToBeDisconnected(bool status);
        void setUseAnsiColors(bool status);
        void appendReadBuffer(std::string data);
        void appendWriteBuffer(std::string message);
        bool hasCompleteLine() const;
        bool useAnsiColors() const;
        std::string extractLine();
};

#endif