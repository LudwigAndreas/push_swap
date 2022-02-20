/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsherry <lsherry@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:14:01 by lsherry           #+#    #+#             */
/*   Updated: 2022/02/18 17:14:03 by lsherry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	reverse_rotate(t_stack *stack, char name, int mode)
{
	t_elem	*first;
	t_elem	*last;

	if (stack->head && stack->head->next)
	{
		first = stack->head;
		last = first;
		while (last->next)
			last = last->next;
		last->next = first;
		last->prev->next = NULL;
		last->prev = NULL;
		first->prev = last;
		stack->head = last;
		if (mode)
		{
			ft_putstr_fd("rr", 1);
			ft_putchar_fd(name, 1);
			ft_putendl_fd("", 1);
		}
	}
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(stack_a, 'r', 0);
	reverse_rotate(stack_b, 'r', 1);
}
