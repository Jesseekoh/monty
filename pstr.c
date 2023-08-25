#include "monty.h"

/**
 * pstr - print a string from the stack
 * @stack: pointer to the first node in the stack
 * @line_number: command argument (int)
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	(void)line_number;
	if (!(*stack))
	{
		fprintf(stdout, "\n");
		return;
	}

	while (tmp)
	{
		if (ascii_range(tmp->n))
		{
			fprintf(stdout, "\n");
			return;
		}

		fprintf(stdout, "%c", tmp->n);
		tmp = tmp->next;
	}
	fprintf(stdout, "\n");
}
