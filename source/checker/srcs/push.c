/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsherry <lsherry@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:13:50 by lsherry           #+#    #+#             */
/*   Updated: 2022/02/18 17:13:53 by lsherry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	print_func_name(char *funcname, char stackname, int mode)
{
	if (mode)
	{
		ft_putstr_fd(funcname, 1);
		ft_putchar_fd(stackname, 1);
		ft_putendl_fd("", 1);
	}
}

void	push_null(t_stack *from, t_stack *to)
{
	t_elem	*temp;

	temp = from->head;
	temp->next = to->head;
	temp->prev = NULL;
	to->head->prev = temp;
	to->head = temp;
	from->head = NULL;
	to->size++;
	from->size--;
}

void	push(t_stack *from, t_stack *to, char name, int mode)
{
	t_elem	*temp;

	if (from && from->head)
	{
		if (from->head->next)
		{
			temp = from->head->next;
			ft_elemadd_front(&(to->head), from->head);
			temp->prev = NULL;
			from->head = temp;
			from->size--;
			to->size++;
		}
		else
		{
			push_null(from, to);
		}
		print_func_name("p", name, mode);
	}
}
