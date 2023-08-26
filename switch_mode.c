#include "monty.h"

/**
 * switch_mode - switch between stack and queue
 * @cmd: the command to check for
 * Return: 1 (valid switch command) else 0
 */
int switch_mode(char *cmd)
{
	if (strcmp("queue", cmd) == 0)
	{
		command_struct.is_stack = false;
		return (1);
	}
	else if (strcmp("stack", cmd) == 0)
	{
		command_struct.is_stack = true;
		return (1);
	}
	else
	{
		return (0);
	}
}


