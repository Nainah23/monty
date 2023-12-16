#include "monty.h"
/**
 * free_tok - frees the op_toks string array
 */
void free_tok(void)
{
	size_t x = 0;

	if (op_toks == NULL)
		return;
	for (x = 0; op_toks[x]; x++)
		free(op_toks[x]);
	free(op_toks);
}
/**
 * monty_exec - main fn to run the script
 * @fd: fd for open Monty bytecode script
 * Return: EXIT_SUCCESS if pass
 */
int monty_exec(FILE *fd)
{
	stack_t *stack_ptr = NULL;
	size_t length = 0, exit_status = EXIT_SUCCESS;
	unsigned int line_number = 0, tok_len1 = 0;
	char *line = NULL;
	void (*op_func)(stack_t**, unsigned int);

	if (stack_initialize(&stack_ptr) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	while (getline(&line, &length, fd) != -1)
	{
		line_number++;
		op_toks = strTok(line, DELIMS);
		if (op_toks == NULL)
		{
			if (line_empty(line, DELIMS))
				continue;
			clear_stack(&stack_ptr);
			return (err_malloc);
		}
		else if (op_toks[0][0] == '#')
		{
			free_tok();
			continue;
		}
		op_func = func_op(op_toks[0]);
		if (op_func == NULL)
		{
			clear_stack(&stack_ptr);
			exit_status = error_op(op_toks[0], line_number);
			free_tok();
			break;
		}
		tok_len1 = tok_len();
		op_func(&stack_ptr, line_number);
		if (tok_len() != tok_len1)
		{
			if (op_toks && op_toks[tok_len1])
				exit_status = atoi(op_toks[tok_len1]);
			else
				exit_status = EXIT_FAILURE;
			free_tok();
			break;
		}
		free_tok();
	}
	clear_stack(&stack_ptr);

	if (line && *line == 0)
	{
		free(line);
		return (err_malloc());
	}
	free(line);
	return (exit_status)
}
/**
 * tok_len - gives the current op_toks len
 * Return: current op_toks len
 */
unsigned int tok_len(void)
{
	unsigned int len = 0;

	while (op_toks[le])
		len++;
	return (len);
}
/**
 * line_empty - looks for delims from a line read from getline
 * @line: line ptr
 * @delim: delimitor
 * Return: 1 success, 0 fail
 */
int line_empty(char *line, char *delim)
{
	int x, y;

	for (x = 0; line[x]; x++)
	{
		for (y = 0; delim[y]; y++)
		{
			if (line[x] == delim[y])
				break;
		}
		if (delim[y] == '\0')
			return (0);
	}
	return (1);
}
/**
 * func_op - match an opcode with a func
 * @opcode: opcode to match
 * Return: pointer to the matched func
 */
void (*func_op(char *opcode))(stack_t**, unsigned int)
{
	instruction_t op_funcs[] = {
		{"push", m_push},
		{"pall", m_pall},
		{"pint", m_pint},
		{"pop", m_pop},
		{"swap", m_swap},
		{"add", m_add},
		{"nop", m_nop},
		{"sub", m_sub},
		{"div", m_div},
		{"mul", m_mul},
		{"mod", m_mod},
		{"pchar", m_pchar},
		{"pstr", m_pstr},
		{"rot1", m_rot1},
		{"rot2", m_rot2},
		{"stack", m_stack},
		{"queue", m_queue},
		{NULL, NULL}
	};
	int x;

	for (x = 0; op_funcs[x].opcode; x++)
	{
		if (strcmp(opcode, op_funcs[x].opcode) == 0)
			return (op_funcs[x].f);
	}
	return (NULL);
}
