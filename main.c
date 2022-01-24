#include "push_swap.h"
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

	if (validator(argc, argv) == 0)
		ft_printf("Error\n");
	parse(argc,argv, &vault);
//	is_sorted(vault);
//	sort(vault);
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