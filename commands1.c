/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 20:30:48 by hugo-mar          #+#    #+#             */
/*   Updated: 2024/07/28 20:33:24 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack_node **src, t_stack_node **dst, char id)
{
	t_stack_node	*tmp;

	if (!src || !*src)
		return ;
	tmp = (*src)->next;
	if (!*dst)
	{
		*dst = *src;
		(*dst)->next = NULL;
	}
	else
	{
		(*src)->next = *dst;
		(*dst)->prev = *src;
		*dst = *src;
	}
	if (tmp)
		tmp->prev = NULL;
	*src = tmp;
	if (id == 'a')
		write(1, "pa\n", 3);
	else if (id == 'b')
		write(1, "pb\n", 3);
}

void	swap(t_stack_node **stack, char id, bool print)
{
	t_stack_node	*first;
	t_stack_node	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	second->prev = first->prev;
	first->prev = second;
	if (first->next)
		first->next->prev = first;
	*stack = second;
	if (print)
	{
		if (id == 'a')
			write(1, "sa\n", 3);
		else if (id == 'b')
			write(1, "sb\n", 3);
	}
}

void	rotate(t_stack_node **stack, char id, bool print)
{
	t_stack_node	*first;
	t_stack_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
	first->prev = last;
	*stack = first->next;
	first->next->prev = NULL;
	first->next = NULL;
	if (print)
	{
		if (id == 'a')
			write(1, "ra\n", 3);
		else if (id == 'b')
			write(1, "rb\n", 3);
	}
}

void	rev_rotate(t_stack_node **stack, char id, bool print)
{
	t_stack_node	*first;
	t_stack_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	last->prev->next = NULL;
	last->next = first;
	last->prev = NULL;
	first->prev = last;
	*stack = last;
	if (print)
	{
		if (id == 'a')
			write(1, "rra\n", 4);
		else if (id == 'b')
			write(1, "rrb\n", 4);
	}
}
