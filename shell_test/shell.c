#include "shell.h"

void freetins(char *nc, char *ptr, char **string);
void _EOF(char *buffer);

/**
 * main - Main for Built shell
 * @argc: number of arguments
 * @argv: Array of arguments
 * @envp: Array of environment variables
 * Return: Always 0.
 */
int main(int argc, char *argv[], char *envp[])
{
	char **string;
	size_t n = 20, imbt = 0, pt = 4;
	ssize_t num_char;
	char *ptr, *nc;

	if (argc > 1)
		argv[1] = NULL;
	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "#cisfun$ ", 9);
		ptr = malloc(sizeof(char) * n);
		if (ptr == NULL)
			exit(0);
		num_char = _getline(&ptr, &n, stdin);
		if (num_char == -1)
			break;
		if (*ptr != '\n')
		{
			string = chstrtok(ptr);
			if (_strcmp("exit", string[0]) == 0)
				break;
			imbt = checkinbuilt(string[0]);
			nc = filechk(string[0]);
			if (imbt == 0 &&  nc != NULL)
				string[0] = nc;
			pt = pathchk(string[0]);
			if (pt == 1)
				forkexe(string, envp);
			if (nc == NULL && pt == 0 && imbt == 0)
				printf("./shell: No such file or directory\n");
			fflush(stdin);
			freetins(nc, ptr, string);
		}
	}
	fflush(stdin);
	freetins(nc, ptr, string);
	exit(0);
}
/**
 * main - Main for Built shell
 * @argc: number of arguments
 * @argv: Array of arguments
 * @envp: Array of environment variables
 * Return: Always 0.
 */
void freetins(char *nc, char *ptr, char **string)
{
	if (nc)
		free(nc);
	free(ptr);
	free(string);
}
/**
 * _EOF - A function that chaecks if buffer is EOF
 * @buffer: The pointer to the input string.
 * Return: Nothing
 */
void _EOF(char *buffer)
{
	if (buffer)
	{
		free(buffer);
		buffer = NULL;
	}

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
	free(buffer);
	exit(EXIT_SUCCESS);
}

