#include "Client.hpp"

Client::Client(int id, int fd, std::string ip) : _id(id), _fd(fd), _ip(ip) {
    _isRegistered = false;
    _hasPassed = false;
    _hasNickname = false;
    _hasUser = false;
    _toDisconnected = false;
    _useAnsiColors = true;

	_readBuffer.clear();
	_writeBuffer.clear();
}

Client::~Client() {}

int Client::getId() const {
    return _id;
}

int Client::getFd() const {
	return _fd;
}

std::string Client::getIp() const {
	return _ip;
}

std::string Client::getReadBuffer() const {
	return _readBuffer;
}

std::string Client::getWriteBuffer() const {
	return _writeBuffer;
}

std::string Client::getNickname() const {
	return _nickname;
}

std::string Client::getUsername() const {
	return _username;
}

std::string Client::getRealname() const {
	return _realname;
}

bool Client::isRegistered() const {
	return _isRegistered;
}

bool Client::hasPassed() const {
	return _hasPassed;
}

bool Client::hasNickname() const {
	return _hasNickname;
}

bool Client::hasUser() const {
	return _hasUser;
}

bool Client::isToBeDisconnected() const {
	return _toDisconnected;
}

bool Client::useAnsiColors() const {
    return _useAnsiColors;
}

void Client::setReadBuffer(const std::string& buffer) {
	_readBuffer = buffer;
}

void Client::setWriteBuffer(const std::string& buffer) {
	_writeBuffer = buffer;
}

void Client::setNickname(const std::string& nickname) {
	_nickname = nickname;
}

void Client::setUsername(const std::string& username) {
	_username = username;
}

void Client::setRealname(const std::string& realname) {
	_realname = realname;
}

void Client::setRegistered(bool isRegistered) {
	_isRegistered = isRegistered;
}

void Client::setHasPassed(bool hasPassed) {
	_hasPassed = hasPassed;
}

void Client::setHasNickname(bool hasNickname) {
	_hasNickname = hasNickname;
}

void Client::setHasUser(bool hasUser) {
	_hasUser = hasUser;
}

void Client::setToBeDisconnected(bool status) {
	_toDisconnected = status;
}

void Client::setUseAnsiColors(bool status) {
    _useAnsiColors = status;
}

std::string Client::extractLine() {
	size_t pos = _readBuffer.find('\n');

	if (pos == std::string::npos)
		return "";

	std::string line = _readBuffer.substr(0, pos);
	if (!line.empty() && line[line.length() - 1] == '\r')
		line.erase(line.length() - 1);

	_readBuffer.erase(0, pos + 1);
	
	return line;
}

void Client::appendReadBuffer(std::string data) {
	_readBuffer.append(data);
}

bool Client::hasCompleteLine() const {
	return _readBuffer.find('\n') != std::string::npos;
}

void Client::appendWriteBuffer(std::string message) {
    if (!_useAnsiColors) {
        std::string cleaned;
        cleaned.reserve(message.size());

        for (size_t i = 0; i < message.size(); ) {
            if (message[i] == '\033' && i + 1 < message.size() && message[i + 1] == '[') {
                i += 2;
                while (i < message.size() && message[i] != 'm')
                    i++;
                if (i < message.size())
                    i++;
                continue;
            }
            cleaned.push_back(message[i]);
            i++;
        }
        message = cleaned;
    }

    if (message.length() < 2 || message.substr(message.length() - 2) != "\r\n")
        message.append("\r\n");
    
    _writeBuffer.append(message);
}