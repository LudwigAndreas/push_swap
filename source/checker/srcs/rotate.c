/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsherry <lsherry@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:14:07 by lsherry           #+#    #+#             */
/*   Updated: 2022/02/18 17:14:11 by lsherry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	rotate(t_stack *stack, char name, int mode)
{
	t_elem	*first;
	t_elem	*last;

	if (stack && stack->head && stack->head->next)
	{
		first = stack->head;
		last = ft_elemlast(first);
		last->next = first;
		stack->head = first->next;
		first->next = NULL;
		first->prev = last;
		stack->head->prev = NULL;
		if (mode)
		{
			ft_putchar_fd('r', 1);
			ft_putchar_fd(name, 1);
			ft_putendl_fd("", 1);
		}
	}
}

void	rr(t_stack *stack_a, t_stack *stack_b, int mode)
{
	if (stack_b && stack_a)
	{
		rotate(stack_a, 'r', 0);
		if (mode)
			rotate(stack_b, 'r', 1);
		else
			rotate(stack_b, 'r', 0);
	}
}
