#include "monty.h"
/**
 * push - adds node to the front of the head
 * @stack: head of the list
 * @n:the data to be inputed
 * Return: new node
 */
void push(stack_t **stack, unsigned int line_number)
{
	 stack_t *new;
	 stack_t *temp;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("error");
	}
	new->n = line_number;
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
 */
void pall(stack_t **stack, unsigned int line_number)
{
	 
	 (void) line_number;
	 stack_t *temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
		
	}
}

