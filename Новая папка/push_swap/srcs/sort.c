/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsherry <lsherry@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:14:42 by lsherry           #+#    #+#             */
/*   Updated: 2022/02/18 17:14:44 by lsherry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_scored(t_elem *to_score, int step, t_vault *vault)
{
	int	counter;

	counter = find_best_place(to_score, vault);
	if (counter >= vault->a->size / 2 && step >= vault->b->size / 2)
	{
		counter = vault->a->size - counter;
		step = vault->b->size - step;
		return (max(counter, step));
	}
	else if (counter <= vault->a->size / 2 && step <= vault->b->size / 2)
		return (max(counter, step));
	if (counter > vault->a->size / 2)
		counter = vault->a->size - counter;
	else if (step > vault->b->size / 2)
		step = vault->b->size - step;
	return (step + counter);
}

void	push_elem_back(t_elem *to_push_elem, t_vault *vault)
{
	int		counter;
	int		step;

	step = find_elem_index(to_push_elem, vault);
	counter = find_best_place(to_push_elem, vault);
	if (counter >= (vault->a->size / 2) + 1 && step >= (vault->b->size / 2) + 1
		&& vault->b->size != 0)
	{
		counter = vault->a->size - counter;
		step = vault->b->size - step;
		do_reverse_rotate(counter, step, vault);
	}
	else if (counter <= vault->a->size / 2 && step <= vault->b->size / 2)
		do_rotate(counter, step, vault);
	else if (counter > vault->a->size / 2 && step <= vault->b->size / 2)
		do_iter(vault->a->size - counter, step, 1, vault);
	else if (step > vault->b->size / 2 && counter <= vault->a->size / 2)
		do_iter(counter, vault->b->size - step, 2, vault);
//	print_data(vault, "");
	push(vault->b, vault->a, 'a', 1);
}

void	put_elem_b_to_a(t_vault *vault)
{
	t_elem	*elem;
	t_elem	*min_elem;
	int		step;
	int		min;
	int		temp;

	while (vault->b->head != NULL)
	{
		min = 2147483647;
		step = 0;
		elem = vault->b->head;
		while (elem)
		{
			temp = get_scored(elem, step, vault);
			if (min > temp)
			{
				min = temp;
				min_elem = elem;
			}
			step++;
			elem = elem->next;
		}
		push_elem_back(min_elem, vault);
//		print_data(vault, "");
	}
}

void	sort(t_vault *vault, int *array)
{
	t_elem	*elem;
	int		c;

	if (try_sort_one_stack(vault, array))
		return ;
	else
	{
		divide_a(vault, array);
//		print_data(vault, "");
		put_elem_b_to_a(vault);
	}
	c = 0;
	elem = vault->a->head;
	while (elem->index != 0 && elem->next)
	{
		c++;
		elem = elem->next;
	}
	while (vault->a->head->index != 0)
	{
		if (c > vault->a->size / 2)
			reverse_rotate(vault->a, 'a', 1);
		else
			rotate(vault->a, 'a', 1);
	}
}
