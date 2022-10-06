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
	var.line_number = 1;
	var.head = NULL;
	var.dict = instruc();
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	process_file(argv[1]);
	return (EXIT_SUCCESS);
}
