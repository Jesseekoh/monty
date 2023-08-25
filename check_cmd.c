#include "monty.h"

/**
 * check_cmd - check if cmd is not pall, pop, pint
 * @cmd: command
 * Return: 1 on success or 0 on failure
*/
int check_cmd(char *cmd)
{
	if ((strcmp("pall", cmd) != 0) && (strcmp("pint", cmd) != 0) &&
	(strcmp("pop", cmd) != 0) && (strcmp("swap", cmd) != 0))
		return (1);

	return (0);
}
