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
