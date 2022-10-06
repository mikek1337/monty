#include "monty.h"
/**
 * push - adds node to the front of the head
 * @stack: head of the list
 * @line_number:the data to be inputed
 * Return: new node
 */
void push(stack_t **stack, unsigned int line_number)
{
	 stack_t *temp = *stack;
	 stack_t *new = malloc(sizeof(stack));
	 char *num = strtok(NULL, " \r\t\n");
	if (num == NULL || (_isdigit(num) != 0 && num[0] != '-'))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	new->n = atoi(num);
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_all();
		exit(EXIT_FAILURE);
	}
	if (*stack == NULL)
	{
		*stack = new;
	}
	else
	{
		temp = *stack;
		new->next = *stack;
		temp->prev = new;
		*stack = new;
	}
}
/**
 * pall - pops all elements in a stack
 * @stack: head of the list
 * @line_number: numbers
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	(void) line_number;
	if (!tmp)
		return;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
/**
 * pint - Print last node
 * @stack: Double linked list
 * @line_number: File line execution
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

