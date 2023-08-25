#include "monty.h"

/**
 * cmd_identifier - command identifier
 * @opcode: command to check for.
 * Return: function else NULL
 */
void (*cmd_identifier(char *opcode))(stack_t **stack, unsigned int line_number)
{
	int i;
	instruction_t array[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};

	if (!opcode)
		return (NULL);

	i = 0;
	while (array[i].opcode)
	{
		if (strcmp(opcode, array[i].opcode) == 0)
			return (array[i].f);

		i++;
	}

	return (NULL);
}
