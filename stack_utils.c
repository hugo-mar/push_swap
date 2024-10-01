/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 21:15:17 by hugo-mar          #+#    #+#             */
/*   Updated: 2024/07/28 21:36:45 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_stack_node **s)
{
	t_stack_node	*actual;
	int				n;

	n = 0;
	actual = *s;
	while (actual)
	{
		n++;
		actual = actual->next;
	}
	return (n);
}

int	min_value(t_stack_node **s)
{
	t_stack_node	*current;
	int				min;

	current = *s;
	min = INT_MAX;
	while (current)
	{
		if (current->nbr < min)
			min = current->nbr;
		current = current->next;
	}
	return (min);
}

int	max_value(t_stack_node **s)
{
	t_stack_node	*current;
	int				max;

	current = *s;
	max = INT_MIN;
	while (current)
	{
		if (current->nbr > max)
			max = current->nbr;
		current = current->next;
	}
	return (max);
}

t_stack_node	*find_biggest(t_stack_node *s)
{
	t_stack_node	*current;

	current = s;
	while (s)
	{
		if (current->nbr < s->nbr)
			current = s;
		s = s->next;
	}
	return (current);
}

t_stack_node	*find_smallest(t_stack_node *s)
{
	t_stack_node	*current;

	current = s;
	while (s)
	{
		if (current->nbr > s->nbr)
			current = s;
		s = s->next;
	}
	return (current);
}
