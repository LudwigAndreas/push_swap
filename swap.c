#include "push_swap.h"

void	swap(t_stack *stack, char *name, int mode)
{
	t_elem	*first;
	t_elem	*second;

	if (stack && stack->head && stack->head->next)
	{
		first = stack->head;
		second = first->next;
		first->next = second->next;
		first->prev = second;
		second->next = first;
		second->prev = NULL;
		stack->head = second;
		if (mode)
			ft_putendl_fd(name, 1);
	}
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a, "", 0);
	swap(stack_b, "ss", 1);
}