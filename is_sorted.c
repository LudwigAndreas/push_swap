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

#include "push_swap.h"

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

int	is_stack_sorted(t_stack *stack)
{
	t_elem	*elem;

	elem = stack->head;
	while (elem->next != NULL)
	{
		if (elem->next->index < elem->index)
			return (0);
		elem = elem->next;
	}
	return (1);
}
