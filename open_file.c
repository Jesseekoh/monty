#include "monty.h"


/**
 * open_file - open a file
 * @pathname: character pointer to the full pathname
 * or the actual file name
 */
void open_file(char *pathname)
{
	command_struct.file = fopen(pathname, "r");
	if (command_struct.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", pathname);
		exit(EXIT_FAILURE);
	}

	read_lines();

	fclose(command_struct.file);

	free_stack(command_struct.head);
}
