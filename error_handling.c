/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 21:04:04 by hugo-mar          #+#    #+#             */
/*   Updated: 2024/08/26 12:48:18 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	deallocate_stack(t_stack_node **root)
{
	t_stack_node	*current;
	t_stack_node	*aux;

	current = *root;
	while (current != NULL)
	{
		aux = current;
		current = current->next;
		free(aux);
	}
	*root = NULL;
}

void	error_exit(t_stack_node **a, char **argv)
{
	if (!argv[0][0])
		ft_free(argv);
	deallocate_stack(a);
	write(2, "Error\n", 6);
	exit(1);
}

bool	valid_argument(char *arg)
{
	if (arg == NULL || *arg == '\0')
		return (false);
	if (*arg == '+' || *arg == '-')
		arg++;
	if (!*arg)
		return (false);
	while (*arg)
	{
		if (*arg < '0' || *arg > '9')
			return (false);
		arg++;
	}
	return (true);
}

bool	is_duplicate(t_stack_node **a, int nbr)
{
	t_stack_node	*current;

	current = *a;
	while (current)
	{
		if (current->nbr == nbr)
			return (true);
		current = current->next;
	}
	return (false);
}

bool	stack_sorted(t_stack_node **stack)
{
	t_stack_node	*actual;
	bool			result;

	result = true;
	actual = *stack;
	while (actual->next)
	{
		if (actual->nbr > actual->next->nbr)
			result = false;
		actual = actual->next;
	}
	return (result);
}
