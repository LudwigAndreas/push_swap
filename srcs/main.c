/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsherry <lsherry@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:13:30 by lsherry           #+#    #+#             */
/*   Updated: 2022/02/18 17:13:31 by lsherry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "stdlib.h"

void	free_all(int *arr1, int *arr2, t_vault *vault)
{
	t_elem	*elem;
	t_elem	*next;

	free(arr1);
	free(arr2);
	elem = vault->a->head;
	while (elem)
	{
		next = elem->next;
		free(elem);
		elem = next;
	}
	free(vault->a);
	free(vault->b);
	free(vault);
}

int	main(int argc, char **argv)
{
	t_vault	*vault;
	int		*arr;
	int		*indexes;

	arr = (int *) malloc(sizeof(int) * (argc - 1));
	if (!arr)
		return (0);
	if (validator(argc, argv, arr) == 0)
	{
		ft_putendl_fd("Error", 2);
		return (0);
	}
	is_sorted(argc, arr);
	indexes = parse(argc, arr, &vault);
	print_data(vault, "");
	sort(vault, indexes);
	print_data(vault, "");
	free_all(arr, indexes, vault);
	return (0);
}
