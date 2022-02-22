/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsherry <lsherry@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:13:42 by lsherry           #+#    #+#             */
/*   Updated: 2022/02/18 17:13:45 by lsherry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_data(t_vault *vault, char *name)
{
	t_elem	*elem_a;
	t_elem	*elem_b;

	elem_a = vault->a->head;
	elem_b = vault->b->head;
	ft_putendl_fd("----------------------------"
				  "----------------------------------------------------"
				  "----------------------------", 1);
	if (!name[0])
		ft_putendl_fd("Init a and b:", 1);
	else
	{
		ft_putstr_fd("Exec ", 1);
		ft_putstr_fd(name, 1);
		ft_putendl_fd(":", 1);
	}
	while (elem_a || elem_b)
	{
		if (elem_a && elem_b)
		{
			ft_putnbr_fd(elem_a->number, 1);
			ft_putchar_fd(' ', 1);
			ft_putnbr_fd(elem_b->number, 1);
			ft_putendl_fd("", 1);
			elem_a = elem_a->next;
			elem_b = elem_b->next;
		}
		else if (elem_a)
		{
			ft_putnbr_fd(elem_a->number, 1);
			ft_putendl_fd("", 1);
			elem_a = elem_a->next;
		}
		else
		{
			ft_putstr_fd("  ", 1);
			ft_putnbr_fd(elem_b->number, 1);
			ft_putendl_fd("", 1);
			elem_b = elem_b->next;
		}
	}
	ft_putendl_fd("", 1);
	ft_putendl_fd("- -", 1);
	ft_putendl_fd("a b", 1);
	ft_putendl_fd("----------------------------"
				  "----------------------------------------------------"
				  "----------------------------", 1);
}
