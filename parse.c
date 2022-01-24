#include "push_swap.h"

void parse(int argc, char **argv, t_vault **vault)
{
	int i;

	*vault = (t_vault *) malloc(sizeof(t_vault));
	if (!(*vault))
		exit(1);
	(*vault)->a = malloc(sizeof((*vault)->a));
	(*vault)->b = malloc(sizeof((*vault)->a));
	(*vault)->b->head = NULL;
	(*vault)->a->head = NULL;
	(*vault)->a->size = argc - 1;
	i = 1;
	while (i < argc)
	{
		ft_elemadd_back(&((*vault)->a->head), ft_newelem(ft_atoi(argv[i])));
		i++;
	}
}