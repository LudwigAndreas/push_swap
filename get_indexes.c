#include "push_swap.h"
#include "stdio.h"

int	*new_arr(int argc, int *array)
{
	int *temp;
	int i;

	temp = (int *) malloc(sizeof(int) * (argc - 1));
	if (!temp)
		return (NULL);
	i = 0;
	while (i < argc - 1)
	{
		temp[i] = array[i];
		i++;
	}
	return (temp);
}

void	get_indexes(int argc, int *array, int *indexes)
{
	int	i;
	int	j;
	int	*temp;

	temp = new_arr(argc, array);
	if (!temp)
		return;
	quick_sort(temp, (argc - 2));
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