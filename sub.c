#include "monty.h"

/**
 * sub - add first two elements of a stack
 * @stack: stack
 * @line_number: line number
*/
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int difference = 0;

	(void) line_number;
	if (*stack && (*stack)->next)
	{
		tmp = *stack;
		difference = (*stack)->next->n - tmp->n;

		*stack = (*stack)->next;
		(*stack)->n = difference;
		(*stack)->prev = NULL;

		free(tmp);
	}
	else
	{
		fclose(command_struct.file);
		fprintf(stderr, "L%d: can't sub, stack too short\n",
		command_struct.line_number);
		exit(EXIT_FAILURE);
	}

}
