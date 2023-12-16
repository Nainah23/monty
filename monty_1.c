#include "monty.h"
/**
 * m_push - push sth to stack_t
 * @stack_ptr: pointer to stack mode of stack_t
 * @line_number: exact working line currently
 */
void m_push(stack_t **stack_ptr, unsigned int line_number)
{
	stack_t *temp, current;
	int x;

	current = malloc(sizeof(stack_t));
	if (current == NULL)
	{
		err_tok(err_malloc());
		return;
	}
	if (op_toks[1] == NULL)
	{
		err_tok(err_int(line_number));
		return;
	}
	for (x = 0; op_toks[1][x]; x++)
	{
		if (op_toks[1][x] == '-' && x == 0)
			continue;
		if (op_toks[1][x] < '0' || op_toks[1][x] > '9')
		{
			err_tok(err_int(line_number));
			return;
		}
	}
	current->n = atoi(op_toks[1]);
	if (stack_check(*stack_ptr) == STACK)
	{
		temp = (*stack_ptr)->next;
		current->prev = *stack_ptr;
		current->next = temp;
		if (temp)
			temp->prev = current;
		(*stack_ptr)->next = current;
	}
	else
	{
		temp = *stack_ptr;
		while (temp->next)
			temp = temp->next;
		current->prev = temp;
		current->next = NULL;
		temp->next = new;
	}
}
/**
 * m_swap - swaps 2 stack_t elements
 * @stack_ptr: ptr to stack mode of stack_t
 * @line_number: exact current working line no.
 */
void m_swap(stack_t **stack_ptr, unsigned int line_number)
{
	stack_t *temp;

	if ((*stack_ptr)->next == NULL || (*stack_ptr)->next->next == NULL)
	{
		err_tok(err_smallStack(line_number, "swap"));
		return;
	}
	temp = (*stack_ptr)->next->next;
	(*stack_ptr)->next->next = temp->next;
	(*stack_ptr)->next->prev = temp;
	if (temp->next)
		temp->next->prev = (*stack_ptr)->next;
	temp->next = (*stack_ptr)->next;
	temp->prev = *stack_ptr;
	(*stack_ptr)->next = temp;
}
/**
 * m_pall - prints stack_t values
 * @stack_ptr: ptr to stack mode of stack_t
 * @line_number: exact current working line no.
 */
void m_pall(stack_t **stack_ptr, unsigned int line_number)
{
	stack_t temp = (*stack_ptr)->next;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
	(void)line_number;
}
/**
 * m_pop - deletes the to stack_t element
 * @stack_ptr: ptr to stack mode of stack_t
 * @line_number: exact current working line no.
 */
void m_pop(stack_t **stack_ptr, unsigned int line_number)
{
	stack_t *next = NULL;

	if ((*stack_ptr)->next == NULL)
	{
		err_tok(err_pop(line_number));
		return;
	}
	next = (*stack_ptr)->next->next;
	free((*stack_ptr)->next);
	if (next)
		next->prev = *stack_ptr;
	(*stack_ptr)->next = next;
}
/**
 * m_pint - prints stack_t's top element
 * @stack_ptr: ptr to stack mode of stack_t
 * @line_number: exact current working line no.
 */
void m_pint(stack_t **stack_ptr, unsigned int line_number)
{
	if ((*stack_ptr)->next == NULL)
	{
		err_tok(err_pint(line_number));
		return;
	}
	printf("%d\n", (*stack_ptr)->next->n);
}
