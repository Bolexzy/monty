#include "monty.h"

void monty_push(stack_t **stack, unsigned int line_number);
void monty_pall(stack_t **stack, unsigned int line_number);


/**
 * monty_push - Pushes a value to a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The instruction line number of a Monty bytecodes file.
 */
void monty_push(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *new;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		malloc_error();
		return;
	}

	if (op_data < 0 || op_data > 9)
	{
		int_error(line_number);
		return;
	}
	new->n = op_data;
	if (check_mode(*stack) == STACK)
	{
		tmp = (*stack)->next;
		new->prev = (*stack);
		new->next = tmp;
		if (tmp)
			tmp->prev = new;
		(*stack)->next = new;
	}
	else
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		new->prev = tmp;
		new->next = NULL;
		tmp->next = new;
	}

}

/**
 * monty_pall - Prints the values of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The instruction line number of a Monty bytecodes file.
 */
void monty_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = (*stack)->next;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	(void)line_number;
}
