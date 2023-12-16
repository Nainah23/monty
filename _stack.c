#include "monty.h"
/**
 * clear_stack - frees stack_t
 * @stack_ptr: a stack_t pointer to it top/bottom
 */
void clear_stack(stack_t **stack_ptr)
{
	stack_t *temp = *stack_ptr;

	while (*stack_ptr)
	{
		temp = (*stack_ptr)->next;
		free(*stack_ptr);
		*stack_ptr = temp;
	}
}
/**
 * stack_initialize - initialize stack_t with top stack and
 * bottom nodes
 * @stack_ptr: an uninitialized stack_t ptr
 * Return: EXIT_FAILURE if fail
 * otherwise - EXIT_SUCCESS
 */
int stack_initialize(stack_t **stack_ptr)
{
	stack_t *x;

	x = malloc(sizeof(stack_t));
	if (x == NULL)
		return (err_malloc());
	x->n = STACK;
	x->prev = NULL;
	x->next = NULL;

	*stack_ptr = x;

	return (EXIT_SUCCESS);
}
/**
 * stack_check - Check the mode of stack_t. whether stack or queue
 * @stack_ptr:  a stack_t pointer to it top/bottom
 * Return: STACK (0) - if in stack mode
 * STACK (1) - if in queue mode
 * else - 2
 */
int stack_check(stack_t *stack_ptr)
{
	if (stack_ptr->n == STACK)
		return (STACK);
	else if (stack_ptr->n == QUEUE)
		return (QUEUE);
	return (2);
}
