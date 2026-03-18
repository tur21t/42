/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 00:06:02 by dmtur             #+#    #+#             */
/*   Updated: 2026/01/07 15:16:48 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

/* parse */
int		*parse_arguments(int argc, char **argv, int *out_count);
int		validate_integer_string(const char *s);
char	**split_arguments(const char *arg_string, int *out_count);
char	**split_arguments_from_argv(char **argv, int argc, int *out_count);
int		validate_number_tokens(char **tokens, int count);
int		*convert_tokens_to_int_array(char **tokens, int count);
void	free_tokens(char **tokens);

/* stack */
void	stack_init_from_array(t_stack *stack, int *arr, int len);
void	push_node(t_stack *stack, t_node *node);
t_node	*pop_node(t_stack *stack);
t_node	*stack_last_node(t_stack *stack);
int		pop_node_value(t_stack *stack, int *out_value);
void	free_stack(t_stack *stack);
int		stack_min_value(t_stack *stack);
int		stack_find_position(t_stack *stack, int value);

/* operations */
void	operation_sa(t_stack *a);
void	operation_sb(t_stack *b);
void	operation_ss(t_stack *a, t_stack *b);
void	operation_pa(t_stack *a, t_stack *b);
void	operation_pb(t_stack *a, t_stack *b);
void	operation_ra(t_stack *a);
void	operation_rb(t_stack *b);
void	operation_rr(t_stack *a, t_stack *b);
void	operation_rra(t_stack *a);
void	operation_rrb(t_stack *b);
void	operation_rrr(t_stack *a, t_stack *b);

/* sort */
void	sort_small(t_stack *a, t_stack *b);
void	sort_big(t_stack *a, t_stack *b);
void	sort_dispatcher(t_stack *a, t_stack *b);
void	assign_indexes(t_stack *stack);

/* utils */
void	print_error_and_exit(void);
int		is_sorted_ascending(t_stack *stack);

#endif
