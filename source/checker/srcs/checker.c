/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsherry <lsherry@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 00:17:19 by lsherry           #+#    #+#             */
/*   Updated: 2022/02/25 20:18:19 by lsherry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	com_len_two(char *command)
{
	if (ft_strncmp("pa", command, 2) == 0)
		return (1);
	else if (ft_strncmp("pb", command, 2) == 0)
		return (2);
	else if (ft_strncmp("sa", command, 2) == 0)
		return (3);
	else if (ft_strncmp("sb", command, 2) == 0)
		return (4);
	else if (ft_strncmp("ss", command, 2) == 0)
		return (5);
	else if (ft_strncmp("ra", command, 2) == 0)
		return (6);
	else if (ft_strncmp("rb", command, 2) == 0)
		return (7);
	else if (ft_strncmp("rr", command, 2) == 0)
		return (8);
	return (0);
}

int	com_len_three(char *command)
{
	if (ft_strncmp("rra", command, 3) == 0)
		return (9);
	else if (ft_strncmp("rrb", command, 3) == 0)
		return (10);
	else if (ft_strncmp("rrr", command, 3) == 0)
		return (11);
	return (0);
}

int	is_com_valid(char *command)
{
	int	len;
	int	com_index;

	com_index = 0;
	len = ft_strlen(command);
	if (len > 3 || len < 2)
		return (0);
	else if (len == 2)
		com_index = com_len_two(command);
	else if (len == 3)
		com_index = com_len_three(command);
	if (!com_index)
		return (0);
	return (com_index);
}

int	wait_input(t_vault *vault)
{
	int		rd;
	char	*command;
	int		com_index;

	while (1)
	{
		command = NULL;
		rd = ft_readline(0, &command);
		com_index = is_com_valid(command);
		free(command);
		if (rd == 0)
			break ;
		if (!com_index)
			return (0);
		do_command(com_index, vault);
	}
	if (is_stack_sorted(vault->a) && vault->b->head == NULL
		&& vault->a->size == vault->size)
		return (1);
	return (-1);
}

void	checker(t_vault *vault)
{
	int	check;

	check = wait_input(vault);
	if (!check)
	{
		ft_putendl_fd("Error", 2);
		return ;
	}
	if (check == -1)
	{
		ft_putendl_fd("KO", 1);
		return ;
	}
	else
	{
		ft_putendl_fd("OK", 1);
		return ;
	}
}
