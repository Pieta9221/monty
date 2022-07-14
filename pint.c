#include <stdio.h>
#include "monty.h"

/**
 * pint - it print the value at the top of the stack
 * @stack: the head of the stack
 * @line_number: the line from the file
 * Return: Nothing
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
