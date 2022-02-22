/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsherry <lsherry@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:14:47 by lsherry           #+#    #+#             */
/*   Updated: 2022/02/18 17:14:51 by lsherry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack *stack, char name, int mode)
{
	t_elem	*first;
	t_elem	*second;

	if (stack && stack->head && stack->head->next)
	{
		first = stack->head;
		second = first->next;
		first->next = second->next;
		first->prev = second;
		second->next = first;
		second->prev = NULL;
		stack->head = second;
		if (mode)
		{
			ft_putchar_fd('s', 1);
			ft_putchar_fd(name, 1);
			ft_putendl_fd("", 1);
		}
	}
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a, 's', 0);
	swap(stack_b, 's', 1);
}
