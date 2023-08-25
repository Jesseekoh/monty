#include "monty.h"

/**
 * rotl - rotates the stack to the top.
 * @stack: pointer to the first node in the stack
 * @line_number: command argument
 * Description: The top element of the stack becomes the last one,
 * and the second top element of the stack becomes the first one
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *current;

	(void) line_number;
	if (!(*stack) || !(*stack)->next)
		return;

	tmp = *stack;

	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	current = *stack;

	while (current->next)
		current = current->next;

	current->next = tmp;
	tmp->prev = current;
	tmp->next = NULL;
}
