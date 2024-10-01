/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 18:20:49 by hugo-mar          #+#    #+#             */
/*   Updated: 2024/08/27 16:43:22 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_node(t_stack_node **stack)
{
	t_stack_node	*current;
	int				len;
	int				median;
	int				i;

	current = *stack;
	len = stack_len(stack);
	median = len / 2;
	i = 0;
	while (current)
	{
		current->index = i;
		if (i <= median)
		{
			current->a_med = true;
			current->price = i;
		}
		else
		{
			current->a_med = false;
			current->price = len - i;
		}
		current = current->next;
		i++;
	}
}

static int	calculate_deal_value(t_stack_node *src)
{
	if (src->a_med && src->target->a_med && src->price && src->target->price)
	{
		if (src->price >= src->target->price)
			return (src->price);
		else
			return (src->target->price);
	}
	else if (!src->a_med && !src->target->a_med
		&& src->price && src->target->price)
	{
		if (src->price >= src->target->price)
			return (src->price);
		else
			return (src->target->price);
	}
	else
		return (src->price + src->target->price);
}

static t_stack_node	*find_best_deal(t_stack_node *src)
{
	t_stack_node	*cheapest;
	int				best_deal;
	int				current_deal;

	cheapest = NULL;
	best_deal = INT_MAX;
	while (src)
	{
		src->cheapest = false;
		src->target->cheapest = false;
		current_deal = calculate_deal_value(src);
		if (current_deal < best_deal)
		{
			best_deal = current_deal;
			cheapest = src;
		}
		src = src->next;
	}
	return (cheapest);
}

void	set_cheapest(t_stack_node *src)
{
	t_stack_node	*cheapest;

	cheapest = find_best_deal(src);
	if (cheapest)
	{
		cheapest->cheapest = true;
		cheapest->target->cheapest = true;
	}
}
