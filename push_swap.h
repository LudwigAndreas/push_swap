#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libftprintf/ft_printf.h"

typedef struct s_elem
{
	int number;
	int index;
	struct s_elem *next;
	struct s_elem *prev;
} t_elem;

typedef struct s_stack
{
	struct s_elem *head;
	int size;
	//*end?
} t_stack;

typedef struct s_vault
{
	struct s_stack *a;
	struct s_stack *b;
	int size;

} t_vault;

int validator(int argc, char **argv);
void parse(int argc, char **argv, t_vault **vault);
t_elem *ft_newelem(int nbr);
void	ft_elemadd_back(t_elem **lst, t_elem *new);
t_elem 	*ft_elemlast(t_elem *lst);

#endif
