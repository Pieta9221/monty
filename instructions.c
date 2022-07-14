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

/**
 * swap - Removes the top element of the stack
 * @stack: the head of the stack
 * @line_number: the line of the file
 * Return: NOthing
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next;
	(*stack)->prev = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	if (tmp->next)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack) = (*stack)->prev;
}
