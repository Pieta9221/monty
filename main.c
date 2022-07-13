#include "monty.h"
#include <stdio.h>

stack_t *stack = NULL;

/**
 * push - it push an element to the stack
 * @stack: the head of the stack
 * @line_number: the number of line
 * Return: Nothing
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *newnode = (stack_t *)malloc(sizeof(stack_t));
	int num;
	char *tok;

	tok = strtok(NULL, DELIMS);
	if (tok == NULL || stack == NULL)
	{
		fprintf(stderr, "L%i: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	num = atoi(tok);

	if (newnode == NULL)
	{
		write(STDERR, "Error: malloc failed\n", 21);
		exit(EXIT_FAILURE);
	}
		
	newnode->n = num;
	newnode->prev = NULL;
	newnode->next = *stack;
	if (*stack != NULL)
	{
		(*stack)->prev = newnode;
	}
	*stack = newnode;

}

/**
 * pall - it print the value in a stack
 * @stack: the head of the stack 
 * @line_number: unuse varaible
 * Return: Nothing
 */
void pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *str = *stack;
	while (str != NULL)
	{
		printf("%i\n", str->n);
		str = str->next;
	}
	free(str);
}

/**
 * stack - the head of the stack
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
 * pint - it print the value at the top of the stack
 * @stack: the head of the stack
 * @line_number: the line from the file
 * Return: Nothing
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack != NULL)
		printf("%i\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%i: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}	
}


void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	if (*stack == NULL)
	{
		fprintf(stderr, "L%i: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack) = (*stack)->next;
	free(temp);
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
	

	if (argc != 2)
	{
		write(STDERR, "USAGE: monty file\n", 18);
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, fp))!= - 1)
	{
		tok = strtok(line, DELIMS);
		process_str(&stack, tok, line_number);
		line_number++;
	}
	
	return (0);
}