/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsherry <lsherry@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 00:18:01 by lsherry           #+#    #+#             */
/*   Updated: 2022/02/24 00:18:04 by lsherry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	is_stack_sorted(t_stack *stack)
{
	t_elem	*elem;

	elem = stack->head;
	while (elem->next)
	{
		if (elem->index > elem->next->index)
			return (0);
		elem = elem->next;
	}
	return (1);
}
