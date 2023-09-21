#include "shell.h"

/**
 * interactive - returns true if shell is interactive mode
 * @info: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
 
 
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - looks for character if is a delimeter
 * @c: the character to  be checked
 * @delim: the delimeter string
 * Return: 1 if true, 0 if false
 */
 
 
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - looks for an alphabetic characters
 * @c: The character to input
 * Return: 1 if true, otherwise 0.
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - converts a string to an integer
 * @strn: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *strn)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; strn[i] != '\0' && flag != 2; i++)
	{
		if (strn[i] == '-')
			sign *= -1;

		if (strn[i] >= '0' && strn[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (strn[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
