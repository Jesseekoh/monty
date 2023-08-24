#include "monty.h"

/**
 * process_cmd - process a command
 * @cmd: command
 * @line_no: number to add to stack
 */
void process_cmd(char *cmd, unsigned int line_no)
{
	char *av[2];
	void (*func)(stack_t **stack, unsigned int line_number);
	unsigned int value = 0;

	av[0] = strtok(cmd, " ");
	av[1] = strtok(NULL, " ");


	func = cmd_identifier(av[0]);

	if (func == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_no, av[0]);
		exit(EXIT_FAILURE);
	}
	if (av[1])
		value = (unsigned int)atoi(av[1]);

	/*  Run the command */
	func(&head, value);

}
