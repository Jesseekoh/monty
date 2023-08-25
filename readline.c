#include "monty.h"

/**
 * read_lines - read line from a file
 */
void read_lines(void)
{

	char buffer[1024];

	while (fgets(buffer, 1024, command_struct.file) != NULL)
	{
		buffer[strlen(buffer)] = '\0';

		/* printf("%s\n", buffer); */
		process_cmd(buffer, command_struct.line_number);
		command_struct.line_number++;
	}
}
