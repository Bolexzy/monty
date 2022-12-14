#include "monty.h"

int unknown_opcode(char *opcode, unsigned int line_number);
int malloc_error(void);
int int_error(unsigned int line_number);

/**
 * unknown_opcode - Prints unknown instruction error message.
 * @opcode: Opcode instructuion where error occurred.
 * @line_number: Line number in Monty bytecodes file where error occured.
 *
 * Return: (EXIT_FAILURE) always.
 */
int unknown_opcode(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n",
		line_number, opcode);
	return (EXIT_FAILURE);
}

/**
 * malloc_error - Prints malloc error messages.
 *
 * Return: (EXIT_FAILURE) always.
 */
int malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}

/**
 * int_error - Prints invalid monty_push argument error messages.
 * @line_number: Line number in monty bytecode file where error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int int_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	exit(EXIT_FAILURE);
}
