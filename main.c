#include "main.h"

int main(int argc, char *argv[])
{
	char line_buffer[MAX_LINE];

	printf("%d\n", argc);
	if (argc != 2)
	{
		dprintf(2, "USAGE: monty file");
		exit(EXIT_FAILURE);
	}

	FILE *fd = fopen(argv[1], "r");

	if (fd == NULL)
	{
		dprintf(2, "Error: Can't open file %s", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(line_buffer, MAX_LINE, fd))
	{
		/* code */
		printf("%s", line_buffer);
	}

	fclose(fd);
}
