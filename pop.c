#include "monty.h"

/**
 * pop - deletes the top element of stack
 * @stack: stack
 * @line_number: line number
*/
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;

	(void) line_number;
	if (*stack == NULL)
	{
		fclose(command_struct.file);
		fprintf(stderr, "L%d: can't pop an empty stack\n",
command_struct.line_number);
		exit(EXIT_FAILURE);
	}
	ptr = *stack;

	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(ptr);

}
