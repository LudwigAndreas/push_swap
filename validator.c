#include "push_swap.h"
#include <stdio.h>

int validator(int argc, char **argv, int array[])
{
	int i;
	int j;

	if (argc < 2)
		return (0);
	i = 0;
	while (i < argc - 1)
	{
		if (ft_atoi(argv[i + 1]) > 2147483647
			|| ft_atoi(argv[i + 1]) < (-2147483648) || ft_strlen(argv[i + 1]) > 11)
			return (0);
		j = 0;
		ft_putnbr_fd(ft_atoi(argv[i + 1]), 1);
		while (argv[i + 1][j++]) {
			if (argv[i + 1][0] != '-') {
				if (!ft_isdigit(argv[i + 1][j])) {
					return (0);
				}
			}
		}
		ft_putnbr_fd(ft_atoi(argv[i + 1]), 1);
		array[i] = ft_atoi(argv[i + 1]);
		j = i - 1;
		while (j < argc && j > 0)
		{
			if (array[i] == array[j])
				return (0);
			j--;
		}
		i++;
	}
	return (1);
}