#ifndef MONTY_H
#define MONTY_H

/*Header Files*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

/*Data Structure module #1*/
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO - ALX Project.
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/*Data structure module #2*/
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO - ALX Project.
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/**
 * enum stack_queue_mode - modee forr queue and stackk behaviorr.
 * @STACK: stack modee to pushh to top.
 * @QUEUE: queue modee to pushh to end.
 */
enum stack_queue_mode
{
	STACK,
	QUEUE
};

/**
 * struct allocated_s - containns memory to free; push valuee & stack modee.
 * @n: integer valuee for pushh opcode.
 * @token: tokenizedd opcode to free.
 * @mode: modee to formatt data to stack(1) or queue(0).
 * @pScript: file pointer rto Monty bytecode file.
 */
typedef struct allocated_s
{
	char *n;
	char *token;
	FILE *pScript;
	enum stack_queue_mode mode;
} allocated_t;

extern allocated_t mem;
void execute_script(void);
void stack_push(stack_t **stack, unsigned int line_number);
void stack_nop(stack_t **stack, unsigned int line_number);
void stack_pop(stack_t **stack, unsigned int line_number);
void stack_pint(stack_t **stack, unsigned int line_number);
void stack_swap(stack_t **stack, unsigned int line_number);
void stack_add(stack_t **stack, unsigned int line_number);
void stack_pall(stack_t **stack, unsigned int line_number);
void stack_sub(stack_t **stack, unsigned int line_number);
void stack_div(stack_t **stack, unsigned int line_number);
void stack_mul(stack_t **stack, unsigned int line_number);
void stack_rotl(stack_t **stack, unsigned int line_number);
void stack_mod(stack_t **stack, unsigned int line_number);
void stack_pchar(stack_t **stack, unsigned int line_number);
void stack_pstr(stack_t **stack, unsigned int line_number);
void stack_rotr(stack_t **stack, unsigned int line_number);
void op_stack(stack_t **stack, unsigned int line_number);
void free_all(stack_t *stack);
void op_queue(stack_t **stack, unsigned int line_number);
int isNum(char *str);

#endif
