#include "../includes/push_swap.h"

int	try_sort_one_stack(t_vault *vault, int *array)
{
	int		i;
	t_elem	*elem;

	i = 0;
	while (i < vault->a->size - 1)
	{
		if (array[i] < array[i + 1])
			return (0);
		i++;
	}
	while (vault->a->size != 1)
	{
		elem = vault->a->head;
		if (elem->index == vault->max)
			rotate(vault->a, 'a', 1);
		else
			push(vault->a, vault->b, 'b', 1);
	}
	while (vault->b->size != 0)
	{
		elem = vault->b->head;
		if (elem->index + 1 == vault->a->head->index)
			push(vault->b, vault->a, 'a', 1);
		else
			reverse_rotate(vault->b, 'b', 1);
	}
	return (1);
}