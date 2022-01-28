#include "push_swap.h"

int is_sorted(int argc, int *array)
{
	int i;

	i = 0;
	while (i < argc - 2)
	{
		if (array[i] > array[i + 1])
			return (0);
		++i;
	}
	return (1);
}