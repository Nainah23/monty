#include "monty.h"
/**
 * err_usage - It prints the error usage message
 * Return: [EXIT_FAILURE]
 */
int err_usage(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}
/**
 * err_malloc - It prints the error malloc message
 * Return: [EXIT_FAILURE]
 */
int err_malloc(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}
/**
 * err_fileOpen - Will print the file name with
 * its file opening err message
 * @file: the file that's failed to open
 * Return: [EXIT_FAILURE]
 */
int err_fileOpen(char *file)
{
	fprintf(stderr, "Error: Can't open file %s\n", file);
	return (EXIT_FAILURE);
}
/**
 * err_op - will print the err message for the instruction
 * unknown
 * @opcode: Opcode of the error
 * @line: the exact line where the error occurred in
 * Monty bytecodes
 * Return: [EXIT_FAILURE]
 */
int err_op(char *opcode, unsigned int line)
{
	fprintf(stderr, "L%u: unknown instrunction %s\n", line, opcode);
	return (EXIT_FAILURE);
}
/**
 * err_arg - Will print the error message for the
 * monty_push argument that's invalid
 * @line: the exact line where the error occurred in
 * Monty bytecodes
 * Return: [EXIT_FAILURE]
 */
int err_arg(unsigned int line)
{
	fprintf(stderr, "L%u: usage: push integer\n", line);
	return (EXIT_FAILURE);
}
