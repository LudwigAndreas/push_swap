/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsherry <lsherry@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:43:18 by lsherry           #+#    #+#             */
/*   Updated: 2022/02/22 12:43:20 by lsherry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
