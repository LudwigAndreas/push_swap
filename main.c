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

int main(int argc, char **argv)
{
	t_vault *vault;

	if (validator(argc, argv) == 0) {
		ft_putendl_fd("Error", 2);
		exit(1);
	}
	parse(argc,argv, &vault);
//TODO	is_sorted(vault);
//TODO	sort(vault);
	t_elem *elem = vault->a->head;
	while (elem->next != NULL)
	{
		ft_printf("%d", elem->number);
		elem = elem->next;
	}
	while (elem != NULL)
	{
		ft_printf("%d", elem->number);
		elem = elem->prev;
	}
	return (0);
}