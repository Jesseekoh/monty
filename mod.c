#include "monty.h"

/**
 * m_mod - mod first two elements of a stack
 * @stack: stack
 * @line_number: line number
*/
void m_mod(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int result = 0;

	(void) line_number;
	if (*stack && (*stack)->next)
	{
		if ((*stack)->n == 0)
		{
			fprintf(stderr, "L%d: division by zero\n",
			command_struct.line_number);
			free_stack(*stack);
			fclose(command_struct.file);
			exit(EXIT_FAILURE);
		}
		tmp = *stack;
		result = (*stack)->next->n % tmp->n;

		*stack = (*stack)->next;
		(*stack)->n = result;
		(*stack)->prev = NULL;

		free(tmp);
	}
	else
	{
		fclose(command_struct.file);
		fprintf(stderr, "L%d: can't add, stack too short\n",
		command_struct.line_number);
		exit(EXIT_FAILURE);
	}

}
