/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:06:53 by hugo-mar          #+#    #+#             */
/*   Updated: 2024/08/27 17:48:05 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					price;
	bool				cheapest;
	bool				a_med;
	struct s_stack_node	*target;
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
}			t_stack_node;

// Stack initiation
char			**ft_split(char const *s, char c);
void			append_node(t_stack_node **stack, int value);
void			create_stack(t_stack_node **a, char **argv);
long			ft_atol(char *str);

// Handle errors
void			error_exit(t_stack_node **a, char **argv);
bool			valid_argument(char *arg);
bool			is_duplicate(t_stack_node **a, int nbr);

// Stack utils
void			ft_free(char **argv);
void			deallocate_stack(t_stack_node **root);
int				stack_len(t_stack_node **s);
bool			stack_sorted(t_stack_node **stack);
t_stack_node	*find_biggest(t_stack_node *s);
t_stack_node	*find_smallest(t_stack_node *s);
t_stack_node	*find_cheapest(t_stack_node **stack);
int				min_value(t_stack_node **s);
int				max_value(t_stack_node **s);

//***Commands
void			push(t_stack_node **src, t_stack_node **dst, char id);
void			swap(t_stack_node **stack, char id, bool print);
void			rotate(t_stack_node **stack, char id, bool print);
void			rev_rotate(t_stack_node **stack, char id, bool print);
void			swap_both(t_stack_node **a, t_stack_node **b);
void			rotate_both(t_stack_node **a, t_stack_node **b);
void			rev_rotate_both(t_stack_node **a, t_stack_node **b);

//***Algorithm
void			index_node(t_stack_node **stack);
void			set_cheapest(t_stack_node *src);
void			b_target_search(t_stack_node *src, t_stack_node *dst);
void			a_target_search(t_stack_node *src, t_stack_node *dst);
void			set_nodes_to_b(t_stack_node **src, t_stack_node **dst);
void			set_nodes_to_a(t_stack_node **src, t_stack_node **dst);
void			tiny_sort(t_stack_node **stack);
void			send_to_b(t_stack_node **a, t_stack_node **b);
void			send_to_a(t_stack_node **b, t_stack_node **a);
void			turk_sort(t_stack_node **a,	t_stack_node **b);

#endif