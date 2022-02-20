int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	get_max_index(t_stack *stack)
{
	t_elem	*elem;
	int		max;

	max = 0;
	elem = stack->head;
	while (elem)
	{
		if (elem->index > max)
			max = elem->index;
		elem = elem->next;
	}
	return (max);
}

int	get_min_index(t_stack *stack)
{
	t_elem	*elem;
	int		min;

	elem = stack->head;
	min = elem->index;
	while (elem)
	{
		if (elem->index < min)
			min = elem->index;
		elem = elem->next;
	}
	return (min);
}