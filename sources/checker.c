/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:09:39 by hugo-mar          #+#    #+#             */
/*   Updated: 2024/10/08 18:36:29 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	invalid_command_exit(t_stack_node **a, t_stack_node **b,
				int argc, char **argv)
{
	if (a)
		deallocate_stack(a);
	if (b)
		deallocate_stack(b);
	if (argc == 2)
		ft_free(argv);
	perror("Invalid command");
	exit(1);
}

static void	run_command(char *cmd, t_command_data *data)
{
	if (!ft_strncmp(cmd, "pa\n", ft_strlen(cmd)))
		push_no_print(data->b, data->a);
	else if (!ft_strncmp(cmd, "pb\n", ft_strlen(cmd)))
		push_no_print(data->a, data->b);
	else if (!ft_strncmp(cmd, "sa\n", ft_strlen(cmd)))
		swap(data->a, 'a', false);
	else if (!ft_strncmp(cmd, "sb\n", ft_strlen(cmd)))
		swap(data->b, 'b', false);
	else if (!ft_strncmp(cmd, "ra\n", ft_strlen(cmd)))
		rotate(data->a, 'a', false);
	else if (!ft_strncmp(cmd, "rb\n", ft_strlen(cmd)))
		rotate(data->b, 'b', false);
	else if (!ft_strncmp(cmd, "rra\n", ft_strlen(cmd)))
		rev_rotate(data->a, 'a', false);
	else if (!ft_strncmp(cmd, "rrb\n", ft_strlen(cmd)))
		rev_rotate(data->b, 'b', false);
	else if (!ft_strncmp(cmd, "ss\n", ft_strlen(cmd)))
		swap_both_no_print(data->a, data->b);
	else if (!ft_strncmp(cmd, "rr\n", ft_strlen(cmd)))
		rotate_both_no_print(data->a, data->b);
	else if (!ft_strncmp(cmd, "rrr\n", ft_strlen(cmd)))
		rev_rotate_both_no_print(data->a, data->b);
	else
		invalid_command_exit(data->a, data->b, data->argc, data->argv);
}

static void	execute_commands(t_stack_node **a, t_stack_node **b,
				char **argv, int argc)
{
	char			*command;
	t_command_data	data;

	data.a = a;
	data.b = b;
	data.argc = argc;
	data.argv = argv;
	command = get_next_line(0);
	while (command)
	{
		run_command(command, &data);
		free(command);
		command = get_next_line(0);
	}
}

static void	finalize(t_stack_node **a, char **argv, int argc, int initial_len)
{
	if (stack_sorted(a) && stack_len(a) == initial_len)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	if (argc == 2)
		ft_free(argv);
	deallocate_stack(a);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	int				len;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	if (argv == NULL)
		return (1);
	create_stack(&a, argv);
	len = stack_len(&a);
	execute_commands(&a, &b, argv, argc);
	finalize(&a, argv, argc, len);
	return (0);
}
