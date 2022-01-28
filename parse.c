#include "push_swap.h"

void parse(int argc, int *arr, t_vault **vault)
{
	int i;
	int indexes[argc - 1];

	*vault = (t_vault *) malloc(sizeof(t_vault));
	if (!(*vault))
		exit(1);
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
}