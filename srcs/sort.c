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

void	sort(t_vault *vault, int *array)
{
	divide_a(vault, array);
//	get_scored();
//	ft_putnbr_fd(is_stack_sorted(vault->a), 1);
}
