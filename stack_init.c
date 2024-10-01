/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 21:00:32 by hugo-mar          #+#    #+#             */
/*   Updated: 2024/08/23 17:30:15 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	append_node(t_stack_node **stack, int value)
{
	t_stack_node	*new_node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
		return ;
	new_node->nbr = value;
	new_node->next = NULL;
	if (*stack == NULL)
	{
		new_node->prev = NULL;
		*stack = new_node;
	}
	else if (*stack != NULL)
	{
		last_node = *stack;
		while (last_node->next)
			last_node = last_node->next;
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}

long	ft_atol(char *str)
{
	long	nbr;
	int		parity;

	nbr = 0;
	parity = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			parity++;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nbr = nbr * 10 + (*str - '0');
		str++;
	}
	if (parity % 2 != 0)
		return (-nbr);
	return (nbr);
}

void	create_stack(t_stack_node **a, char **argv)
{
	long	nbr;
	int		i;

	i = 1;
	while (argv[i])
	{
		nbr = ft_atol(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			error_exit(a, argv);
		if (is_duplicate(a, nbr))
			error_exit(a, argv);
		if (!valid_argument(argv[i]))
			error_exit(a, argv);
		append_node(a, (int)nbr);
		i++;
	}
}
