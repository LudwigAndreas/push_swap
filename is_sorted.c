#include "push_swap.h"

int is_sorted(t_stack *stack)
{
	int previous_number;
	t_elem *elem;
	int flag = 0;

	elem = stack->head;
	while (elem != NULL)
	{
		previous_number = elem->number;
		elem = elem->next;
		if (elem && previous_number > elem->number) {
			flag = 1;
			break;
		}
	}
	if (flag == 1)
		return (0);
	return (1);
}