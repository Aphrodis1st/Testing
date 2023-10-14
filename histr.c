#include "shell.h"

/**
 * displayHistory - displays the history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
 
 
int displayHistory(info_t *info)
{
	printList(info->history);
	return (0);
}

/**
 * unset_alias - sets alias to string
 * @info: parameter struct
 * @string: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
 
 
int unset_alias(info_t *info, char *string)
{
	char *q, c;
	int ret;

	q = _strchr(string, '=');
	if (!q)
		return (1);
	c = *q;
	*q = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, string, -1)));
	*q = c;
	return (ret);
}

/**
 * set_alias - sets alias to string
 * @info: parameter struct
 * @string: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
 
 
int set_alias(info_t *info, char *string)
{
	char *q;

	q = _strchr(string, '=');
	if (!q)
		return (1);
	if (!*++q)
		return (unset_alias(info, string));

	unset_alias(info, string);
	return (add_node_end(&(info->alias), string, 0) == NULL);
}

/**
 * print_alias - prints an alias string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
 
 
int print_alias(list_t *node)
{
	char *q = NULL, *a = NULL;

	if (node)
	{
		q = _strchr(node->string, '=');
		for (a = node->string; a <= q; a++)
		_putchar(*a);
		_putchar('\'');
		_puts(q + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - mimics the alias builtin (man alias)
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
 
 
int _myalias(info_t *info)
{
	int i = 0;
	char *q = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		q = _strchr(info->argv[i], '=');
		if (q)
			set_alias(info, info->argv[i]);
		else
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}