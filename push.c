#include <stdio.h>
#include "monty.h"

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

	if (newnode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	tok = strtok(NULL, DELIMS);
	if (tok == NULL || stack == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	num = atoi(tok);

	newnode->n = num;
	newnode->prev = NULL;
	newnode->next = *stack;
	if (*stack != NULL)
	{
		(*stack)->prev = newnode;
	}
	*stack = newnode;

}
