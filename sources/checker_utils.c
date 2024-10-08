/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:35:33 by hugo-mar          #+#    #+#             */
/*   Updated: 2024/10/08 18:36:20 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	push_no_print(t_stack_node **src, t_stack_node **dst)
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
}

void	swap_both_no_print(t_stack_node **a, t_stack_node **b)
{
	swap(a, 'a', false);
	swap(b, 'b', false);
}

void	rotate_both_no_print(t_stack_node **a, t_stack_node **b)
{
	rotate(a, 'a', false);
	rotate(b, 'b', false);
}

void	rev_rotate_both_no_print(t_stack_node **a, t_stack_node **b)
{
	rev_rotate(a, 'a', false);
	rev_rotate(b, 'b', false);
}
