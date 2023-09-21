#include "shell.h"

/**
 **_strncpy - a function to copy a string 
 *@dest: the first string to be copied to
 *@src: the second string to be copied
 *@am: the amount of characters to be copied
 *Return: the concatenated string
 */
 
 
char *_strncpy(char *dest, char *src, int am)
{
	int i, j;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < am - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < am)
	{
		j = i;
		while (j < am)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 **_strncat - concatenates two strings
 *@dest: the first string
 *@src: the second string
 *@am: the amount of bytes to be maximally used
 *Return: the concatenated string
 */
 
 
char *_strncat(char *dest, char *src, int am)
{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < am)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < am)
		dest[i] = '\0';
	return (s);
}

/**
 **_strchr - locates a character in a string
 *@s: the string to be parsed
 *@c: the character to look for
 *Return: (s) a pointer to the memory area s
 */
 
 
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
