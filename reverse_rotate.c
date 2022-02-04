#include "push_swap.h"

void	reverse_rotate(t_stack *stack, char *name, int mode)
{
	t_elem *first;
	t_elem *last;

	if (stack)
	{
	first = stack->head;
	last = ft_elemlast(first);
	first->prev = last;
	last->prev->next = NULL;
	last->next = first;
	last->prev = NULL;
	stack->head = last;
	if (mode)
		ft_putendl_fd(name, 1);
	}
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(stack_a, "", 0);
	reverse_rotate(stack_b, "rrr", 1);
}