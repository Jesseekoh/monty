#include "monty.h"

/**
 * pint - prints the int at the top of stack
 * @stack: stack
 * @line_number: line number
*/
void pint(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	if (*stack == NULL)
	{
		fclose(command_struct.file);
		fprintf(stderr, "L%d: can't pint, stack empty\n",
command_struct.line_number);
		exit(EXIT_FAILURE);
	}
		fprintf(stdout, "%d\n", (*stack)->n);

}
