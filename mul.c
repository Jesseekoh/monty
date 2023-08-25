#include "monty.h"

/**
 * m_mul - add first two elements of a stack
 * @stack: stack
 * @line_number: line number
*/
void m_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int result = 0;

	(void) line_number;
	if (*stack && (*stack)->next)
	{
		tmp = *stack;
		result = tmp->n + (*stack)->next->n;

		*stack = (*stack)->next;
		(*stack)->n = result;
		(*stack)->prev = NULL;

		free(tmp);
	}
	else
	{
		fclose(command_struct.file);
		fprintf(stderr, "L%d: can't mul, stack too short\n",
		command_struct.line_number);
		exit(EXIT_FAILURE);
	}

}
