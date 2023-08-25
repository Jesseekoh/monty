#include "monty.h"

/**
 * pchar - prints the char at the top of the stack, followed by a new line.
 * @stack: pointer to the first node in the stack
 * @line_number: the command argument (int)
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (!(*stack))
	{
		fclose(command_struct.file);
		fprintf(stderr, "L%d: can't pchar, stack empty\n",
		command_struct.line_number);
		exit(EXIT_FAILURE);
	}
	else if (ascii_range((*stack)->n))
	{
		fclose(command_struct.file);
		free_stack(*stack);
		fprintf(stderr, "L%d: can't pchar, value out of range\n",
		command_struct.line_number);
		exit(EXIT_FAILURE);
	}

	fprintf(stdout, "%c\n", (*stack)->n);
}

/**
 * ascii_range - check if a value is between a valid
 * valid character ascii table
 * @element: the value to check for
 * Return: 1 (True) 0 (False)
 */
int ascii_range(int element)
{
	if ((element < 65 || element > 90) &&
	(element < 97 || element > 122))
		return (1);

	return (0);
}
