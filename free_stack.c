#include "monty.h"

/**
 * free_stack - free the stack
 * @stack: pointer to the first node in the stack
 */
void free_stack(stack_t *stack)
{
	stack_t *current;


	while (stack)
	{
		current = stack;
		stack = stack->next;
		free(current);
	}
}
