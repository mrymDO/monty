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
 * m_pchar - prints the char at the top of the stack, followed by a new line.
 * @stack: pointer to the doubly linked list
 * @line_num: number of lines
 * Return: void
 */

void m_pchar(stack_t **stack, unsigned int line_num)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	if (isascii((*stack)->n) == 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}

/**
 * m_pstr - prints the contents of a stack_t stack as a string
 * @stack: stack given by main
 * @line_num: line counter for error messages
 * Return: nothing
 */

void m_pstr(stack_t **stack, unsigned int line_num __attribute__((unused)))
{
	stack_t *current = *stack;

	while (current)
	{
		if (current->n <= 0 || current->n > 127)
			break;
		putchar((char) current->n);
		current = current->next;
	}
	putchar('\n');
}
