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

#include "../includes/checker.h"

void	rr_three(t_stack *stack)
{
	t_elem	*first;
	t_elem	*last;

	first = stack->head;
	last = first->next->next;
	first->prev = last;
	last->next = first;
	first->next->next = NULL;
	last->prev = NULL;
	stack->head = last;
}

void	reverse_rotate(t_stack *stack, char name, int mode)
{
	t_elem	*first;
	t_elem	*last;

	if (stack && stack->head && stack->head->next)
	{
		if (stack->size == 3)
			rr_three(stack);
		else
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
		}
		print_func_name("rr", name, mode);
	}
}

void	rrr(t_stack *stack_a, t_stack *stack_b, int mode)
{
	reverse_rotate(stack_a, 'r', 0);
	if (mode)
		reverse_rotate(stack_b, 'r', 1);
	else
		reverse_rotate(stack_b, 'r', 0);
}
