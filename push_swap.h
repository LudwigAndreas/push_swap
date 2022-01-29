#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"

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

int validator(int argc, char **argv, int *array);
int is_sorted(int argc, int *arr);
void parse(int argc, int *arr, t_vault **vault);
t_elem *ft_newelem(int nbr, int index);
void	ft_elemadd_back(t_elem **lst, t_elem *new);
void	ft_elemadd_front(t_elem **lst, t_elem *new);
t_elem 	*ft_elemlast(t_elem *lst);
void quick_sort(int *numbers, int size);
void swap(t_stack *stack);
void push(t_stack *from, t_stack *to);
void rotate(t_stack *stack);
void reverse_rotate(t_stack *stack);
void get_indexes(int argc, int *array, int *indexes);

#endif
