#include "monty.h"

/**
 * m_push - push an integer  to a stack
 * @stack: pointer to the doubly linked list
 * @line_num: number of lines
 */
void m_push(stack_t **stack, unsigned int line_num)
{
	int val;
	stack_t *top;

	if (arg == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer", line_num);
		exit(EXIT_FAILURE);
	}
	val = atoi(arg);

	top = malloc(sizeof(stack_t));
	if (top == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	top->n = val;
	top->prev = NULL;
	top->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = top;
	*stack = top;
}

/**
 * m_pall - print all
 * @stack: pointer to the doubly linked list
 * @line_num: number of lines
 */

void m_pall(stack_t **stack, __attribute__ ((unused))unsigned int line_num)
{
	stack_t *current;


	if (*stack == NULL)
		return;

	current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
