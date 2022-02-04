#include "push_swap.h"
#include <stdio.h>

void	print_data(t_vault *vault, char *name)
{
	t_elem *elem_a;
	t_elem *elem_b;

	elem_a = vault->a->head;
	elem_b = vault->b->head;
	ft_putendl_fd("------------------------------------------------------------------------------------------------------------", 1);
	if (!name[0])
		ft_putendl_fd("Init a and b:", 1);
	else
	{
		ft_putstr_fd("Exec", 1);
		ft_putstr_fd(name, 1);
		ft_putendl_fd(":", 1);
	}
	while (elem_a || elem_b)
	{
		if (elem_a && elem_b)
		{
			ft_putnbr_fd(elem_a->number, 1);
			ft_putchar_fd(' ', 1);
			ft_putnbr_fd(elem_b->number, 1);
			ft_putendl_fd("", 1);
			elem_a = elem_a->next;
			elem_b = elem_b->next;
		}
		else if (elem_a)
		{
			ft_putnbr_fd(elem_a->number, 1);
			ft_putendl_fd("", 1);
			elem_a = elem_a->next;
		}
		else
		{
			ft_putnbr_fd(elem_b->number, 1);
			ft_putendl_fd("", 1);
			elem_b = elem_b->next;
		}
	}
	ft_putendl_fd("", 1);
	ft_putendl_fd("- -", 1);
	ft_putendl_fd("a b", 1);
	ft_putendl_fd("------------------------------------------------------------------------------------------------------------", 1);
}

int main(int argc, char **argv)
{
	t_vault *vault;
	int *arr;

	arr = (int *) malloc(sizeof(int) * (argc - 1));
	if (!arr)
		exit(1);
	if (validator(argc, argv, arr) == 0) {
		ft_putendl_fd("Error", 2);						//main
		exit(1);
	}
	if (is_sorted(argc, arr)) {
        ft_putendl_fd("Sorted", 1);						//trace
		exit(0);
	}
	else
	{
		ft_putendl_fd("start sorting...", 1);			//trace
		parse(argc, arr, &vault);
	}
	print_data(vault, "");
	//TODO	sort(vault);

	free(vault);
	return (0);
}