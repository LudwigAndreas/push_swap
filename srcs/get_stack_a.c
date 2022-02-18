/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsherry <lsherry@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:13:07 by lsherry           #+#    #+#             */
/*   Updated: 2022/02/18 17:13:08 by lsherry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	mini_sort(t_stack *stack, char stack_name)
{
	t_elem	*one;
	t_elem	*two;
	t_elem	*three;

	if (stack->size == 2 && !is_stack_sorted(stack))
		swap(stack, stack_name, 1);
	while (!is_stack_sorted(stack))
	{
		one = stack->head;
		two = stack->head->next;
		three = stack->head->next->next;
		if (one->index > two->index && one->index > three->index)
			rotate(stack, stack_name, 1);
		else if (two->index > one->index && two->index > three->index)
			reverse_rotate(stack, stack_name, 1);
		else if (one->index > two->index)
			swap(stack, stack_name, 1);
	}
}

void	divide_a(t_vault *vault, int *array)
{
	int		*seq;
	int		size;
	t_elem	*elem;
	int		i;

	i = 0;
	seq = largest_seq_len(array, vault->max + 1, &size);
	while (i <= vault->max + 1)
	{
		elem = vault->a->head;
		if ((size >= 3 && vault->a->size == size)
			|| (size < 3 && vault->a->size == 3)
			|| is_stack_sorted(vault->a))
			break ;
		if ((size > 3 && !ft_isin_seq(elem, seq, size))
			|| (size < 3 && !(elem->index == vault->max
					|| elem->index == vault->min || elem->index == vault->mid)))
			push(vault->a, vault->b, 'b', 1);
		else
			rotate(vault->a, 'a', 1);
		i++;
	}
	if (vault->a->size == 3)
		mini_sort(vault->a, 'a');
	free(seq);
}
