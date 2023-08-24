#include "monty.h"

/**
 * read_lines - read line from a file
 * @file_ptr: file pointer
 */
void read_lines(FILE *file_ptr)
{
	unsigned int line = 1;
	char buffer[1024];

	while (fgets(buffer, 1024, file_ptr) != NULL)
	{
		buffer[strlen(buffer)] = '\0';

		/* printf("%s\n", buffer); */
		process_cmd(buffer, line, file_ptr);
		line++;
	}
}
