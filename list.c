#include "push_swap.h"

t_elem *ft_newelem(int nbr, int index)
{
	t_elem *elem;

	elem = (t_elem *) malloc(sizeof(t_elem));
	if (!elem)
		return (NULL);
	elem->number = nbr;
	elem->index = index;
	elem->prev = NULL;
	elem->next = NULL;
	return (elem);
}

void	ft_elemadd_front(t_elem **lst, t_elem *new)
{
	new->next = (*lst);
	new->prev = NULL;
	if (*lst)
		(*lst)->prev = new;
	(*lst) = new;
}

void	ft_elemadd_back(t_elem **lst, t_elem *new)
{
	t_elem 	*elem;

	elem = NULL;
	if (lst && new)
	{
		if (!(*lst))
			*lst = new;
		else
		{
			elem = ft_elemlast(*lst);
			elem->next = new;
			elem->next->prev = elem;
		}
	}
}

t_elem 	*ft_elemlast(t_elem *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}