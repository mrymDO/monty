#include "monty.h"

#define SIZE 254
/**
 * main - entry point
 * @argc: number of arguments
 * @argv: opcode file
 * Return: 0
 */
int main(int argc, char **argv)
{
	FILE *fd;
	char buffer[SIZE];
	char *op;
	unsigned int line_num = 1;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(buffer, sizeof(buffer), fd) != NULL)
	{
		op = arg_tok(&stack, buffer, line_num);
		if (op != NULL && op[0] != '#')
		{
			void (*func)(stack_t **stack, unsigned int line_num) =
				getInstructionFunc(op);

			if (func != NULL)
				func(&stack, line_num);
			else
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", line_num, op);
				fclose(fd);
				free_stack(stack);
				exit(EXIT_FAILURE);
			}
		}

		line_num++;
	}

		fclose(fd);
		free_stack(stack);
		return (0);
}

char *arg_tok(stack_t **stack, char *read_op, unsigned int line_num)
{
	char *opcode, *arg;

	(void)stack;

	opcode = strtok(read_op, " \t\n");
	if (opcode == NULL)
		return (NULL);

	if (strcmp(opcode, "push") == 0)
	{
		arg = strtok(NULL, " \t\n");
		if (arg != NULL)
			val_arg = arg_push(arg, line_num);
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_num);
			exit(EXIT_FAILURE);
		}
	}
	return (opcode);
}

int arg_push(char *arg, unsigned int line_num)
{
	unsigned int i;
	for (i = 0; i < strlen(arg); i++)
	{
		if (!isdigit(arg[i]))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_num);
			exit(EXIT_FAILURE);
		}
	}
	return atoi(arg);
}
/**
 * getInstructionFunc - select instruction to perform
 * @op: opcode entered
 * Return: pointer to the fucntion to be executed
 */
void (*getInstructionFunc(char *op))(stack_t **stack, unsigned int line_num)
{
        size_t i;
        instruction_t instructions[] = {
                {"push", m_push},
                {"pall", m_pall},
                {NULL, NULL}
        };
        for (i = 0; instructions[i].opcode != NULL; i++)
        {
                if (strcmp(instructions[i].opcode, op) == 0)
                        return (instructions[i].f);
        }
        return (NULL);
}

/**
 * free_stack - free the doubly linked list
 * @stack: pointer to the doubly linked list
 * Return: void
 *
 */
void free_stack(stack_t *stack)
{
	stack_t *current = stack;
	stack_t *temp;

	while (current != NULL)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
}
