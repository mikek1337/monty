#include "monty.h"
#include <stdio.h>
globe var;
int process_file(const char *filename)
{
	FILE *file;
	char *opcode;
	
	int i;
	size_t tmp;
	char *s;
	var.line_number = 1;
	var.head = NULL;
	tmp = 30;
	var.dict = instruc();
	s = malloc(sizeof(char)*tmp);
	file = fopen(filename,"r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n",filename);
		return (EXIT_FAILURE);   
	}
	while (!feof(file))
	{
		fgets(s, tmp, file);
		opcode = strtok(s, " \r\t\n");
		if (opcode != NULL)
		{
			for(i = 0; var.dict[i].opcode; i++)
			{
				
				if(strcmp(opcode, var.dict[i].opcode) == 0)
				{
					if(!var.dict[i].f)
					{
						return (EXIT_SUCCESS);
					}
					
					var.dict[i].f(&var.head, var.line_number);
					
				}
			}
			/* if (strlen(opcode) != 0 && opcode[0] != '#')
			{
				fprintf(stderr, "L%u: unknown instruction %s\n",
						var.line_number, opcode);
					return (EXIT_FAILURE);
			} */
			
		}
		var.line_number++;
		
	}
	return (EXIT_SUCCESS);

}

instruction_t *instruc()
{
	instruction_t *i = malloc(sizeof(instruction_t) * 2);

	if (!i)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (NULL);
	}
	i[0].opcode = "pall", i[0].f = pall;
	i[1].opcode = "push", i[1].f = push;
	

	return (i);
}

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

