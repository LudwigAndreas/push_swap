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

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	find_best_place(t_elem	*to_find, t_vault *vault)
{
	int		counter;
	t_elem	*elem;

	elem = vault->a->head;
	counter = 0;
	while (elem->next)
	{
		counter++;
		if (elem->index < to_find->index && to_find->index < elem->next->index)
			break ;
		elem = elem->next;
	}
	return (counter);
}

int find_elem_index(t_elem *to_find, t_vault *vault)
{
	int		step;
	t_elem	*elem;

	step = 0;
	elem = vault->b->head;
	while (elem->next)
	{
		if (elem == to_find)
			break ;
		step++;
	}
	return (step);
}

int	get_scored(t_elem *to_score, int step, t_vault *vault)
{
	int		counter;

	counter = find_best_place(to_score, vault);
	if (counter >= vault->a->size / 2 && step >= vault->b->size / 2)
	{
		counter = vault->a->size - counter;
		step = vault->b->size - step;
		return (max(counter, step));
	}
	else if (counter <= vault->a->size / 2 && step <= vault->b->size / 2)
	{
		return (max(counter, step));
	}
	if (counter > vault->a->size / 2)
		counter = vault->a->size - counter;
	else if (step > vault->b->size / 2)
		step = vault->b->size - step;
	return (step + counter);
}

void	do_rotate(int counter, int step, t_vault *vault)
{
	while (counter != 0 || step != 0)
	{
		if (counter != 0 && step != 0)
		{
			counter--;
			step--;
			rr(vault->a, vault->b);
		}
		else if (counter != 0)
		{
			counter--;
			rotate(vault->a, 'a', 1);
		}
		else
		{
			step--;
			rotate(vault->b, 'b', 1);
		}
	}
}

void	do_reverse_rotate(int counter, int step, t_vault *vault)
{
	while (counter != 0 || step != 0)
	{
		if (counter != 0 && step != 0)
		{
			counter--;
			step--;
			rrr(vault->a, vault->b);
		}
		else if (counter != 0)
		{
			counter--;
			reverse_rotate(vault->a, 'a', 1);
		}
		else
		{
			step--;
			reverse_rotate(vault->b, 'b', 1);
		}
	}
}

void	do_iter(int counter, int step, int mode, t_vault *vault)
{
	while (counter != 0 || step != 0)
	{
		if (mode == 1 && counter != 0)
		{
			counter--;
			reverse_rotate(vault->a, 'a', 1);
		}
		if (mode == 1 && step != 0)
		{
			step--;
			rotate(vault->b, 'b', 1);
		}
		if (mode == 2 && counter != 0)
		{
			counter--;
			rotate(vault->a, 'a', 1);
		}
		if (mode == 2 && step != 0)
		{
			step--;
			reverse_rotate(vault->b, 'b', 1);
		}
	}
}

void	push_elem_back(t_elem *to_push_elem, t_vault *vault)
{
	int		counter;
	int		step;

	step = find_elem_index(to_push_elem, vault);
	counter = find_best_place(to_push_elem, vault);

	if (counter >= vault->a->size / 2 && step >= vault->b->size / 2)
	{
		counter = vault->a->size - counter;
		step = vault->b->size - step;
		do_reverse_rotate(counter, step, vault);
		push(vault->b, vault->a, 'a', 1);
		return ;
	}
	else if (counter <= vault->a->size / 2 && step <= vault->b->size / 2)
	{
		do_rotate(counter, step, vault);
		push(vault->b, vault->a, 'a', 1);
		return ;
	}
	if (counter > vault->a->size / 2)
		do_iter(vault->a->size - counter, step, 1, vault);
	else if (step > vault->b->size / 2)
		do_iter(counter, vault->b->size - step, 2, vault);
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
		while (elem) {
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
	}
}

void	sort(t_vault *vault, int *array)
{
	t_elem	*elem;
	int c;

	divide_a(vault, array);
	put_elem_b_to_a(vault);
	c = 0;
	elem = vault->a->head;
	while (elem->index != 0 && elem->next)
	{
		c++;
		elem = elem->next;
	}
	if (c > vault->a->size / 2)
		do_reverse_rotate(vault->a->size - c, 0, vault);
	do_rotate(c, 0, vault);
}
