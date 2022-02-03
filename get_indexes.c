#include "push_swap.h"
#include "stdio.h"

void get_indexes(int argc, int *array, int *indexes)
{
	int i;
	int j;
	int *temp;

	temp = (int *) malloc(sizeof(int) * (argc - 1));
	if (!temp)
		return;
	i = 0;
	while (i < argc - 1)
	{
		temp[i] = array[i];
		i++;
	}
//	i = 0;
//	ft_putendl_fd("Until sort", 1);
//	while (i < argc - 1) 							//trace
//	{
//		ft_putnbr_fd(temp[i], 1);
//		ft_putendl_fd("", 1);
//		i++;
//	}
	quick_sort(temp, (argc - 2));
//	i = 0;
//	ft_putendl_fd("After sort", 1);
//	while (i < argc - 1) 							//trace
//	{
//		ft_putnbr_fd(temp[i], 1);
//		ft_putendl_fd("", 1);
//		i++;
//	}
	i = 0;
	while (i < argc - 1)
	{
		j = 0;
		while (j < argc - 1)
		{
			if (array[i] == temp[j])
				indexes[i] = j;
			j++;
		}
		i++;
	}
	free(temp);
}