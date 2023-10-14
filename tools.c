#include "shell.h"

/**
 * _eputs - prints an input string
 * @string: the string to be printed
 *
 * Return: Nothing
 */


void _eputs(char *string)
{
	int i = 0;

	if (!string)
		return;
	while (string[i] != '\0')
	{
		_eputchar(string[i]);
		i++;
	}
}


/**
 * _putsfd - prints an input string
 * @string: the string to be printed
 * @fd: the filedescriptor to write to
 *
 * Return: the number of chars put
 */


int _putsfd(char *string, int fd)
{
	int i = 0;

	if (!string)
		return (0);
	while (*string)
	{
		i += _putfd(*string++, fd);
	}
	return (i);
}


/**
 * print_d - function prints a decimal (integer) number (base 10)
 * @input: the input
 * @fd: the filedescriptor to write to
 *
 * Return: number of characters printed
 */


int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int i, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{
			__putchar('0' + current / i);
			count++;
		}
		current %= i;
	}
	__putchar('0' + current);
	count++;

	return (count);
}



/**
 * remove_comments - function replaces first instance of '#' with '\0'
 * @buf: address of the string to modify
 *
 * Return: Always 0;
 */


void remove_comments(char *buf)
{
	int i;

	for (i = 0; buf[i] != '\0'; i++)
		if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
		{
			buf[i] = '\0';
			break;
		}
}

