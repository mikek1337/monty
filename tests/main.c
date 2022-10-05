#include "../monty.h"
int main(void)
{
    stack_t *head = NULL;
    push(&head,1);
    push(&head,2);
    push(&head,3);
    pall(head);
    return (0);
}