#include "monty.h"

/**
 * argument_check - check the command command argument
 * @av: argument vector
 * @f_ptr: file pointer
 * @line_no: current command line numeber
 * Return: a valid argument
 */
unsigned int argument_check(char *av[], FILE *f_ptr, unsigned int line_no)
{
	unsigned int value = 0;
	int i;

	if (strcmp("pall", av[0]) != 0)
	{
		if (av[1] == NULL)
		{
			fclose(f_ptr);
			free_stack(head);
			fprintf(stderr, "L%d: usage: push integer\n", line_no);
			exit(EXIT_FAILURE);
		}
		i = 0;
		while (av[1][i] != '\0')
		{
			if (av[1][i] > 57 || av[1][i] < 48)
			{
				if (av[1][i] != '-')
				{
					fclose(f_ptr);
					free_stack(head);
					fprintf(stderr, "L%d: usage: push integer\n", line_no);
					exit(EXIT_FAILURE);
				}
			}
			i++;
		}
		value = (unsigned int)atoi(av[1]);
	}
	return (value);
}

/**
 * process_cmd - process a command
 * @cmd: command
 * @line_no: number to add to stack
 * @f_ptr: file pointer
 */
void process_cmd(char *cmd, unsigned int line_no, FILE *f_ptr)
{
	char *av[2];
	void (*func)(stack_t **stack, unsigned int line_number);
	unsigned int value;

	av[0] = strtok(cmd, " \t\r\n\v\f");

	if (av[0] == NULL)
	{
		/* printf("is Null"); */
		return;
	}
	av[1] = strtok(NULL, " \t\r\n\v\f");


	func = cmd_identifier(av[0]);

	if (func == NULL)
	{
		fclose(f_ptr);
		free_stack(head);
		fprintf(stderr, "L%d: unknown instruction %s\n", line_no, av[0]);
		exit(EXIT_FAILURE);
	}
	value = argument_check(av, f_ptr, line_no);


	/*  Run the command */
	func(&head, value);

}
