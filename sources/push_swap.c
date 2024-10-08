/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:07:36 by hugo-mar          #+#    #+#             */
/*   Updated: 2024/08/27 18:04:26 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	if (argv == NULL)
		return (1);
	create_stack(&a, argv);
	if (!stack_sorted(&a))
	{
		if (stack_len(&a) == 2)
			swap(&a, 'a', true);
		if (stack_len(&a) == 3)
			tiny_sort(&a);
		if (stack_len(&a) > 3)
			turk_sort(&a, &b);
	}
	if (argc == 2)
		ft_free(argv);
	deallocate_stack(&a);
	return (0);
}
