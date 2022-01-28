#include "push_swap.h"
#include <stdio.h>

int validator(int argc, char **argv, int array[])
{
	int i;
	int j;


	if (argc < 2)
		return (0);
	i = 1;
	while (i < argc)
	{
		array[i - 1] = ft_atoi(argv[i]);
		j = i + 1;
		while (j < argc)
		{
			//TODO валидация цифр больше и меньше инта 2147483647
			if (array[i] == ft_atoi(argv[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}