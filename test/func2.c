#include "monty.h"

/**
 * check_op - Checks and performs the appropriate stack operation on opcode
 * @stack: Pointer to the stack
 * @opcode: Opcode to be executed
 * @value: Value associated with the opcode
 * @line_number: Line number for error handling
 */
void check_op(stack_t **stack, char *opcode, int value, int line_number)
{
	if (strcmp(opcode, "push") == 0)
	{
		push(stack, value);
	}
	else if (strcmp(opcode, "pall") == 0)
	{
		pall(stack, line_number);
	}
	else if (strcmp(opcode, "pint") == 0)
	{
		pint(stack, line_number);
	}
	else if (strcmp(opcode, "pop") == 0)
	{
		pop(stack, line_number);
	}
	else if (strcmp(opcode, "swap") == 0)
	{
		swap(stack, line_number);
	}
	else if (strcmp(opcode, "add") == 0)
	{
		add(stack, line_number);
	}
	else if (strcmp(opcode, "nop") == 0)
	{
		nop(stack, line_number);
	}
}


/**
 * swap - Swaps the top two elements of the stack
 * @stack: Pointer to the stack
 * @line_number: Line number for error handling
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	stack_t *next = top->next;
	stack_t *prev = top->prev;

	if (!stack || !top || !top->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}


	if (prev)
		prev->next = next;
	if (next)
		next->prev = prev;

	top->prev = next;
	top->next = next->next;

	next->next = top;
	next->prev = NULL;

	*stack = next;
}
/**
 * add - Adds the top two elements of the stack
 * @stack: Pointer to the stack
 * @line_number: Line number for error handling
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	*stack = top->next;

	if (!stack || !top || !top->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top->next->n += top->n;

	if (top->next)
	{
		top->next->prev = NULL;
	}

	free(top);
}
/**
 * nop - Does nothing
 * @stack: Pointer to the stack
 * @line_number: Line number for error handling
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
