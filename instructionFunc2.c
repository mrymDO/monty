#include "monty.h"

/**
 * m_mod - add two top element of the doubly linked  list int the stack
 * @stack: pointer to the doubly linked list
 * @line_num: number of lines
 * Return: void
 */

void m_mod(stack_t **stack, unsigned int line_num)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	if (((*stack)->n) == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		exit(EXIT_FAILURE);
	}
	current = *stack;
	after = (*stack)->next;
	res = (after->n % current->n);

	*stack = after;
	if (*stack != NULL)
		after->prev = NULL;
	after->n = res;
	free(current);
}

/**
 * m_pchar - prints the char at the top of the stack,
 * followed by a new line
 * @stack: pointer to the doubly linked list
 * @line_num: number of lines
 * Return: void
*/

void m_pchar(stack_t **stack, unsigned int line_num)
{
	stack_t *h;

	h = *stack;
	if (!h)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	if (h->n > 127 || h->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", h->n);
}
