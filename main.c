#include "push_swap.h"
#include <stdio.h>

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

//	swap(vault->a);
//	push(vault->a, vault->b);
//	rotate(vault->a);
//	reverse_rotate(vault->a);
	t_elem *elem_a = vault->a->head;
	t_elem *elem_b = vault->b->head;
	ft_putendl_fd("---A---", 1);
	while (elem_a != NULL)
	{
		ft_putnbr_fd(elem_a->number, 1);
		ft_putendl_fd("", 1);
		elem_a = elem_a->next;
	}
	elem_a = vault->a->head;
	ft_putendl_fd("\n", 1);
	while (elem_a != NULL)
	{
		ft_putnbr_fd(elem_a->index, 1);
		ft_putendl_fd("", 1);
		elem_a = elem_a->next;
	}
	ft_putendl_fd("---B---", 1);
	while (elem_b != NULL)
	{
		ft_putnbr_fd(elem_b->number, 1);
		ft_putendl_fd("", 1);
		elem_b = elem_b->next;
	}
	return (0);
}