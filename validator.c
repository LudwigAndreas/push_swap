#include "push_swap.h"
#include <stdio.h>

//TODO 32 linebreaks insted 24
//TODO norminette

int	is_valid(char *arg)
{
	int	j;

	if (ft_atoi(arg) > 2147483647
		|| ft_atoi(arg) < (-2147483648) || ft_strlen(arg) > 11)
		return (0);
	j = 1;
	if (!ft_isdigit(arg[0]) && arg[0] == '-')
	{
		if (!ft_isdigit(arg[1]))
			return (0);
		j = 1;
	}
	else if (!ft_isdigit(arg[0]))
		return (0);
	while (arg[j]) {
		if (!ft_isdigit(arg[j++]))
			return (0);
	}
	return (j);
}

int	validator(int argc, char **argv, int array[])
{
	int	i;
	int	j;

	if (argc < 2)
		return (0);
	i = 0;
	while (i < argc - 1)
	{
		if (!is_valid(argv[i + 1]))
			return (0);
		array[i] = ft_atoi(argv[i + 1]);
		j = i - 1;
		while (j >= 0)
		{
			if (array[i] == array[j--])
				return (0);
		}
		i++;
	}
	return (1);
}