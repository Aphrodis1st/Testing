#include "shell.h"

/**
 * openPrompt - function for promt and urgiuments
 *
 * @av: - a pointer to a character to be printed
 * @env: - a character pointer for environment
 *
 * return: void
 */

void openPrompt(char **av, char **env)
{
	char *string = NULL, *argv[MAX_CMND];
	int i, status, s = 0;
	size_t n = 0;
	ssize_t num_char;
	pid_t child_pid;

	while (true)
	{
		printf("Home:~$ ");
		num_char = getline(&string, &n, stdin);
		if (num_char == -1)
		{
			free(string);
			exit(EXIT_FAILURE);
		}
		i = 0;
		while (string[i])
		{
			if (string[i] == '\n')
			string[i] = 0;
			i++;
		}
		argv[s] = strtok(string, " ");
		while (argv[s])
			argv[++s] = strtok(NULL, " ");
		child_pid = fork();
		if (child_pid == -1)
		{
			free(string);
			exit(EXIT_FAILURE);
		}
		if (child_pid == 0)
		{
			if (execve(argv[0], argv, env) == -1)
			printf("%s: No such file or directory!\n", av[0]);
		}
		else
		wait(&status);
	}
}
