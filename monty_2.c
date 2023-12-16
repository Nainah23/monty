#include "monty.h"
/**
 * m_add - add the first(top) 2 stack_t values
 * @stack_ptr: ptr to stack mode of stack_t
 * @line_number: exact current working line no.
 */
void m_add(stack_t **stack_ptr, unsigned int line_number)
{
	if ((*stack_ptr)->next == NULL || (*stack_ptr)->next->next == NULL)
	{
		err_tok(err_smallStack(line_number, "add"));
		return;
	}
	(*stack_ptr)->next->next->n += (*stack_ptr)->next->n;
	m_pop(stack_ptr, line_number);
}
/**
 * m_mod - calculates the mod of the second top stack_t value
 * from the top value
 * @stack_ptr: ptr to stack mode of stack_t
 * @line_number: exact current working line no.
 */
void m_mod(stack_t **stack_ptr, unsigned int line_number)
{
	if ((*stack_ptr)->next == NULL || (*stack_ptr)->next->next == NULL)
	{
		err_tok(err_smallStack(line_number, "mod"));
		return;
	}
	if ((*stack_ptr)->next->n == 0)
	{
		err_tok(err_div(line_number));
		return;
	}
	(*stack_ptr)->next->next->n %= (*stack_ptr)->next->n;
	m_pop(stack_ptr, line_number);
}
/**
 * m_sub - subtracts the 2nd top stack_t value from the
 * top value
 * @stack_ptr: ptr to stack mode of stack_t
 * @line_number: exact current working line no.
 */
void m_sub(stack_t **stack_ptr, unsigned int line_number)
{
	if ((*stack_ptr)->next == NULL || (*stack_ptr)->next->next == NULL)
	{
		err_tok(err_smallStack(line_number, "sub"));
		return;
	}
	(*stack_ptr)->next->next->n -= (*stack_ptr)->next->n;
	m_pop(stack_ptr, line_number);
}
/**
 * m_mul -multiplies the 2nd top stack_t value by the
 * top value
 * @stack_ptr: ptr to stack mode of stack_t
 * @line_number: exact current working line no.
 */
void m_mul(stack_t **stack_ptr, unsigned int line_number)
{
	if ((*stack_ptr)->next == NULL || (*stack_ptr)->next->next == NULL)
        {
                err_tok(err_smallStack(line_number, "mul"));
                return;
        }
        (*stack_ptr)->next->next->n *= (*stack_ptr)->next->n;
        m_pop(stack_ptr, line_number);
}
/**
 * m_div - divides the 2nd top stack_t value by the
 * top value
 * @stack_ptr: ptr to stack mode of stack_t
 * @line_number: exact current working line no.
 */
void m_mul(stack_t **stack_ptr, unsigned int line_number)
{
        if ((*stack_ptr)->next == NULL || (*stack_ptr)->next->next == NULL)
        {
                err_tok(err_smallStack(line_number, "div"));
                return;
        }
	if ((*stack_ptr)->next->n == 0)
	{
		err_tok(err_div(line_number));
		return;
	}
        (*stack_ptr)->next->next->n /= (*stack_ptr)->next->n;
        m_pop(stack_ptr, line_number);
}
