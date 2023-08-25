#include "monty.h"

/**
 * add - add first two elements of a stack
 * @stack: stack
 * @line_number: line number
*/
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int sum = 0;

	(void) line_number;
	if (*stack && (*stack)->next)
	{
		tmp = *stack;
		sum = tmp->n + (*stack)->next->n;

		*stack = (*stack)->next;
		(*stack)->n = sum;
		(*stack)->prev = NULL;

		free(tmp);
	}
	else
	{
		fclose(command_struct.file);
		fprintf(stderr, "L%d: can't add, stack too short\n",
		command_struct.line_number);
	}

}
