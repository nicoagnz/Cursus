# IRC Server Commands (ft_irc)

This is a quick guide to the commands supported by this server.

## 1) Starting the Server

Run the server before opening your IRC clients:

```bash
./ircserv <port> <password>
```

Example:

```bash
./ircserv 6667 1234
```

Notes:
- The port must be numeric and between `1024` and `65535`.
- The password cannot be empty.

## 2) Initial Registration (Recommended Order)

1. `PASS <password>`
2. `NICK <nickname>`
3. `USER <username> 0 * :<realname>`

Once you complete `PASS + NICK + USER`, the server responds with `001 Welcome`.

## 3) Available Commands

### PASS
- Usage: `PASS <password>`
- Example: `PASS 1234`
- Description: validates the server password.

### NICK
- Usage: `NICK <nickname>`
- Example: `NICK pafuente`
- Description: sets or changes your nickname.
- Common error: if the nickname already exists, it returns `433`.

### USER
- Usage: `USER <username> 0 * :<realname>`
- Example: `USER pafuente 0 * :Pablo Fuente`
- Description: registers username and real name.

### JOIN
- Usage: `JOIN <#channel>`
- Example: `JOIN #general`
- Description: joins a channel (if it doesn't exist, it's created).

### PART
- Usage: `PART <#channel> [:message]`
- Example: `PART #general :leaving now`
- Description: leaves the channel.

### PRIVMSG
- Usage (private): `PRIVMSG <nick> :<message>`
- Example: `PRIVMSG maria :hello!`
- Usage (channel): `PRIVMSG <#channel> :<message>`
- Example: `PRIVMSG #general :hello everyone`
- Description: sends messages to users or channels.

### PING
- Usage: `PING <token>`
- Example: `PING 12345`
- Description: server responds with `PONG`.

### QUIT
- Usage: `QUIT [:message]`
- Example: `QUIT :goodbye`
- Description: closes your connection.

### CAP
- Usage: `CAP ...`
- Example: `CAP`
- Description: in this implementation it's used to disable/enable ANSI colors in responses.

## 4) Complete Example Flow

```irc
PASS 1234
NICK pafuente
USER pafuente 0 * :Pablo Fuente
JOIN #general
PRIVMSG #general :hello team
PART #general :see you
QUIT :bye
```

## 5) Real Example with Multiple Users and Channel Creation

In IRC, the channel is automatically created when the first user does `JOIN`.

### Terminal 0 (Server)

```bash
./ircserv 6667 1234
```

Start the server first, then connect user terminals.

### Terminal A/B/C (Clients)

Open a connection to the server with `nc` before writing IRC commands:

```bash
nc localhost 6667
```

### Terminal A (Ana)

```irc
PASS 1234
NICK ana
USER ana 0 * :Ana Lopez
JOIN #team
PRIVMSG #team :Hello, I just created the #team channel
```

### Terminal B (Luis)

```irc
PASS 1234
NICK luis
USER luis 0 * :Luis Perez
JOIN #team
PRIVMSG #team :Hi Ana, I'm in
```

### Terminal C (Marta)

```irc
PASS 1234
NICK marta
USER marta 0 * :Marta Ruiz
JOIN #team
PRIVMSG ana :Hi Ana, I'm sending you a private message
```

Now you have:
- Channel created (`#team`) by Ana.
- Users added to the channel (Luis and Marta with `JOIN #team`).
- Channel messages and private messages between users.

### Leave the Channel and Disconnect

```irc
PART #team :leaving the channel
QUIT :goodbye
```

## 6) Common Errors

- `461` Not enough parameters
- `464` Password incorrect
- `433` Nickname is already in use
- `401` No such nick/channel
- `403` No such channel
- `404` Cannot send to channel
- `442` You're not on that channel
