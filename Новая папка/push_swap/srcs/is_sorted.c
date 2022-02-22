/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsherry <lsherry@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 00:56:34 by lsherry           #+#    #+#             */
/*   Updated: 2022/02/02 00:56:43 by lsherry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(int argc, int *array)
{
	int	i;

	i = 0;
	while (i < argc - 2)
	{
		if (array[i] > array[i + 1])
			return (0);
		++i;
	}
	exit(0);
}

t_elem	*get_min(t_stack *stack)
{
	t_elem	*elem;
	t_elem	*start;

	elem = stack->head;
	start = elem;
	while (elem->next)
	{
		if (elem->index < start->index)
			start = elem;
		elem = elem->next;
	}
	return (start);
}

int	is_stack_sorted(t_stack *stack)
{
	t_elem	*elem;
	t_elem	*start;
	t_elem	*prev;

	start = get_min(stack);
	prev = start;
	elem = start;
	while (1)
	{
		if (elem->next)
		{
			if (elem->next == start)
				return (1);
			elem = elem->next;
		}
		else
		{
			if (stack->head == start)
				return (1);
			elem = stack->head;
		}
		if (prev->index > elem->index)
			return (0);
		prev = elem;
	}
}
