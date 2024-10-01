/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 18:10:29 by hugo-mar          #+#    #+#             */
/*   Updated: 2024/08/27 17:48:44 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tiny_sort(t_stack_node **stack)
{
	t_stack_node	*current;
	int				max;

	current = *stack;
	max = max_value(stack);
	if (current->nbr == max)
		rotate(stack, 'a', true);
	else if (current->next->nbr == max)
		rev_rotate(stack, 'a', true);
	current = *stack;
	if (current->nbr > current->next->nbr)
		swap(stack, 'a', true);
}

t_stack_node	*find_cheapest(t_stack_node **stack)
{
	t_stack_node	*cheaper;

	cheaper = *stack;
	while (!cheaper->cheapest)
		cheaper = cheaper->next;
	return (cheaper);
}

void	send_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*w;

	w = find_cheapest(a);
	if (w->price + w->target->price > 0)
	{
		if (w->a_med && w->price && w->target->a_med && w->target->price)
			rotate_both(a, b);
		else if (!w->a_med && w->price && !w->target->a_med && w->target->price)
			rev_rotate_both(a, b);
		else if (w->a_med && !w->price && w->target->a_med && w->target->price)
			rotate(b, 'b', true);
		else if (w->a_med && !w->price && !w->target->a_med && w->target->price)
			rev_rotate(b, 'b', true);
		else if (w->a_med && w->price && w->target->a_med && !w->target->price)
			rotate(a, 'a', true);
		else if (!w->a_med && w->price && w->target->a_med && !w->target->price)
			rev_rotate(a, 'a', true);
		else if (w->a_med && w->price && !w->target->a_med && w->target->price)
			rotate(a, 'a', true);
		else if (!w->a_med && w->price && w->target->a_med && w->target->price)
			rev_rotate(a, 'a', true);
	}
	if (w->price + w->target->price == 0)
		push(a, b, 'b');
}

void	send_to_a(t_stack_node **b, t_stack_node **a)
{
	t_stack_node	*w;

	w = find_cheapest(b);
	if (w->price + w->target->price > 0)
	{
		if (w->a_med && w->price && w->target->a_med && w->target->price)
			rotate_both(b, a);
		else if (!w->a_med && w->price && !w->target->a_med && w->target->price)
			rev_rotate_both(b, a);
		else if (w->a_med && !w->price && w->target->a_med && w->target->price)
			rotate(a, 'a', true);
		else if (w->a_med && !w->price && !w->target->a_med && w->target->price)
			rev_rotate(a, 'a', true);
		else if (w->a_med && w->price && w->target->a_med && !w->target->price)
			rotate(b, 'b', true);
		else if (!w->a_med && w->price && w->target->a_med && !w->target->price)
			rev_rotate(b, 'b', true);
		else if (w->a_med && w->price && !w->target->a_med && w->target->price)
			rotate(b, 'b', true);
		else if (!w->a_med && w->price && w->target->a_med && w->target->price)
			rev_rotate(b, 'b', true);
	}
	if (w->price + w->target->price == 0)
		push(b, a, 'a');
}

void	turk_sort(t_stack_node **a,	t_stack_node **b)
{
	if (stack_len(a) > 3)
		push(a, b, 'b');
	if (stack_len(a) > 3)
		push(a, b, 'b');
	while (stack_len(a) > 3)
	{
		set_nodes_to_b (a, b);
		send_to_b (a, b);
	}
	tiny_sort(a);
	while (stack_len(b))
	{
		set_nodes_to_a (b, a);
		send_to_a (b, a);
	}
	index_node(a);
	while (*a != find_smallest(*a))
	{
		if (find_smallest(*a)->a_med)
			rotate(a, 'a', true);
		else
			rev_rotate(a, 'a', true);
	}
}
