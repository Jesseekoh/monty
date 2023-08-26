#include "monty.h"

/**
 * p_queue - print element in a queue
 * @queue: pointer to the last element in a queue
 */
void p_queue(stack_t **queue)
{
	stack_t *current;

	if (!(*queue))
		return;

	current = *queue;
	while (current->next)
		current = current->next;

	while (current)
	{
		fprintf(stdout, "%d\n", current->n);
		current = current->prev;
	}
}
