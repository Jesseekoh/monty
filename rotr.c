#include "monty.h"

/**
 * rotr -  rotates the stack to the bottom.
 * @stack: pointer to the first node in the stack
 * @line_number: the command argument
 * Description: The last element of the stack becomes the
 * top element of the stack
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *current, *last;

	(void) line_number;
	if (!(*stack) || !(*stack)->next)
		return;

	current = *stack;
	while (current->next)
	{
		last = current;
		current = current->next;
	}

	last->next = NULL;

	current->next = *stack;
	current->prev = NULL;
	(*stack)->prev = current;

	*stack = current;

}
