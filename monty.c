#include "monty.h"

int op_data = 0;

/**
 * read_lines - Reads and executes monty bytecodes script.
 * @file: File pointer to an open Monty bytecodes script.
 *
 * Return: EXIT_SUCCESS on success, respective error code on failure.
 */
int read_lines(FILE *file)
{
	stack_t *stack = NULL;
	char opcode[5];
	int exit_status = EXIT_SUCCESS;
	unsigned int line_number = 0;
	void (*op_func)(stack_t**, unsigned int);

	if (init_stack(&stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	while (fscanf(file, "%s%d", opcode, &op_data) >= 1)
	{
		line_number++;
		op_func = handle_operation(opcode);
		if (op_func == NULL)
		{
			free_stack(&stack);
			exit_status = unknown_opcode(opcode, line_number);
			break;
		}
		if (op_data == 0)
		{
			free_stack(&stack);
			int_error(line_number);
		}
		op_func(&stack, line_number);
	}
	free_stack(&stack);
	fclose(file);

	return (exit_status);
}


/**
 * main - the entry point for Monty Interp
 *
 * @argc: the count of arguments passed to the program
 * @argv: Argument vector.
 *
 * Return: (EXIT_SUCCESS) on success (EXIT_FAILURE) on error
 */
int main(int argc, char *argv[])
{
	FILE *file = NULL;
	int exit_status = EXIT_SUCCESS;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	exit_status = read_lines(file);
	return (exit_status);
}
