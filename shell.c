#include "shell.h"

int main(int ac, char **av, char **env)

{
	if (ac == 1)
	{
		openPrompt(av, env);
	}
	return (0);
}
