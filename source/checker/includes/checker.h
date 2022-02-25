#ifndef CHECKER_H
# define CHECKER_H

# include "../../../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_elem
{
	int				number;
	int				index;
	struct s_elem	*next;
	struct s_elem	*prev;
}				t_elem;

typedef struct s_stack
{
	struct s_elem	*head;
	int				size;
}				t_stack;

typedef struct s_vault
{
	struct s_stack	*a;
	struct s_stack	*b;
	int				size;
	int				min;
	int				max;
	int				mid;

}				t_vault;

void	print_func_name(char *funcname, char stackname, int mode);
int		validator(int argc, char **argv, int array[]);
void	checker(t_vault *vault);
int		is_stack_sorted(t_stack *stack);
void	parse(int argc, int *arr, t_vault **vault);
void	do_command(int com_index, t_vault *vault);
void	push(t_stack *from, t_stack *to, char name, int mode);
void	swap(t_stack *stack, char name, int mode);
void	ss(t_stack *stack_a, t_stack *stack_b, int mode);
void	rotate(t_stack *stack, char name, int mode);
void	rr(t_stack *stack_a, t_stack *stack_b, int mode);
void	reverse_rotate(t_stack *stack, char name, int mode);
void	rrr(t_stack *stack_a, t_stack *stack_b, int mode);
int		ft_readline(int fd, char **str);
void	get_indexes(int argc, int *array, int *indexes);
void	quick_sort(int *numbers, int size);
t_elem	*ft_newelem(int nbr, int index, t_elem *prev);
void	ft_elemadd_front(t_elem **lst, t_elem *new);
void	ft_elemadd_back(t_elem **lst, t_elem *new);
t_elem	*ft_elemlast(t_elem *lst);

#endif
