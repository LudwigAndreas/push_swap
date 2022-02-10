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

int	*largest_seq_len(int *array, int size, int *ret_len)
{
	int **temp;
	int x;
	int y;
	int *sequence;				//TODO  массив чисел сделать сдвоенным, чтобы определялась поистине максимальная длинна
								//TODO массив индексов [indexes] можно крутить в функции до тех пор, пока не будет найдена максимально длинная последовательность при
								//TODO чем не в два полноценных прохода, а для каждой попытки создавать отдельный массив, для которого ищется наибольшая последовательность
								//TODO то есть переносить markup как угодно, не выводя ничего на экран до тех пор, пока не будет найден оптимальный ответ
	temp = (int **) malloc(sizeof(int *) * size + 1);
	y = 0;
	while (y < size + 1)
	{
		temp[y] = (int *) ft_calloc(size + 1, sizeof(int));
		x = 0;
		while (x < size + 1)
		{
			if (x == 0 || y == 0)
				temp[y][x] = 0;
			else if (array[x - 1] == y - 1)
				temp[y][x] = temp[y - 1][x - 1] + 1;
			else
				temp[y][x] = max(temp[y - 1][x], temp[y][x - 1]);
			x++;
		}
		y++;
	}
	sequence = gls(temp, array, size);
	*ret_len = temp[size][size];
	int i = 0;
	while (i < size + 1)
	{
		free(temp[i]);
		i++;
	}
	free(temp);
	return (sequence);
}

int	ft_isin_seq(t_elem *elem, int *seq, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (elem->index == seq[i])
			return (1);
		i++;
	}
	return (0);
}

void	divide_a(t_vault *vault, int *array)
{
	int		*seq;
	int		size;
	t_stack	*a;
	t_stack	*b;
	t_elem	*elem;
	int		i;

	i = 0;
	seq = largest_seq_len(array, vault->max + 1, &size);
	a = vault->a;
	b = vault->b;
	while (i <= vault->max + 1)
	{
		elem = a->head;
//		if (is_stack_sorted(a))
//			exit(1);
		if ((size >= 3 && ft_isin_seq(elem, seq, size))
			|| !(size < 3 && (elem->index == vault->max
			|| elem->index == vault->min || elem->index == vault->mid)))
		{
			push(a, b, "pb", 1);
//			print_data(vault, "pb");
		}
		else
		{
			rotate(a, "ra", 1);
//			print_data(vault, "ra");
		}
		i++;
	}
//	print_data(vault, "Devide A");
}

//void	get_scored(t_vault *vault)
//{
//	int max;
//	t_elem *best_score;
//	t_elem *elem;
//
//	max = 0;
//	elem = vault->b->head;
//	while (elem != NULL)
//	{
//		if (elem->index)
//	}
//}

void	sort(t_vault *vault, int *array)
{
	divide_a(vault, array);
//	get_scored();
//	ft_putnbr_fd(is_stack_sorted(vault->a), 1);
}