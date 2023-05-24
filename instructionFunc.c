#include "monty.h"

/**
 * m_push - push an integer  to a stack
 * @stack: pointer to the doubly linked list
 * @line_num: number of lines
 */
void m_push(stack_t **stack, unsigned int line_num)
{
	stack_t *new_node;

	(void)line_num;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = val_arg;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * m_pall - print all
 * @stack: pointer to the doubly linked list
 * @line_num: number of lines
 */

void m_pall(stack_t **stack, unsigned int line_num)
{
	stack_t *current;

	(void)line_num;


	if (*stack == NULL)
		return;

	current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
