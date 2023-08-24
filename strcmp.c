#include "monty.h"

/**
 * _strcmp - compares two strings
 * @str1: first string
 * @str2: second string
 * Return: if same, 0 else 1
 */
int _strcmp(char *str1, char *str2)
{
	int i = 0;

	if (!str1 || !str2)
		return (1);

	while (str1[i] == str2[i])
	{

		if ((str1[i] == '\0'))
			return (0);

		i++;
	}
	return (1);
}
