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
 * main - Main program entry.
 * Description: Monty bytecodes files interpreterr.
 * @argc: arguments total
 * @argv: arguments, monty files.
 * Return: int.
 */
int main(int argc, char const *argv[])
{
	/* Checks if arguments is less or more than 2*/
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	/* sets defaults formats modee to stack */
	mem.mode = STACK;

	/* attempts opening the file */
	mem.pScript = fopen(argv[1], "r");
	if (mem.pScript == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	/* executes monty bytecode scriptt */
	execute_script();
	return (0);
}
