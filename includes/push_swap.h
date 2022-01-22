/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfranke <dfranke@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 21:33:11 by dfranke           #+#    #+#             */
/*   Updated: 2022/01/22 01:29:42 by dfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

# define STD 0
# define REV 1
# define MIN 0
# define MAX 1
# define A 0
# define B 1
# define RX 0
# define RRX 1
# define PX 2
# define RR 3
# define RRR 4

typedef struct s_node
{
	int				value;
	int				index;
	int				pos;
	struct s_node	*above;
	struct s_node	*below;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		id;
	int		nbrs;
	bool	valid;
	int		t_pos;
	int		chnks;
	int		c_chnk;
	int		rb_count;
	int		trg;
}	t_stack;

void	create_node(t_stack *stack, int nbr);
t_stack	*parse(char **argv, int argc);
bool	duplicates(t_stack *stack);
t_stack	*create_stack(void);
void	free_stack(t_stack *stack);
bool	terminate(int code);

bool	issorted(t_stack *stack_a);
void	positions(t_stack *stack_a);
void	get_min_max(t_stack *stack);
void	get_target(t_stack *stack_a);

void	sx(t_stack *stack);
void	rx(t_stack *stack);
void	rrx(t_stack *stack);
void	px(t_stack *src, t_stack *dst);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);

void	ops_sx(t_stack *stack);
void	ops_rx(t_stack *stack, int op);
void	ops_2(t_stack *stack_src, t_stack *stack_dst, int op);
void	index_a(t_stack *stack_a);

void	alg_manager(t_stack *stack_a, t_stack *stack_b);
void	sort_3(t_stack *stack);
void	sort_10(t_stack *dst, t_stack *hold);
void	sort_100(t_stack *stack_a, t_stack *stack_b);

void	print_stack(t_stack *stack_i);
#endif