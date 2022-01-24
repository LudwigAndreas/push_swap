#include "libftprintf/ft_printf.h"
#include <stdio.h>

int validator(int argc, char **argv)
{
	int i;
	int j;

	if (argc < 2)
		return (0);
	i = 0;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j])) //TODO валидация цифр больше и меньше инта
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}