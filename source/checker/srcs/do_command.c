/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsherry <lsherry@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 00:17:30 by lsherry           #+#    #+#             */
/*   Updated: 2022/02/24 00:17:32 by lsherry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	do_command(int com_index, t_vault *vault)
{
	if (com_index == 1)
		push(vault->b, vault->a, 'a', 0);
	else if (com_index == 2)
		push(vault->a, vault->b, 'b', 0);
	else if (com_index == 3)
		swap(vault->a, 'a', 0);
	else if (com_index == 4)
		swap(vault->b, 'b', 0);
	else if (com_index == 5)
		ss(vault->a, vault->b, 0);
	else if (com_index == 6)
		rotate(vault->a, 'a', 0);
	else if (com_index == 7)
		rotate(vault->b, 'b', 0);
	else if (com_index == 8)
		rr(vault->a, vault->b, 0);
	else if (com_index == 9)
		reverse_rotate(vault->a, 'a', 0);
	else if (com_index == 10)
		reverse_rotate(vault->b, 'b', 0);
	else if (com_index == 11)
		rrr(vault->a, vault->b, 0);
}
