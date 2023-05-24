#include "monty.h"
/**
 * m_add - add two top element of the doubly linked  list int the stack
 * @stack: pointer to the doubly linked list
 * @line_num: number of lines
 * Return: void
 */
void m_add(stack_t **stack, unsigned int line_num)
{
	stack_t *current, *after;
	int len = 0;
	int res = 0;

	if (*stack != NULL)
	{
		current = *stack;
		while (current != NULL)
		{
			len++;
			current = current->next;
		}
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	current = *stack;
	after = (*stack)->next;
	res = (current->n + after->n);

	*stack = after;
	if (*stack != NULL)
		after->prev = NULL;
	after->n = res;
	free(current);
}
/**
 * m_nop - function used a a placeholder instruction that doesn't anything
 * @stack: pointer to the doubly linked list
 * @line_num: number of line
 * Return: Void
 */
void m_nop(stack_t **stack, unsigned int line_num)
{
	(void)stack;
	(void)line_num;
}