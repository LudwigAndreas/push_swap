#include "push_swap.h"
#include <stdio.h>
//sa - swap a
//sb - swap b
//ss - sa && sb
//pa - push a
//pb - push b
//ra - rotate a;
//rb - rotate b;
//rr - ra && rb;
//rra - reverse rotate a;
//rrb - reverse rotate b;
//rrr - rra && rrb;
//algo - проверяем, что массив не отсортирован. После распределяем индексы по нашему массиву.
//оставляем как можно больше элементов в А (которые последовательно расположены), остальные элементы отправляем в b.
// теперь осталось переместить каждый элемент из б в а за минимальное количество шагов.зцв
//


/*
 * Начинаем алгоритм сортировки с учетом индексов
 */
int main(int argc, char **argv)
{
	t_vault *vault;
	int *arr;

	arr = (int *) malloc(sizeof(int) * (argc - 1));
	if (!arr)
		exit(1);
	if (validator(argc, argv, arr) == 0) {
		ft_putendl_fd("Error", 2);
		exit(1);
	}
	if (is_sorted(argc, arr)) {
		printf("Sorted");
		exit(0);
	}
	else
	{
		ft_putendl_fd("start sorting...", 1);
		parse(argc, arr, &vault);
	}
	//TODO	sort(vault);


	t_elem *elem = vault->a->head;
	while (elem != NULL)
	{
		ft_putnbr_fd(elem->number, 1);
		ft_putendl_fd("", 1);
		elem = elem->next;
	}
	elem = vault->a->head;
	ft_putendl_fd("\n", 1);
	while (elem != NULL)
	{
		ft_putnbr_fd(elem->index, 1);
		ft_putendl_fd("", 1);
		elem = elem->next;
	}



	return (0);
}