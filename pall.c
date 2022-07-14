#include <stdio.h>
#include "monty.h"

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
		printf("%d\n", str->n);
		str = str->next;
	}
	free(str);
}

