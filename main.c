#include "monty.h"

/**
 * main - Entry point (execution start from here)
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 (Sucess)
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}


	open_file(argv[1]);

	return (EXIT_SUCCESS);
}

stack_t *head = NULL;
