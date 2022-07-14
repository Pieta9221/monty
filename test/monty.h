#ifndef MONTY_H
#define MONTY_H

#define STDERR 2
#define DELIMS "\n \t\r"



#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <limits.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct glob_s - globally useful variables, all rolled into one
 * @top: double pointer to top of stack
 * @ops: double pointer to an instruction struct
**/
typedef struct globals
{
int num;
stack_t *stack;
char *line;
char *token;
char *opco;
FILE *file;
} globals_t;

extern globals_t global;




/* instructions.c */
void push(stack_t **stack, unsigned int line_cnt);
void pall(stack_t **stack, unsigned int line_cnt);
void pint(stack_t **stack, unsigned int line_cnt);
void swap(stack_t **stack, unsigned int line_cnt);
void pop(stack_t **stack, unsigned int line_cnt);

/* _strtol.c */
int _strtol(char *num_string, unsigned int line_number);

/* main.c */
void process_str(stack_t **stack, char *tok, unsigned int line_number);
int main(int argc, char *argv[]);

/* helper.c*/
void free_l(stack_t **stack);

#endif /* MONTY_H */
