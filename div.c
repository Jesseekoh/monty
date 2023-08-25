#include "monty.h"

/**
 * m_div - add first two elements of a stack
 * @stack: stack
 * @line_number: line number
*/
void m_div(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int result = 0;

	(void) line_number;
	if (*stack && (*stack)->next)
	{
		if ((*stack)->n == 0)
		{
			fprintf(stderr, "L%d: division by zero",
			command_struct.line_number);
		}
		tmp = *stack;
		result = (*stack)->next->n / tmp->n;

		*stack = (*stack)->next;
		(*stack)->n = result;
		(*stack)->prev = NULL;

		free(tmp);
	}
	else
	{
		fclose(command_struct.file);
		fprintf(stderr, "L%d: can't div, stack too short\n",
		command_struct.line_number);
		exit(EXIT_FAILURE);
	}

}
