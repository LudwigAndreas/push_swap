#include "push_swap.h"
void	devide_a(t_vault *vault, int max)
{
	//итерируемся по списку дважды для каждого элемента
	//выбираем максимальный по включениню список и его "голову" заносим в markup
	int counter;
	int i;
	t_elem *elem;
	t_elem *markup;
	t_elem *prev;

	elem = vault->a->head;
	prev = elem;
	while (prev != elem)
	{
		if (elem->next == NULL)
			elem = prev;

	}
}

void	sort(t_vault *vault)
{
	t_stack *a;
	t_stack *b;

	a = vault->a;
	b = vault->b;
	devide_a(vault, 0);
}