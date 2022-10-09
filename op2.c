#include "monty.h"
/**
 * add - adds top two
 * @stack: head
 * @line_number: number
 */
void add(stack_t **stack, unsigned int line_number)
{
	 int sum = 0;
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n",
				line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->n + (*stack)->next->n;
	(*stack)->next->n = sum;
	pop(stack, line_number);
}
/**
 * sub - adds top two
 * @stack: head
 * @line_number: number
 */
void sub(stack_t **stack, unsigned int line_number)
{
	 int sum = 0;
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n",
				line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->next->n - (*stack)->n;
	(*stack)->next->n = sum;
	pop(stack, line_number);
}
/**
 * div1 - adds top two
 * @stack: head
 * @line_number: number
 */
void div1(stack_t **stack, unsigned int line_number)
{
	if (!*stack || (*stack)->next)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n / (*stack)->n;
	pop(stack, line_number);
}
/**
 * mul - adds top two
 * @stack: head
 * @line_number: number
 */
void mul(stack_t **stack, unsigned int line_number)
{
	if (!*stack || (*stack)->next)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n * (*stack)->n;
	pop(stack, line_number);
}

/**
 * mod - calculate the module
 * @stack: top of the stack
 * @line_number: instruction line number
 */
void mod(stack_t **stack, unsigned int line_number)
{
	if (!*stack || (*stack)->next)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n % (*stack)->n;
	pop(stack, line_number);
}
