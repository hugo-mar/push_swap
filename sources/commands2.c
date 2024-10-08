/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 20:34:37 by hugo-mar          #+#    #+#             */
/*   Updated: 2024/07/28 21:39:57 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_both(t_stack_node **a, t_stack_node **b)
{
	swap(a, 'a', false);
	swap(b, 'b', false);
	write(1, "ss\n", 3);
}

void	rotate_both(t_stack_node **a, t_stack_node **b)
{
	rotate(a, 'a', false);
	rotate(b, 'b', false);
	write(1, "rr\n", 3);
}

void	rev_rotate_both(t_stack_node **a, t_stack_node **b)
{
	rev_rotate(a, 'a', false);
	rev_rotate(b, 'b', false);
	write(1, "rrr\n", 4);
}
