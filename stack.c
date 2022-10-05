#include "monty.h"
/**
 * addhead - adds node to the front of the head
 * 
 * @head: head of the list
 * @n:the data to be inputed
 * Returns: stack_t* 
 */
stack_t *push(stack_t **head, int n)
{
	 stack_t *new;
	 stack_t *temp;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		return (NULL);
	}
	new->n = n;
	if (*head == NULL)
	{
		*head = new;
	}
	else
	{
		temp = *head;
		new->next = *head;
		temp->prev = new;
		*head = new;
	}
	return (new);

}

int pall(stack_t *head)
{
	int count = 0;
	 const stack_t *temp = head;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
		count++;
	}
	return (count);

	return (1);
}

