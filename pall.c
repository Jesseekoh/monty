#include "monty.h"

/**
 * pall - print all element from the stack
 * in a FILO.
 * @stack: the stack
 * @line_number: The line number
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	while (current)
	{
		fprintf(stdout, "%d\n", current->n);
		current = current->next;
	}
}
