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
	else if (((*stack)->n < 65 || (*stack)->n > 90) &&
	((*stack)->n < 97 || (*stack)->n > 122))
	{
		fclose(command_struct.file);
		free_stack(*stack);
		fprintf(stderr, "L%d: can't pchar, value out of range\n",
		command_struct.line_number);
		exit(EXIT_FAILURE);
	}

	fprintf(stdout, "%c\n", (*stack)->n);
}
