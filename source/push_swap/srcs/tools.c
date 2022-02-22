/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsherry <lsherry@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:43:10 by lsherry           #+#    #+#             */
/*   Updated: 2022/02/22 12:43:13 by lsherry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	find_best_place(t_elem	*to_find, t_vault *vault)
{
	int		counter;
	t_elem	*elem;

	elem = vault->a->head;
	counter = 0;
	while (elem->next)
	{
		if (to_find->index > get_max_index(vault->a)
			&& elem->index == get_min_index(vault->a))
			break ;
		else if (to_find->index < get_min_index(vault->a)
			&& elem->index == get_min_index(vault->a))
			break ;
		else if (vault->a->head->index > to_find->index
			&& ft_elemlast(vault->a->head)->index < to_find->index)
			break ;
		counter++;
		if (elem->index < to_find->index && to_find->index < elem->next->index)
			break ;
		elem = elem->next;
	}
	return (counter);
}

int	find_elem_index(t_elem *to_find, t_vault *vault)
{
	int		step;
	t_elem	*elem;

	step = 0;
	elem = vault->b->head;
	while (elem)
	{
		if (elem == to_find)
			break ;
		step++;
		elem = elem->next;
	}
	return (step);
}
