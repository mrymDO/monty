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
		op = strtok(buffer, " \t\n");
		arg = strtok(NULL, " \t\n");

		if (op != NULL && op[0] != '#')
		{
			void (*func)(stack_t **stack, unsigned int line_num) =
				getInstructionFunc(op);

			if (func != NULL)
				func(&stack, line_num);
			else
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", line_num, op);
				exit(EXIT_FAILURE);
			}
		}

		line_num++;
	}

		fclose(fd);
		return (0);
}

/**
 * getInstructionFunc - select instruction to perform
 * @op: opcode entered
 * Return: pointer to the fucntion to be executed
 */
void (*getInstructionFunc(char *op))(stack_t **stack, unsigned int line_num)
{
        int i;
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
