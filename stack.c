#include "monty.h"
/**
 * push - adds node to the front of the head
 * @stack: head of the list
 * @line_number:the data to be inputed
 * Return: new node
 */
void push(stack_t **stack, unsigned int line_number)
{
	 stack_t *head = *stack;
	 stack_t *new_node = malloc(sizeof(stack));
	 char *num = strtok(NULL, " \r\t\n");
	if (num == NULL || (_isdigit(num) != 0 && num[0] != '-'))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new_node->n = atoi(num);
	new_node->next = NULL;
	new_node->prev = NULL;
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (head == NULL)
	{
		head = new_node;
	}
	else
	{
		printf("here");
		new_node->next = head;
		head->prev = new_node;
		*stack = new_node;
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

