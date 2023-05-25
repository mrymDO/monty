#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

FILE *fd;
int val_arg;


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


void m_push(stack_t **stack, unsigned int line_number);
void m_pall(stack_t **stack, unsigned int line_number);
void m_pint(stack_t **stack, unsigned int line_num);
void m_pop(stack_t **stack, unsigned int line_num);
void m_swap(stack_t **stack, unsigned int line_num);
void m_add(stack_t **stack, unsigned int line_num);
void m_nop(stack_t **stack, unsigned int line_num);
void m_sub(stack_t **stack, unsigned int line_num);
void m_div(stack_t **stack, unsigned int line_num);
void m_mul(stack_t **stack, unsigned int line_num);
void m_mod(stack_t **stack, unsigned int line_num);
void m_pchar(stack_t **stack, unsigned int line_num);
void m_pstr(stack_t **stack, unsigned int line_num);
void (*getInstructionFunc(char *op))(stack_t **stack, unsigned int line_num);
void free_stack(stack_t *stack);
int arg_push(char *arg, unsigned int line_num);
char *arg_tok(char *read_op, unsigned int line_num);
int isascii(int c);

#endif
