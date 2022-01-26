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

int main(int argc, char **argv)
{
	t_vault *vault;

	if (validator(argc, argv) == 0) {
		ft_putendl_fd("Error", 2);
		exit(1);
	}
	parse(argc,argv, &vault);
	if (is_sorted(vault->a))
		exit(0);
	else
	{
		ft_putendl_fd("start sorting...", 1);
	}
//TODO	sort(vault);
	return (0);
}