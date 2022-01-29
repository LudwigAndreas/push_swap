#include "push_swap.h"

void swap(t_stack *stack)
{
	t_elem *first;
	t_elem *second;

	first = stack->head;
	second = first->next;
	first->next = second->next;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	stack->head = second;
}

void push(t_stack *from, t_stack *to)
{
	t_elem *temp;

	temp = from->head->next;
	ft_elemadd_front(&(to->head), from->head);
	temp->prev = NULL;
	from->head = temp;
}

void rotate(t_stack *stack)
{
	t_elem *first;
	t_elem *last;


	first = stack->head;
	last = ft_elemlast(first);
	last->next = first;
	stack->head = first->next;
	first->next = NULL;
	first->prev = last;
	stack->head->prev = NULL;
}

void reverse_rotate(t_stack *stack)
{
	t_elem *first;
	t_elem *last;


	first = stack->head;
	last = ft_elemlast(first);
	first->prev = last;
	last->prev->next = NULL;
	last->next = first;
	last->prev = NULL;
	stack->head = last;
}


//TODO сделать операторы
/*
 * 2 - 1
 * 3 - 2
 * 5 - 3
 * 7 - 4
 * 1 - 0
 */