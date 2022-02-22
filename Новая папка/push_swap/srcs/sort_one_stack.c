/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_one_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsherry <lsherry@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:42:48 by lsherry           #+#    #+#             */
/*   Updated: 2022/02/22 12:42:50 by lsherry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	iter_stack_a(t_vault *vault)
{
	t_elem	*elem;

	while (vault->a->size != 1)
	{
		elem = vault->a->head;
		if (elem->index == vault->max)
			rotate(vault->a, 'a', 1);
		else
			push(vault->a, vault->b, 'b', 1);
	}
}

int	try_sort_one_stack(t_vault *vault, int *array)
{
	int		i;
	t_elem	*elem;

	if (vault->a->size <= 3)
		return (0);
	i = 0;
	while (i < vault->a->size - 1)
	{
		if (array[i] < array[i + 1])
			return (0);
		i++;
	}
	iter_stack_a(vault);
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
