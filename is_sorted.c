/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsherry <lsherry@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 00:56:34 by lsherry           #+#    #+#             */
/*   Updated: 2022/02/02 00:56:43 by lsherry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(int argc, int *array)
{
	int	i;

	i = 0;
	while (i < argc - 2)
	{
		if (array[i] > array[i + 1])
			return (0);
		++i;
	}
	return (1);
}
