#include "monty.h"
/**
 * m_rot1 - rotates the top stack_t value to bottom
 * @stack_ptr: ptr to stack mode of stack_t
 * @line_number: exact current working line no.
 */
void m_rot1(stack_t **stack_ptr, unsigned int line_number)
{
	stack_t *up, *down;

	if ((*stack_ptr)->next == NULL || (*stack_ptr)->next->next == NULL)
		return;
	up = (*stack_ptr)->next;
	down = (*stack_ptr)->next;
	while (down->next != NULL)
		down = down->next;
	up->next->prev = *stack_ptr;
	(*stack_ptr)->next = up->next;
	down->next = up;
	up->next = NULL;
	up->prev = down;

	(void)line_number;
}
/**
 * m_queue - convert stack to queue
 * @stack_ptr: ptr to stack mode of stack_t
 * @line_number: exact current working line no.
 */
void m_queue(stack_t **stack_ptr, unsigned int line_number)
{
	(*stack_ptr)->n = QUEUE;
	(void)line_number;
}
/**
 * m-rot2 - rotates the bottom stack_t value to top
 * @stack_ptr: ptr to stack mode of stack_t
 * @line_number: exact current working line no.
 */
void m_rot2(stack_t **stack_ptr, unsigned int line_number)
{
	stack_t *up, *down;

	stack_t *up, *down;

        if ((*stack_ptr)->next == NULL || (*stack_ptr)->next->next == NULL)
                return;
        up = (*stack_ptr)->next;
        down = (*stack_ptr)->next;
        while (down->next != NULL)
                down = down->next;
	down->prev->next = NULL;
	(*stack_ptr)->next = down;
	down->prev = *stack_ptr;
	down->next = up;
	up->prev = down;

	(void)line_number;
}
/**
 * m_stack - convert queue to stack
 * @stack_ptr: ptr to stack mode of stack_t
 * @line_number: exact current working line no.
 */
void m_stack(stack_t **stack_ptr, unsigned int line_number)
{
	(*stack_ptr)->n = STACK;
	(void)line_number;
}
