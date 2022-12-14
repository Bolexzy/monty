#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define STACK 0
#define QUEUE 1

extern int op_data;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* monty.c*/
int read_lines(FILE *file);
void (*handle_operation(char *opcode))(stack_t **stack, unsigned int line_number);

/* monty_ops1.c */
void monty_push(stack_t **stack, unsigned int line_number);
void monty_pall(stack_t **stack, unsigned int line_number);

/* stack.c */
int init_stack(stack_t **stack);
int check_mode(stack_t *stack);
void free_stack(stack_t **stack);

/* error_1.c */
int unknown_opcode(char *opcode, unsigned int line_number);
int int_error(unsigned int line_number);
int malloc_error(void);

#endif /* monty.h */
