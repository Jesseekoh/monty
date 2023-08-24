#include "monty.h"

/**
 * process_cmd - process a command
 * @cmd: command
 * @line_no: number to add to stack
 */
void process_cmd(char *cmd, unsigned int line_no)
{
	int i = 0;
	char *av[2];
	void (*func)(stack_t **stack, unsigned int line_number);
	unsigned int value = 0;

	av[0] = strtok(cmd, " \t\r\n\v\f");

	if (av[0] == NULL){
		/* printf("is Null"); */
		return;
	}
	av[1] = strtok(NULL, " \t\r\n\v\f");


	func = cmd_identifier(av[0]);

	if (func == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_no, av[0]);
		exit(EXIT_FAILURE);
	}
	if (av[1])
	{
		while (av[1][i] != '\0')
		{
			if (av[1][i] > 57 || av[1][i] < 48)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_no);
				exit(EXIT_FAILURE);
			}
			i++;
		}
		
		value = (unsigned int)atoi(av[1]);
	}

	/*  Run the command */
	func(&head, value);

}
