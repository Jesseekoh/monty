#include "monty.h"

/**
 * enqueue - push element to the queue
 * @queue: first node in the queue
 * @line_number: element to add to the queue
 */
void enqueue(stack_t **queue, unsigned int line_number)
{
	stack_t *new_node, *current;	
		
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		free_stack(command_struct.head);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->next = NULL;
	new_node->n = (int)line_number;

	current = *queue;
	if (!(*queue))
	{
		*queue = new_node;
	}
	else
	{
		while (current->next)
			current = current->next;
	}

	if (current)
		current->next = new_node;

	new_node->prev = current;
}
