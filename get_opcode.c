#include "monty.h"

/**
 * handle_operation - MAtchees an opcode with its corresponding function.
 * @opcode: The opcode to check.
 *
 * Return: A pointer to the coresponding function.
 */
void (*handle_operation(char *opcode))(stack_t **, unsigned int)
{
	int i;

	instruction_t op_funcs[] = {
		{"push", monty_push},
		{"pall", monty_pall},
		{NULL, NULL}
	};
	i = 0;

	while (op_funcs[i].opcode)
	{
		if (strcmp(opcode, op_funcs[i].opcode) == 0)
			return (op_funcs[i].f);
		i++;
	}
	return (NULL);
}