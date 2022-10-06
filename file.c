#include "monty.h"
#include <stdio.h>
/**
 * process_file - start point for the process
 * @filename: file name
 * Return: int
 */
int process_file(const char *filename)
{
	 FILE *file;
	 char *opcode;
	 size_t tmp;
	 char *s;
	tmp = 30;
	s = malloc(sizeof(char) * tmp);
	file = fopen(filename, "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		return (EXIT_FAILURE);
	}
	while (!feof(file))
	{
		fgets(s, tmp, file);
		opcode = strtok(s, " \r\t\n");
		if (opcode != NULL)
		{
			if (call_funct(&var, opcode) == EXIT_FAILURE)
			{
				free_all();
				return (EXIT_FAILURE);
			}
		}
		var.line_number++;
	}
	free_all();
	return (EXIT_SUCCESS);

}

/**
 * instruc - instruction
 * Return: instruction_t*
 */
instruction_t *instruc()
{
	instruction_t *i = malloc(sizeof(instruction_t) * 4);

	if (!i)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (NULL);
	}
	i[0].opcode = "push", i[0].f = push;
	i[1].opcode = "pall", i[1].f = pall;
	i[2].opcode = "pint", i[2].f = pint;
	i[3].opcode = "pop", i[3].f = pop;
	return (i);
}

/**
 * _isdigit - determine wether it is a digit
 * @string: string
 * Return: int
 */
int _isdigit(char *string)
{
	int i;

	for (i = 0; string[i]; i++)
	{
		if (string[i] < 48 || string[i] > 57)
			return (1);
	}
	return (0);
}
/**
 * free_all - frees all elements
 */
void free_all(void)
{
	free(var.dict);
	if (var.head != NULL)
	{
		while (var.head->next != NULL)
		{
			var.head = var.head->next;
			free(var.head->prev);
		}
		free(var.head);
	}
}
/**
 * call_funct - calling functions
 * @var: global variable
 * @opcode: optcode for all
 * Return: int
 */
int call_funct(globe *var, char *opcode)
{
	int i;

	for (i = 0; var->dict[i].opcode; i++)
		if (strcmp(opcode, var->dict[i].opcode) == 0)
		{
			if (!var->dict[i].f)
				return (EXIT_SUCCESS);
			var->dict[i].f(&var->head, var->line_number);
			return (EXIT_SUCCESS);
		}
	if (strlen(opcode) != 0 && opcode[0] != '#')
	{
		fprintf(stderr, "L%u: unknown instruction %s\n",
			var->line_number, opcode);
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}
