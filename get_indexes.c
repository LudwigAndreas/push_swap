#include "push_swap.h"
#include "stdio.h"

void get_indexes(int argc, int *array, int indexes[])
{
	int i;
	int j;
	int temp[argc - 1];

	i = 0;
	while (i < argc - 1)
	{
		temp[i] = array[i];
		i++;
	}
	quick_sort(temp, argc - 1);
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
}