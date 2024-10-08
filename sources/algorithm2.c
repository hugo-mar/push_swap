/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 18:19:02 by hugo-mar          #+#    #+#             */
/*   Updated: 2024/07/28 20:33:39 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	b_target_search(t_stack_node *src, t_stack_node *dst)
{
	t_stack_node	*current_dst;
	t_stack_node	*target_node;
	long			best_match;

	while (src)
	{
		best_match = LONG_MIN;
		current_dst = dst;
		while (current_dst)
		{
			if (current_dst->nbr < src->nbr && current_dst->nbr > best_match)
			{
				best_match = current_dst->nbr;
				target_node = current_dst;
			}
			current_dst = current_dst->next;
		}
		if (best_match == LONG_MIN)
			src->target = find_biggest(dst);
		else
			src->target = target_node;
		src = src->next;
	}
}

void	a_target_search(t_stack_node *src, t_stack_node *dst)
{
	t_stack_node	*current_dst;
	t_stack_node	*target_node;
	long			best_match;

	while (src)
	{
		best_match = LONG_MAX;
		current_dst = dst;
		while (current_dst)
		{
			if (current_dst->nbr > src->nbr && current_dst->nbr < best_match)
			{
				best_match = current_dst->nbr;
				target_node = current_dst;
			}
			current_dst = current_dst->next;
		}
		if (best_match == LONG_MAX)
			src->target = find_smallest(dst);
		else
			src->target = target_node;
		src = src->next;
	}
}

void	set_nodes_to_b(t_stack_node **src, t_stack_node **dst)
{
	index_node(src);
	index_node(dst);
	b_target_search(*src, *dst);
	set_cheapest(*src);
}

void	set_nodes_to_a(t_stack_node **src, t_stack_node **dst)
{
	index_node(src);
	index_node(dst);
	a_target_search(*src, *dst);
	set_cheapest(*src);
}
