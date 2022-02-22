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

int	find_best_place(t_elem	*to_find, t_vault *vault)
{
	int		counter;
	t_elem	*elem;

	elem = vault->a->head;
	counter = 0;
	while (elem->next)
	{
		if (to_find->index > get_max_index(vault->a) && elem->index == get_min_index(vault->a))
			break ;
		else if (to_find->index < get_min_index(vault->a) && elem->index == get_min_index(vault->a))
			break ;
		else if (vault->a->head->index > to_find->index && ft_elemlast(vault->a->head)->index < to_find->index)
			break ;
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
	while (elem)
	{
		if (elem == to_find)
			break ;
		step++;
		elem = elem->next;
	}
	return (step);
}

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
	{
		return (max(counter, step));
	}
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
//	ft_putstr_fd("elem: ", 1);
//	ft_putnbr_fd(to_push_elem->number, 1);
//	ft_putstr_fd(" counter: ", 1);
//	ft_putnbr_fd(counter, 1);
//	ft_putstr_fd(" step: ", 1);
//	ft_putnbr_fd(step, 1);
//	ft_putstr_fd(" index: ", 1);
//	ft_putnbr_fd(to_push_elem->index, 1);

	if (counter >= (vault->a->size / 2) + 1 && step >= (vault->b->size / 2) + 1 && vault->b->size != 0)
	{
//		ft_putnbr_fd(counter, 1);
//		ft_putnbr_fd(step, 1);
		counter = vault->a->size - counter;
		step = vault->b->size - step;

		do_reverse_rotate(counter, step, vault);
//		print_data(vault, "rra");
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
//			ft_putnbr_fd(elem->number, 1);		//trace
//			ft_putstr_fd(" : ", 1);				//trace
//			ft_putnbr_fd(temp, 1);				//trace
//			ft_putstr_fd(" | ", 1);				//trace
			if (min > temp)
			{
				min = temp;
				min_elem = elem;
			}
			step++;
			elem = elem->next;
		}
//		ft_putendl_fd("++", 1);					//trace
		push_elem_back(min_elem, vault);
//		print_data(vault, "");
	}
}

void	sort(t_vault *vault, int *array)
{
	t_elem	*elem;
	int c;

	if (try_sort_one_stack(vault, array))
		return;
	else
	{
		divide_a(vault, array);
//		print_data(vault, "after divide");
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
