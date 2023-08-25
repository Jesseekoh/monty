#include "monty.h"

/**
 * check_cmd - check if cmd is not pall, pop, pint
 * @cmd: command
 * Return: 1 on success or 0 on failure
*/
int check_cmd(char *cmd)
{
	if ((strcmp("pall", cmd) != 0) && (strcmp("pint", cmd) != 0) &&
	(strcmp("pop", cmd) != 0) && (strcmp("swap", cmd) != 0) &&
	(strcmp("add", cmd) != 0) &&
	(strcmp("nop", cmd) != 0) &&
	(strcmp("sub", cmd) != 0) &&
	(strcmp("div", cmd) != 0) &&
	(strcmp("mul", cmd) != 0) &&
	(strcmp("mod", cmd) != 0) &&
	(strcmp("pchar", cmd) != 0))
		return (1);

	return (0);
}
