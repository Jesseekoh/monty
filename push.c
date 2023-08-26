#include "monty.h"

/**
 * push - push element to the stack
 * @stack: first node in the stack
 * @line_number: number to add to the stack
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	if (!command_struct.is_stack)
	{
		/* add to queue */
		enqueue(stack, line_number);
		return;
	}
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		free_stack(command_struct.head);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->next = *stack;
	new_node->n = (int)line_number;
	new_node->prev = NULL;


	*stack = new_node;

	if ((*stack)->next)
		(*stack)->next->prev = *stack;

}
