*This project has been created as part of the 42 curriculum by **aboussem, pafuente, nacuna-g***

# ft_irc

## Description

ft_irc is a custom implementation of an Internet Relay Chat (IRC) server written in C++98.

The goal of this project is to understand and implement a real network protocol (IRC) using low-level system calls and non-blocking I/O. The server handles multiple clients simultaneously and allows real-time communication through channels, similar to traditional IRC servers.

The server follows the IRC protocol basics:
- TCP/IP communication
- Client authentication
- Nickname and username registration
- Channel management
- Message broadcasting

Only the server side is implemented. No client or server-to-server communication is included.

## Features

### Core Features
- Multiple client handling (non-blocking I/O)
- Authentication via password
- Nickname and username management
- Channel creation and joining
- Private messaging (client-to-client)
- Channel messaging (broadcast)

### Operator Commands
- `KICK` — Remove a user from a channel
- `INVITE` — Invite a user to a channel
- `TOPIC` — Set or view channel topic
- `MODE` — Manage channel modes:
  - `i` — Invite-only
  - `t` — Topic restricted to operators
  - `k` — Channel password
  - `o` — Operator privileges
  - `l` — User limit

## Architecture Overview

### Networking
- Uses TCP sockets
- Non-blocking file descriptors
- Multiplexing handled with `poll()` (or equivalent)

### Core Components
- **Server**
  - Accepts new connections
  - Manages file descriptors
- **Client**
  - Stores user state (nick, user, auth status)
- **Channel**
  - Manages users, operators, modes, and messages
- **Parser**
  - Reconstructs and interprets IRC commands from partial packets

### Key Challenges
- Handling partial reads (packet fragmentation)
- Maintaining state per client
- Avoiding blocking operations
- Correct command parsing

## Build Instructions

### Requirements
- C++ compiler with C++98 support
- Make

### Compile
```bash
make
```

### Run
```bash
./ircserv <port> <password>
```

*Example:*
```bash
./ircserv 6667 mypassword
```

### Usage

*You can connect using any IRC client such as:*

- irssi
- hexchat
- netcat (for testing)

### Example with netcat
```bash
nc -C 127.0.0.1 6667
```

### Basic IRC Flow
PASS "password"
NICK "nickname"
USER "username" 0 * :realname
JOIN #channel
PRIVMSG #channel :Hello world

### Testing Considerations

*The server correctly handles:*

- Partial command input (fragmented packets)
- Multiple simultaneous clients
- Invalid commands and error handling

*Example of fragmented input:*
```bash
com
man	
d\n
```

### Technical Choices
- C++98 standard (mandatory)
- poll() for multiplexing
- std::string for safer string manipulation
- Custom parser for IRC protocol compliance

*Alternative approaches considered:*

- select(): simpler but less scalable
- epoll(): more efficient but Linux-specific

### Limitations
- No server-to-server communication
- Limited subset of IRC protocol
- No TLS/SSL support
- No file transfer (bonus not implemented)

---

### Resources
#### Documentation & References

- **Socket Programming in C++**  
  A practical introduction to socket programming, covering TCP communication, server-client architecture, and basic networking concepts.  
  https://www.geeksforgeeks.org/socket-programming-in-cpp/

- **IRC Client-Server Communication Examples**  
  Provides concrete examples of IRC message exchanges and command flows between clients and servers. Useful for understanding protocol behavior.  
  https://chi.cs.uchicago.edu/chirc/irc_examples.html

- **RFC 1459 - Internet Relay Chat Protocol**
  Official specification of the IRC protocol, detailing commands, message formats, and expected server behavior.  
  https://datatracker.ietf.org/doc/html/rfc1459

- **ft_irc Project Guide (Medium Article)**  
  A high-level walkthrough of the project, including implementation steps and architectural insights.  
  https://medium.com/@afatir.ahmedfatir/small-irc-server-ft-irc-42-network-7cee848de6f9

#### AI Usage

AI tools were used for:

Understanding IRC protocol structure
Clarifying socket and poll() behavior
Generating test scenarios and edge cases

All generated content was reviewed, tested, and adapted before integration.