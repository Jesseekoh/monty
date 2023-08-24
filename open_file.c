#include "monty.h"

/**
 * open_file - open a file
 * @pathname: character pointer to the full pathname
 * or the actual file name
 */
void open_file(char *pathname)
{
	FILE *fd;

	fd = fopen(pathname, "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", pathname);
		exit(EXIT_FAILURE);
	}

	read_lines(fd);

	fclose(fd);
}
