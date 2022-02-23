/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsherry <lsherry@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 00:17:36 by lsherry           #+#    #+#             */
/*   Updated: 2022/02/24 00:17:38 by lsherry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

char	*ft_strndup(char *src, unsigned int n)
{
	unsigned int	i;
	char			*dest;
	unsigned int	j;

	j = 0;
	i = 0;
	while (src[i])
		i++;
	if (i < n)
		n = i;
	dest = (char *) malloc(n + 1);
	while (j < n)
	{
		dest[j] = src[j];
		++j;
	}
	dest[n] = '\0';
	return (dest);
}

int	ft_readline(int fd, char **str)
{
	char	line[20000];
	char	ch;
	int		pos;
	int		rd;

	pos = 0;
	rd = 1;
	while (rd > 0)
	{
		rd = read(fd, &ch, 1);
		if (ch == '\n' || rd == 0)
			break ;
		line[pos] = ch;
		pos++;
	}
	line[pos] = '\0';
	*str = ft_strndup(line, pos);
	return (ft_strlen(*str));
}
