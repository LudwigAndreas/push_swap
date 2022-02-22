/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   largest_seq.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsherry <lsherry@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:13:15 by lsherry           #+#    #+#             */
/*   Updated: 2022/02/18 17:13:17 by lsherry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	*gls(int **temp, int *array, int size)
{
	int	x;
	int	y;
	int	*out;
	int	i;

	i = temp[size][size];
	x = size;
	y = size;
	out = (int *) malloc(sizeof(int) * i);
	if (!out)
		return (NULL);
	while (temp[y][x] > 0)
	{
		if (temp[y][x] == temp[y - 1][x])
			--y;
		else if (temp[y][x] == temp[y][x - 1])
			--x;
		else
		{
			out[--i] = array[x - 1];
			--x;
			--y;
		}
	}
	return (out);
}

void	free_temp(int **temp, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(temp[i]);
		i++;
	}
	free(temp);
}

int	gls_iter(int x, int y, int **temp, int *array)
{
	if (x == 0 || y == 0)
		return (0);
	else if (array[x - 1] == y - 1)
		return (temp[y - 1][x - 1] + 1);
	else
		return (max(temp[y - 1][x], temp[y][x - 1]));
}

int	*largest_seq_len(int *array, int size, int *ret_len)
{
	int	**temp;
	int	x;
	int	y;
	int	*sequence;

	temp = (int **) malloc(sizeof(int *) * (size + 1));
	y = 0;
	while (y < size + 1)
	{
		temp[y] = (int *) malloc(sizeof(int) * (size + 1));
		x = 0;
		while (x < size + 1)
		{
			temp[y][x] = gls_iter(x, y, temp, array);
			x++;
		}
		y++;
	}
	sequence = gls(temp, array, size);
	*ret_len = temp[size][size];
	free_temp(temp, size + 1);
	return (sequence);
}

int	ft_isin_seq(t_elem *elem, int *seq, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (elem->index == seq[i])
			return (1);
		i++;
	}
	return (0);
}
