#include "monty.h"
int main(int argc, char *argv[])
{
 
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        return (EXIT_FAILURE);
    }
    process_file(argv[1]);
   

    return (EXIT_SUCCESS);
}