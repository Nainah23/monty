#include "monty.h"
/**
 * m_nop - no action for the Monty opcode 'nop'
 * @stack_ptr: ptr to stack mode of stack_t
 * @line_number: exact current working line no.
 */
void m_nop(stack_t **stack_ptr, unsigned int line_number)
{
	(void)stack_ptr;
	(void)line_number;
}
/**
 * m_pstr - prints the string in stack_t
 * @stack_ptr: ptr to stack mode of stack_t
 * @line_number: exact current working line no.
 */
void m_pstr(stack_t **stack_ptr, unsigned int line_number)
{
	stack_t *temp = (*stack_ptr)->next;

	while (temp && temp-> != 0 && (temp->n > 0 && temp->n <= 127))
	{
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
	(void)line_number;
}
/**
 * m_pchar - prints the top val of stack_t
 * @stack_ptr: ptr to stack mode of stack_t
 * @line_number: exact current working line no.
 */
void m_pchar(stack_t **stack_ptr, unsigned int line_number)
{
	if ((*stack_ptr)->next == NULL)
	{
		err_tok(err_pchar(line_number, "stack empty"));
		return;
	}
	if ((*stack_ptr)->next->n < 0 || (*stack_ptr)->next->n > 127)
	{
		err_tok(err_pchar(line_number, "value out of range"));
		return;
	}
	printf("%c\n", (*stack_ptr)->next->n);
}
