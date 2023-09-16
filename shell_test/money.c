#include "shell.h"
/**
 * chstrtok - Print "$ " first ine
 * @str: string parameter
 * Return: Array of string
 */
char **chstrtok(char *str)
{
	char **arst, **pars;
	int i = 0, j = 0;

	arst = malloc(8 * sizeof(char *));
	if (arst == NULL)
	{
		perror("cant allocate space");
		exit(1);
	}
	pars = _strtok(str, " ");
	while (pars != NULL)
	{
		while (pars[j])
		{
			if (*pars[j] == '\n')
				pars[j] = '\0';
			j++;
		}
		arst[i] = pars[i];
		i++;
		j = 0;
		pars = _strtok(NULL, " ");
	}
	arst[i] = NULL;
	return (arst);
}
