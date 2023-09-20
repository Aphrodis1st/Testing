#include "shell.h"

int _execute(char **command, char **argv, int idx)
{
	char *full_cmd;
	pid_t child;
	int status;

	full_cmd = _getpath(command[0]);
	if (!full_cmd)
	{
		print_error(argv[0], command[0], idx);
		freeString(command);
		return(127);
	}

	child = fork();
	if (child == 0)
	{
		if (execve(full_cmd, command, environ) == -1)
		{
			free(full_cmd), full_cmd = NULL;
			freeString(command);
		}
	}

	else
	{
		waitpid(child, &status, 0);
		freeString(command);
		free(full_cmd), full_cmd = NULL;
	}

	return (WEXITSTATUS(status));
}
