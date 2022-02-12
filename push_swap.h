#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>

typedef struct	s_elem
{
	int				number;
	int				index;
	struct s_elem	*next;
	struct s_elem	*prev;
}				t_elem;

typedef struct	s_stack
{
	struct s_elem	*head;
	int				size;
}				t_stack;

typedef struct	s_vault
{
	struct s_stack	*a;
	struct s_stack	*b;
	int				size;
	int				min;
	int				max;
	int 			mid;

}				t_vault;

void	print_data(t_vault *vault, char *name);
int		is_stack_sorted(t_stack *stack);
void	sort(t_vault *vault, int *array);
void	divide_a(t_vault *vault, int *array);
int		*largest_seq_len(int *array, int size, int *ret_len);
int		validator(int argc, char **argv, int *array);
int		is_sorted(int argc, int *arr);
int		*parse(int argc, int *arr, t_vault **vault);
t_elem	*ft_newelem(int nbr, int index);
void	ft_elemadd_back(t_elem **lst, t_elem *new);
void	ft_elemadd_front(t_elem **lst, t_elem *new);
t_elem	*ft_elemlast(t_elem *lst);
void	quick_sort(int *numbers, int size);
void	swap(t_stack *stack, char *name, int mode);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	push(t_stack *from, t_stack *to, char *name, int mode);
void	rotate(t_stack *stack, char *name, int mode);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	reverse_rotate(t_stack *stack, char *name, int mode);
void	rrr(t_stack *stack_a, t_stack *stack_b);
void	get_indexes(int argc, int *array, int *indexes);

#endif
