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
/**
 * m_pint - print top value of the stack
 * @stack: pointer to the doubly linked list
 * @line_num: number of line
 * Return: void
 */
void m_pint(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	temp = *stack;

	printf("%d\n", temp->n);
}
/**
 * m_pop - remove the top element from the stack
 * @stack: pointer to the doubly linked list
 * @line_num: number of line
 * Return: void
 */
void m_pop(stack_t **stack, unsigned int line_num)
{
	stack_t *pop_node;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}
	pop_node = *stack;
	*stack = pop_node->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(pop_node);
}
/**
 * m_swap - swap positions of the top two elements on the stack
 * @stack: pointer to the doubly linked list
 * @line_num: number of line
 * Return: void
 */
void m_swap(stack_t **stack, unsigned int line_num)
{
	stack_t *current, *after;
	int len = 0;
	int temp = 0;

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
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	current = *stack;
	after = (*stack)->next;

	temp = current->n;
	current->n = after->n;
	after->n = temp;
}


