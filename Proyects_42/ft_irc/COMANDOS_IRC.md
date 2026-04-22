# Lista de comandos IRC (ft_irc)

Esta es una guia rapida de los comandos que soporta este servidor.

## 1) Iniciar el servidor

Ejecuta el servidor antes de abrir tus clientes IRC:

```bash
./ircserv <puerto> <password>
```

Ejemplo:

```bash
./ircserv 6667 1234
```

Notas:
- El puerto debe ser numerico y estar entre `1024` y `65535`.
- La password no puede estar vacia.

## 2) Registro inicial (orden recomendado)

1. `PASS <password>`
2. `NICK <apodo>`
3. `USER <username> 0 * :<realname>`

Cuando completas `PASS + NICK + USER`, el servidor responde con `001 Welcome`.

## 3) Comandos disponibles

### PASS
- Uso: `PASS <password>`
- Ejemplo: `PASS 1234`
- Descripcion: valida la contrasena del servidor.

### NICK
- Uso: `NICK <apodo>`
- Ejemplo: `NICK pafuente`
- Descripcion: establece o cambia tu nick.
- Error comun: si el nick ya existe, devuelve `433`.

### USER
- Uso: `USER <username> 0 * :<realname>`
- Ejemplo: `USER pafuente 0 * :Pablo Fuente`
- Descripcion: registra usuario y nombre real.

### JOIN
- Uso: `JOIN <#canal>`
- Ejemplo: `JOIN #general`
- Descripcion: entra a un canal (si no existe, se crea).

### PART
- Uso: `PART <#canal> [:mensaje]`
- Ejemplo: `PART #general :me voy`
- Descripcion: sale del canal.

### PRIVMSG
- Uso (privado): `PRIVMSG <nick> :<mensaje>`
- Ejemplo: `PRIVMSG maria :hola!`
- Uso (canal): `PRIVMSG <#canal> :<mensaje>`
- Ejemplo: `PRIVMSG #general :buenas a todos`
- Descripcion: envia mensajes a usuarios o canales.

### PING
- Uso: `PING <token>`
- Ejemplo: `PING 12345`
- Descripcion: el servidor responde con `PONG`.

### QUIT
- Uso: `QUIT [:mensaje]`
- Ejemplo: `QUIT :hasta luego`
- Descripcion: cierra tu conexion.

### CAP
- Uso: `CAP ...`
- Ejemplo: `CAP`
- Descripcion: en esta implementacion se usa para desactivar/activar colores ANSI en respuestas.

## 4) Flujo de ejemplo completo

```irc
PASS 1234
NICK pafuente
USER pafuente 0 * :Pablo Fuente
JOIN #general
PRIVMSG #general :hola equipo
PART #general :nos vemos
QUIT :bye
```

## 5) Ejemplo real con varias personas y creacion de canal

En IRC, el canal se crea automaticamente cuando el primer usuario hace `JOIN`.

### Terminal 0 (Servidor)

```bash
./ircserv 6667 1234
```

Inicia primero el servidor y luego conecta las terminales de usuarios.

### Terminal A/B/C (Clientes)

Abre una conexion al servidor con `nc` antes de escribir los comandos IRC:

```bash
nc localhost 6667
```

### Terminal A (Ana)

```irc
PASS 1234
NICK ana
USER ana 0 * :Ana Lopez
JOIN #equipo
PRIVMSG #equipo :Hola, acabo de crear el canal #equipo
```

### Terminal B (Luis)

```irc
PASS 1234
NICK luis
USER luis 0 * :Luis Perez
JOIN #equipo
PRIVMSG #equipo :Buenas Ana, ya entre
```

### Terminal C (Marta)

```irc
PASS 1234
NICK marta
USER marta 0 * :Marta Ruiz
JOIN #equipo
PRIVMSG ana :Hola Ana, te escribo por privado
```

Con eso ya tienes:
- Canal creado (`#equipo`) por Ana.
- Personas anadidas al canal (Luis y Marta con `JOIN #equipo`).
- Mensajes al canal y mensajes privados entre usuarios.

### Salir del canal y desconectar

```irc
PART #equipo :me salgo del canal
QUIT :hasta luego
```

## 6) Errores frecuentes

- `461` Not enough parameters
- `464` Password incorrect
- `433` Nickname is already in use
- `401` No such nick/channel
- `403` No such channel
- `404` Cannot send to channel
- `442` You're not on that channel
