#include "monty.h"
/**
 * err_pop - Print the error pop message if stack is empty
 * @line_number: exact line where err happened
 * Return: (EXIT_FAILURE)
 */
int err_pop(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	return (EXIT_FAILURE);
}
/**
 * err_pchar - In case of epmty stacks or non-character values,
 * the pchar err message will be printed
 * @line_number: exact line where err happened
 * @err_msg: the error message to be printed
 * Return: (EXIT_FAILURE)
 */
int err_pchar(unsigned int line_number, char *err_msg)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_number, err_msg);
	return (EXIT_FAILURE);
}
/**
 * err_pint - In case of empty stack, the pint err message
 * will be printed
 * @line_number: exact line where err happened
 * Return: (EXIT_FAILURE)
 */
int err_pint(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	return (EXIT_FAILURE);
}
/**
 * err_div - if divided by 0, division err message will be printed
 * @line_number: exact line where err happened
 * Return: (EXIT_FAILURE)
 */
int err_div(unsigned int line_number)
{
	fprintf(stderr, "L%u: division by zero\n", line_number);
	return (EXIT_FAILURE);
}
/**
 * err_smallStack - if stack is shorter than 2 node,
 * monty math func err message will be printed
 * @err_op: error operation
 * @line_number: exact line where err happened
 * Return: (EXIT_FAILURE)
 */
int err_smallStack(unsigned int line_number, char *err_op)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, err_op);
	return (EXIT_FAILURE);
}
