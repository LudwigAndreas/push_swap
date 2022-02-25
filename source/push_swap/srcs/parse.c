/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsherry <lsherry@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:13:36 by lsherry           #+#    #+#             */
/*   Updated: 2022/02/18 17:13:38 by lsherry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	get_minmax(t_vault *vault, int size)
{
	vault->max = size - 1;
	vault->min = 0;
	vault->mid = (int )(vault->max + 1 / 2);
	vault->size = size;
}

int	*parse(int argc, int *arr, t_vault **vault)
{
	int		i;
	int		*indexes;
	t_elem	*prev;

	indexes = (int *) malloc(sizeof(int) * (argc - 1));
	*vault = (t_vault *) malloc(sizeof(t_vault));
	if (!(*vault) || !indexes)
		exit(0);
	(*vault)->a = malloc(sizeof(t_stack));
	(*vault)->b = malloc(sizeof(t_stack));
	(*vault)->b->head = NULL;
	(*vault)->a->head = NULL;
	(*vault)->a->size = argc - 1;
	(*vault)->b->size = 0;
	i = 0;
	get_indexes(argc, arr, indexes);
	prev = NULL;
	while (i < argc - 1)
	{
		prev = ft_newelem(arr[i], indexes[i], prev);
		ft_elemadd_back(&((*vault)->a->head), prev);
		i++;
	}
	get_minmax(*vault, argc - 1);
	return (indexes);
}
