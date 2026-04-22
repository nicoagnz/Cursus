#include "Message.hpp"
#include <iostream>

Message::Message(const std::string& rawLine) {
	std::string copyRawLine = rawLine;

	if (rawLine.empty()) {
		setCommand("");
		return;
	}

	if (copyRawLine[0] == ':') {
		setPrefix(copyRawLine.substr(1, copyRawLine.find(" ") - 1));
		copyRawLine.erase(0, copyRawLine.find(" ") + 1);
	}

	if (copyRawLine.find(" ") == std::string::npos) {
		setCommand(copyRawLine);
		copyRawLine.clear();
		return;
	}
	setCommand(copyRawLine.substr(0, copyRawLine.find(" ")));
	copyRawLine.erase(0, copyRawLine.find(" ") + 1);
	
	setParameters(copyRawLine);
}

Message::~Message() {}

std::string Message::getPrefix() const {
	return _prefix;
}

std::string Message::getCommand() const {
	return _command;
}

std::vector<std::string> Message::getParameters() const {
	return _parameters;
}

void Message::setPrefix(const std::string& prefix) {
	_prefix = prefix;
}

void Message::setCommand(const std::string& command) {
	_command = command;
}

void Message::setParameters(const std::string& parameters) {
	_parameters.clear();

	std::string copyParameters = parameters;

	while (copyParameters != "") {
		size_t posSpace = copyParameters.find(" ");
		size_t posDoublePoint = copyParameters.find(":");

		if (posSpace < posDoublePoint && posSpace != std::string::npos) {
			_parameters.push_back(copyParameters.substr(0, posSpace));
			copyParameters.erase(0, posSpace + 1);
		} else {
			if (copyParameters[0] == ':')
				_parameters.push_back(copyParameters.substr(1));
			else
				_parameters.push_back(copyParameters);
			copyParameters.clear();
		}
	}
}
