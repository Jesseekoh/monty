#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;



/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef struct mont_st
{
	stack_t *head;
	FILE *file;
	unsigned int line_number;
	bool is_stack;
} mon_t;

extern mon_t command_struct;


void pchar(stack_t **stack, unsigned int line_number);
int switch_mode(char *cmd);
void p_queue(stack_t **queue);
void add_queue(stack_t **queue);
void enqueue(stack_t **queue, unsigned int line_number);
int ascii_range(int element);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
void read_lines(void);
int is_comment(char *cmd);
void (*cmd_identifier(char *opcode))(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void process_cmd(char *cmd, unsigned int line_no);
unsigned int argument_check(char *av[], unsigned int line_no);
void pall(stack_t **stack, unsigned int line_number);
void dequeue(stack_t **queue);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void m_div(stack_t **stack, unsigned int line_number);
void m_mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void free_stack(stack_t *stack);
int _strcmp(char *str1, char *str2);
void open_file(char *pathname);
int check_cmd(char *cmd);
#endif
