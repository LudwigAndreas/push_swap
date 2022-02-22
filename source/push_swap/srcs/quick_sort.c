/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsherry <lsherry@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:13:57 by lsherry           #+#    #+#             */
/*   Updated: 2022/02/18 17:13:58 by lsherry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	partition(int *numbers, int l, int r)
{
	int	i;
	int	x;
	int	less;

	x = numbers[r];
	less = l;
	i = l;
	while (i < r)
	{
		if (numbers[i] <= x)
		{
			ft_swap(&numbers[i], &numbers[less]);
			less++;
		}
		++i;
	}
	ft_swap(&numbers[less], &numbers[r]);
	return (less);
}

static void	quick_sort_impl(int *numbers, int l, int r)
{
	int	q;

	if (l < r)
	{
		q = partition(numbers, l, r);
		quick_sort_impl(numbers, l, q - 1);
		quick_sort_impl(numbers, q + 1, r);
	}
}

void	quick_sort(int *numbers, int size)
{
	if (size != 0)
		quick_sort_impl(numbers, 0, size);
}
