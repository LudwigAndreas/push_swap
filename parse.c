#include "push_swap.h"
void	get_minmax(t_vault *vault)
{
	t_elem *a;
	t_elem *elem;

	a = vault->a->head;
	elem = a;
	while (elem != NULL)
	{
		if(elem->index > vault->max)
			vault->max = elem->index;
		else if (elem->index < vault->min)
			vault->min = elem->index;
		elem = elem->next;
	}
	vault->mid = (int) (vault->max / 2);
}

int	*parse(int argc, int *arr, t_vault **vault)
{
	int	i;
	int	*indexes;

	indexes = (int *) malloc(sizeof(int) * (argc - 1));
	*vault = (t_vault *) malloc(sizeof(t_vault));
	if (!(*vault) || !indexes)
		exit(1);
	(*vault)->max = 0;
	(*vault)->min = 0;
	(*vault)->mid = 0;
	(*vault)->a = malloc(sizeof((*vault)->a));
	(*vault)->b = malloc(sizeof((*vault)->a));
	(*vault)->b->head = NULL;
	(*vault)->a->head = NULL;
	(*vault)->a->size = argc - 1;
	i = 1;
	get_indexes(argc, arr, indexes);
	while (i < argc)
	{
		ft_elemadd_back(&((*vault)->a->head), ft_newelem(arr[i - 1], indexes[i - 1]));
		i++;
	}
	get_minmax(*vault);
//	free(indexes);
	return(indexes);
}