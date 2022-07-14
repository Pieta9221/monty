#include "monty.h"

glob_t glob;

/**
 * stack_init - initialize all the things
 * @head: top of stack data structure
 **/
void stack_init(stack_t **head)
{
	*head = NULL;
	glob.top = head;
}

/**
 * process_str - it process the input file
 * @stack:  the head of the stack
 * @tok: the commmand from the file input
 * @line_number: the line number from the file
 * Return: Nothing
 */
void process_str(stack_t **stack, char *tok, unsigned int line_number)
{
	instruction_t instructions[] = {
		{"pall", pall},
		{"push", push},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{NULL, NULL}
	};

	int i;

	for (i = 0; instructions[i].opcode; i++)
	{
		if (strcmp(instructions[i].opcode, tok) == 0)
		{
			instructions[i].f(stack, line_number);
			return;
		}
	}
	if (tok != NULL)
	{
		fprintf(stderr, "L%i: unknown instruction %s\n", line_number, tok);
		exit(EXIT_FAILURE);
	}
}



/**
 * main - contains the main function
 * @argc: the number of input from the commmand line
 * @argv: the word pass to the program
 * Return: 0
 */
int main(int argc, char *argv[])
{
	FILE *fp;
	char *tok, *line = NULL;
	size_t len = 0;
	ssize_t read = 0;
	int line_number = 1;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, fp)) != -1)
	{
		tok = strtok(line, DELIMS);
		process_str(&stack, tok, line_number);
		line_number++;
	}
	free(line);
	fclose(fp);
	return (0);
}
