#include "main.h"

/**
 * main - Entry point of the program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 * Return: 0 on success, EXIT_FAILURE on failure
 */

int main(int argc, char *argv[])
{
	const char *filename = argv[1];
	FILE *file = fopen(filename, "r");
	stack_t *stack = NULL;
	char buffer[128];

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		return (EXIT_FAILURE);
	}

	if (!file)
	{
		fprintf(stderr, "Error: Unable to open file %s\n", filename);
		return (EXIT_FAILURE);
	}

	while (fgets(buffer, sizeof(buffer), file))
	{
		char *opcode = strtok(buffer, " \t\n$");

		if (opcode)
		{
			char *value_str = strtok(NULL, " \t\n$");
			int value = value_str ? atoi(value_str) : 0;

			check_op(&stack, opcode, value, 0);
		}
	}

	fclose(file);

	return (0);
}
