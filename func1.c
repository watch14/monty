#include "monty.h"

/**
 * push - Pushes a new element onto the stack
 * @stack: Pointer to the stack
 * @value: ..
 */
void push(stack_t **stack, int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
	{
		(*stack)->prev = new_node;
	}

	*stack = new_node;
}

/**
 * pall - Prints all values in the stack
 * @stack: Pointer to the stack
 * @line_number: Line number for error handling (not used)
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
	(void)line_number;
}

/**
 * pint - Prints the top value in the stack
 * @stack: Pointer to the stack
 * @line_number: Line number for error handling (not used)
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * pop - Removes the top element from the stack
 * @stack: Pointer to the stack
 * @line_number: Line number for error handling (not used)
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	*stack = top->next;

	if (top->next)
	{
		top->next->prev = NULL;
	}

	free(top);
}
