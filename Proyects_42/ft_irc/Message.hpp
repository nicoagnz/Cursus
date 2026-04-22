#ifndef MESSAGE
#define MESSAGE

#include <string>
#include <vector>

class Message {
	private:
		std::string _prefix;
		std::string _command;
		std::vector<std::string> _parameters;

    public:
        Message(const std::string& rawLine);
        ~Message();
        std::string getPrefix() const;
        std::string getCommand() const;
        std::vector<std::string> getParameters() const;
        void setPrefix(const std::string& prefix);
        void setCommand(const std::string& command);
        void setParameters(const std::string& parameters);
};

#endif