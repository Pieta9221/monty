#include <stdio.h>
#include "monty.h"

/**
 * pop - Removes the top element of the stack
 * @stack: the head of the stack
 * @line_number: the line of the file
 * Return: NOthing
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack) = (*stack)->next;
	free(temp);
}
