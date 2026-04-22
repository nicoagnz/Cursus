NAME = ircserv

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f
RMDIR = rm -rf
OBJ_DIR = obj

SRCS = main.cpp \
	Server.cpp \
	Client.cpp \
	Message.cpp \
	Channel.cpp \
	CommandHandler.cpp \
	CommandHandlerFunctions/handleJoin.cpp \
	CommandHandlerFunctions/handlePart.cpp \
	CommandHandlerFunctions/handlePassword.cpp \
	CommandHandlerFunctions/handlePing.cpp \
	CommandHandlerFunctions/handlePrivmsg.cpp \
	CommandHandlerFunctions/handlePseudo.cpp \
	CommandHandlerFunctions/handleQuit.cpp \
	CommandHandlerFunctions/handleUser.cpp \
	CommandHandlerFunctions/handleWho.cpp \
	CommandHandlerFunctions/handleTopic.cpp \
	CommandHandlerFunctions/handleKick.cpp \
	CommandHandlerFunctions/handleInvite.cpp \
	CommandHandlerFunctions/handleMode.cpp \
	CommandHandlerFunctions/handleNames.cpp

OBJS = $(addprefix $(OBJ_DIR)/,$(SRCS:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(RMDIR) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
