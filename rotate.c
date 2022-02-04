#include "push_swap.h"

void	rotate(t_stack *stack, char *name, int mode)
{
	t_elem	*first;
	t_elem	*last;

	if (stack)
	{
		first = stack->head;
		last = ft_elemlast(first);
		last->next = first;
		stack->head = first->next;
		first->next = NULL;
		first->prev = last;
		stack->head->prev = NULL;
		if (mode)
			ft_putendl_fd(name, 1);
	}
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b && stack_a)
	{
		rotate(stack_a, "", 0);
		rotate(stack_b, "rr", 1);
	}
}