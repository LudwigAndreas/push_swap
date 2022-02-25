/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsherry <lsherry@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 00:18:31 by lsherry           #+#    #+#             */
/*   Updated: 2022/02/24 00:18:34 by lsherry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	free_all(t_vault *vault, int *arr)
{
	t_elem *elem;
	t_elem *next;

	elem = vault->a->head;
	while (elem)
	{
		next = elem->next;
		free(elem);
		elem = next;
	}
	elem = vault->b->head;
	while (elem)
	{
		next = elem->next;
		free(elem);
		elem = next;
	}
	free(vault->a);
	free(vault->b);
	free(vault);
	free(arr);
}

int	main(int argc, char **argv)
{
	t_vault	*vault;
	int		*arr;

	arr = (int *) malloc(sizeof(int) * (argc - 1));
	if (argc < 2 || !arr)
		return (0);
	if (!validator(argc, argv, arr))
	{
		ft_putendl_fd("Error", 2);
		free(arr);
		return (0);
	}
	parse(argc, arr, &vault);
	checker(vault);
	free_all(vault, arr);
	return (0);
}
