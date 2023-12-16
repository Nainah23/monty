#include "monty.h"
/**
 * err_tok - prints error code to the op_toks last element
 * @err_msg: op_tok int to be stored as string
 */
void err_tok(int err_msg)
{
	int len = 0;
	int x = 0;
	char *string_ex = NULL;
	char **tok_1 = NULL;

	len = tok_len();
	tok_1 = malloc(sizeof(char *) * (len + 2));
	if (!op_toks)
	{
		err_malloc();
		return;
	}
	while (x < len)
	{
		tok_1[x] = op_toks[x];
		x++;
	}
	string_ex = int_get(err_msg);
	if (!string_ex)
	{
		free(tok_1);
		err_malloc();
		return;
	}
	tok_1[x++] = string_ex;
	tok_1[x] = NULL;
	free(op_toks);
	op_toks = tok_1;
}
