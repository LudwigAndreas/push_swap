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

int	main(int argc, char **argv)
{
	t_vault	*vault;
	int		*arr;
	char	*input;

	input = (char *) malloc(sizeof(char) * 1);
	arr = (int *) malloc(sizeof(int) * (argc - 1));
	if (argc < 2 || !arr)
		return (0);
	if (!validator(argc, argv, arr))
	{
		ft_putendl_fd("Error", 2);
		return (0);
	}
	if (is_sorted(argc, arr))
		return (0);
	parse(argc, arr, &vault);
	print_data(vault, "");
	checker(vault);
	print_data(vault, "");
	return (0);
}
