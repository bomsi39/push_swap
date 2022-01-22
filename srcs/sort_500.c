/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_500.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfranke <dfranke@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 12:59:16 by dfranke           #+#    #+#             */
/*   Updated: 2022/01/22 01:27:23 by dfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	smart_pb(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->top->index < stack_b->top->index)
	{
		ops_rx(stack_b, RX);
		stack_b->rb_count++;
	}
	if (stack_a->top->index > stack_b->top->index)
	{
		while (stack_a->top->index > stack_b->bottom->index
			&& stack_b->bottom->index != 0)
		{
			ops_rx(stack_b, RRX);
			stack_b->rb_count--;
		}
		ops_2(stack_a, stack_b, PX);
	}
	while (stack_a->trg == stack_b->nbrs && !issorted(stack_b))
	{
		ops_rx(stack_b, RRX);
		stack_b->rb_count--;
	}
}

/* Comment */

void	sort_b(t_stack *stack_a, t_stack *stack_b)
{
	int	half;

	half = stack_b->nbrs / 2;
	if (stack_a->c_chnk == 1)
	{
		ops_2(stack_a, stack_b, PX);
		sort_10(stack_b, stack_a);
	}
	if (stack_a->c_chnk > 1)
	{
		smart_pb(stack_a, stack_b);
	}
}

/* Comment */

void	push_targets(t_stack *stack_a, t_stack *stack_b)
{
	int		half;

	stack_a->c_chnk += 1;
	while (stack_b->nbrs < stack_a->trg && stack_a->c_chnk < stack_a->chnks)
	{
		get_target(stack_a);
		half = stack_a->nbrs / 2;
		if (stack_a->t_pos <= half && 0 < stack_a->t_pos)
		{
			while (1 < stack_a->t_pos--)
				ops_rx(stack_a, RX);
		}
		else if (stack_a->t_pos > half && 0 < stack_a->t_pos)
		{
			while (stack_a->t_pos++ <= stack_a->nbrs)
				ops_rx(stack_a, RRX);
		}
		sort_b(stack_a, stack_b);
	}
	if (stack_b->nbrs == stack_a->trg && stack_a->c_chnk < stack_a->chnks)
	{
		stack_a->trg += (stack_a->nbrs + stack_b->nbrs) / stack_a->chnks;
		push_targets(stack_a, stack_b);
	}
}

/* IDEAS SET NEW  VAR IN STRUCT STACK->AB = 
A OR B THEN CHANGE ALL FUNCTIONS TO REVERSE AND NORMAL IN 1 */

void	sort_100(t_stack *stack_a, t_stack *stack_b)
{
	index_a(stack_a);
	if (stack_a->nbrs <= 60)
		stack_a->chnks = 4;
	else if (stack_a->nbrs <= 100)
		stack_a->chnks = 8;
	else if (stack_a->nbrs <= 500)
		stack_a->chnks = 16;
	stack_a->trg = stack_a->nbrs / stack_a->chnks;
	push_targets(stack_a, stack_b);
	sort_10(stack_a, stack_b);
	while (0 < stack_b->nbrs)
		ops_2(stack_b, stack_a, PX);
}

/* // 8 = 814 Operations // 9 = 815 Ops // 14 = 7968 // 15 = 7863 
// 16 = 7854 // 17 = 7920 // 18 = 8013 // 19 = 8040 // 20 = 8030 */