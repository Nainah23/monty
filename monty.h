#ifndef __MONTY_H__
#define __MONTY_H__


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define STACK 0
#define QUEUE 1
#define DELIMS " \n\t\a\b"

extern char **op_toks;

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

void free_stack(stack_t **stack_ptr);
int stack_initialize(stack_t **stack_ptr);
int stack_check(stack_t **stack_ptr);
void free_tok(void);
unsigned int tok_len(void);
int monty_exec(FILE *fd);
void err_tok(int error_code);

void m_push(stack_t **stack_ptr, unsigned int line_number);
void m_pall(stack_t **stack_ptr, unsigned int line_number);
void m_pint(stack_t **stack_ptr, unsigned int line_number);
void m_pop(stack_t **stack_ptr, unsigned int line_number);
void m_swap(stack_t **stack_ptr, unsigned int line_number);
void m_add(stack_t **stack_ptr, unsigned int line_number);
void m_nop(stack_t **stack_ptr, unsigned int line_number);
void m_sub(stack_t **stack_ptr, unsigned int line_number);
void m_div(stack_t **stack_ptr, unsigned int line_number);
void m_mul(stack_t **stack_ptr, unsigned int line_number);
void m_mod(stack_t **stack_ptr, unsigned int line_number);
void m_pchar(stack_t **stack_ptr, unsigned int line_number);
void m_pstr(stack_t **stack_ptr, unsigned int line_number);
void m_rot1(stack_t **stack_ptr, unsigned int line_number);
void m_rot2(stack_t **stack_ptr, unsigned int line_number);
void m_stack(stack_t **stack_ptr, unsigned int line_number);
void m_queue(stack_t **stack_ptr, unsigned int line_number);

char **strTok(char *str, char *delim);
char *int_get(int n);

int err_usage(void);
int err_malloc(void);
int err_fileOpen(char *file);
int err_op(char *opcode, unsigned int line_number);
int err_int(unsigned int line_number);
int err_pop(unsigned int line_number);
int err_pint(unsigned int line_number);
int err_smallStack(unsigned int line_number, char *err_op);
int err_div(unsigned int line_number);
int err_pchar(unsigned int line_number, char *err_msg);

#endif /*__MONTY_H__*/
