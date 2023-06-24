#include "monty.h"

/*********************************************************
 * Project: ALX C - Stacks, Queues - LIFO, FIFO
 *
 *
 * Team/Group/Individual Collaboration Project

 *
 *
 * Date: 19/06/2023
 *
 *
 * Author: Samuel Atiemo
 *
 *
 *
 **********************************************************/

allocated_t mem;

/**
 * main - Main entry
 * Description: Monty bytecodes files interpreter
 * @argc: total of arguments
 * @argv: The arguments, monty files
 * Return: int
 */
int main(int argc, char const *argv[])
{
	/* Checks if file arguments is less than or more than 2*/
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	/* set defaults format mode to stack */
	mem.mode = STACK;

	/* Attempts to open the file */
	mem.pScript = fopen(argv[1], "r");
	if (mem.pScript == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	/* Executes the monty bytecode script */
	execute_script();
	return (0);
}
