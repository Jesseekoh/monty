#include "monty.h"

/**
 * is_comment - if a command is a comment
 * @cmd: The command to check for.
 * Return: 0 True else 1 False
 */
int is_comment(char *cmd)
{
	while (*cmd)
	{
		if (*cmd == 35)
			return (0);
		cmd++;
	}
	return (1);
}
