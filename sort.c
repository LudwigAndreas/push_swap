#include "push_swap.h"

int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

int *gls(int **temp, int *array, int size)
{
	int x;
	int y;
	int *out;
	int i;

	i = temp[size][size] - 1;
	x = size;
	y = size;
	out = (int *) malloc(sizeof(int) * i);
	if (!out)
		return NULL;
	while (temp[y][x] != 0)
	{
		if (temp[y][x] == temp[y - 1][x])
			--y;
		else if (temp[y][x] == temp[y][x - 1])
			--x;
		else
		{
			out[i--] = array[x - 1];
			--x;
			--y;
		}
	}
	return (out);
}

int	*largest_seq_len(int *array,t_vault *vault)
{
	int **temp_x;
	int x;
	int y;
	int *sequence;

	temp_x = (int **) malloc(sizeof(int *) * (vault->max + 2));
	y = 0;
	while (y < vault->max + 2)
	{
		temp_x[y] = (int *) ft_calloc(vault->max + 2, sizeof(int));
		x = 0;
		while (x < vault->max + 2)
		{
			if (x == 0 || y == 0)
				temp_x[y][x] = 0;
			else if (array[x - 1] == y - 1)
				temp_x[y][x] = temp_x[y - 1][x - 1] + 1;
			else
				temp_x[y][x] = max(temp_x[y - 1][x], temp_x[y][x - 1]);
			x++;
		}
		y++;
	}
	sequence = gls(temp_x, array, vault->max + 1);
	for (int i = 0; i < temp_x[vault->max + 1][vault->max + 1]; i++)
	{
		ft_putnbr_fd(sequence[i], 1);
	}
	return (sequence);
}

//void	devide_a(t_vault *vault, int max)
//{
//	//итерируемся по списку дважды для каждого элемента
//	//выбираем максимальный по включениню список и его "голову" заносим в markup
//
//
//}
//
//void	sort(t_vault *vault)
//{
//	t_stack *a;
//	t_stack *b;
//
//	a = vault->a;
//	b = vault->b;
//	devide_a(vault, 0);
//}