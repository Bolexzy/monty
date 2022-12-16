#include "monty.h"

void monty_mod(stack_t **stack, unsigned int line_number);

/**
 * monty_mod - Calculates the modulus of the second element from the
 *             top of a stack_t linked list  by the top element value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The isntruction line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second element node
 *              from the top and the top element is removed.
 */
void monty_mod(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		gv.errno = short_stack_error(line_number, "mod");
		return;
	}

	if ((*stack)->next->n == 0)
	{
		gv.errno = EXIT_FAILURE;
		fprintf(stderr, "L%u: division by zero\n", line_number);
		return;
	}

	(*stack)->next->next->n %= (*stack)->next->n;
	monty_pop(stack, line_number);
}
