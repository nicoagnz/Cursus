#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

/*
cmds es un array de comandos.
Cada comando es un array de strings terminado en NULL.
El array de comandos también termina en NULL.
*/

int picoshell(char ***cmds)
{
	int i = 0;				// Índice del comando actual
	int input_fd = 0;		// De dónde leerá el comando actual (stdin al inicio)
	int pipefd[2];			// Pipe para conectar comando actual con el siguiente
	int status;
	int error = 0;

	while (cmds[i] != NULL)
	{
		// Crear un pipe para este comando
		pipe(pipefd);

		pid_t pid = fork();

		if (pid == 0) // PROCESO HIJO
		{
			// 1. Conectar la entrada
			// Si input_fd == 0 → stdin normal
			// Si no → viene del pipe anterior
			dup2(input_fd, STDIN_FILENO);

			// 2. Conectar la salida SOLO si hay un comando después
			if (cmds[i + 1] != NULL)
				dup2(pipefd[1], STDOUT_FILENO);

			// 3. Cerrar descriptores que ya no se usan
			if (input_fd != 0)
				close(input_fd);

			close(pipefd[0]);
			close(pipefd[1]);

			// 4. Ejecutar el comando
			execvp(cmds[i][0], cmds[i]);

			// Si exec falla
			exit(1);
		}

		// PROCESO PADRE

		// El padre no escribe en el pipe
		close(pipefd[1]);

		// El padre ya no necesita el pipe anterior
		if (input_fd != 0)
			close(input_fd);

		// El siguiente comando leerá de aquí
		input_fd = pipefd[0];

		i++;
	}

	// Cerrar el último pipe si quedó abierto
	if (input_fd != 0)
		close(input_fd);

	// Esperar a todos los hijos
	while (wait(&status) > 0)
	{
		if (status != 0)
			error = 1;
	}

	return error;
}

