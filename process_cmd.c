#include "monty.h"

/**
 * argument_check - check the command command argument
 * @av: argument vector
 * @line_no: current command line numeber
 * Return: a valid argument
 */
unsigned int argument_check(char *av[], unsigned int line_no)
{
	unsigned int value = 0;
	int i;

	if (check_cmd(av[0]) != 0)
	{
		if (av[1] == NULL)
		{
			fclose(command_struct.file);
			free_stack(command_struct.head);
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
					fclose(command_struct.file);
					free_stack(command_struct.head);
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
 */
void process_cmd(char *cmd, unsigned int line_no)
{
	char *av[2];
	void (*func)(stack_t **stack, unsigned int line_number);
	unsigned int value;

	av[0] = strtok(cmd, " \t\r\n\v\f");

	if (av[0] == NULL)
		return;

	if (is_comment(av[0]) == 0)
		return;

	av[1] = strtok(NULL, " \t\r\n\v\f");


	func = cmd_identifier(av[0]);

	if (func == NULL)
	{
		fclose(command_struct.file);
		free_stack(command_struct.head);
		fprintf(stderr, "L%d: unknown instruction %s\n", line_no, av[0]);
		exit(EXIT_FAILURE);
	}
	value = argument_check(av, line_no);


	/*  Run the command */
	func(&command_struct.head, value);

}
