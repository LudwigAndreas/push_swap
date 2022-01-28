#include "push_swap.h"

void static ft_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int static partition(int *numbers, int l, int r)
{
	int i;
	int x;
	int less;

	x = numbers[r];
	less = l;
	i = l;
	while (i < r)
	{
		if (numbers[i] <= x)
		{
			ft_swap(&numbers[i], &numbers[less]);
			less++;
		}
		++i;
	}
	ft_swap(&numbers[less], &numbers[r]);
	return (less);
}

void static quick_sort_impl(int *numbers, int l, int r)
{
	int q;

	if (l < r)
	{
		q = partition(numbers, l, r);
		quick_sort_impl(numbers, l, q - 1);
		quick_sort_impl(numbers, q + 1, r);
	}
}

void quick_sort(int *numbers, int size)
{
	if (size != 0)
	{
		quick_sort_impl(numbers, 0, size);
	}
}