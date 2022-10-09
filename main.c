#include "monty.h"
globe var;
/**
 * main - entry point
 * @argc: count
 * @argv: variable
 * Return: int
 */
int main(int argc, char *argv[])
{
	init(&var);
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	return (process_file[argv[1]]);
}
/**
 * init - entry point
 * @v: initiates variables
 * Return: int
 */
int init(globe *v)
{
	v->dict = instruc();
	if (v->dict == NULL)
		return (EXIT_FAILURE);
	v->head = NULL;
	v->line_number = 1;
	return (EXIT_SUCCESS);
}
