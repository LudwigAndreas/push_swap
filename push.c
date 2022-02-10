#include "push_swap.h"

void	push(t_stack *from, t_stack *to, char *name, int mode)
{
	t_elem	*temp;

	if (from)
	{
		temp = from->head->next;
		ft_elemadd_front(&(to->head), from->head);
		temp->prev = NULL;
		from->head = temp;
		if (mode)
			ft_putendl_fd(name, 1);
	}
}