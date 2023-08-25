#include "monty.h"

/**
 * swap - swaps the first two elements of stack
 * @stack: stack
 * @line_number: line number
*/
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	stack_t *tmp;

	(void)line_number;
	if (*stack != NULL && (*stack)->next != NULL)
	{
		current = *stack;
		tmp = current->next;
		current->next = tmp->next;
		if (current->next)
		{
			current->next->prev = current;
		}
		tmp->next = current;
		tmp->prev = NULL;

		*stack = tmp;
	}
	else
	{
		fclose(command_struct.file);
		free_stack(*stack);
		fprintf(stderr, "L%d: can't swap, stack too short\n",
				command_struct.line_number);
		exit(EXIT_FAILURE);
	}
}
