/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_500.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfranke <dfranke@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 12:59:16 by dfranke           #+#    #+#             */
/*   Updated: 2022/01/23 12:34:27 by dfranke          ###   ########.fr       */
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

/*
While the first index of stack a is smaller than the first index of stack b,
rb is used to push the first element to bottom.
then if the first elemen of stack a is bigger than the first element of stack b,
while the last element of b is smaller than stack_a-> top we use rrx to fill the
missing numbers and get the perfect spot for our number to be pushed to b.
For the last number of the chunk we pull up the missing numbers from bottom if
they exist
*/

void	sort_b(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->c_chnk == 1)
	{
		ops_2(stack_a, stack_b, PX);
		alg_manager(stack_b, stack_a);
	}
	if (stack_a->c_chnk > 1)
		smart_pb(stack_a, stack_b);
}

/*
If the first chunk is handled, the numbers are being pushed to b and sorted
after every push, alg manager decides how to proceed with stack_b.
If the first chunk is completely pushed the sorting happens with smart_pb.
*/

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

/*
push_targets finds at first all targets in get_targets, get_targets searches
the stack from top to bottom and bottom to top simulatniously.
Like in sort_10 we are searching for the position of the target in the stack and
use rb if its in the first half of the stack and rrb if its in the second half of
the stack.
push_targets is recursive, means that if one chunk is pushed completely, the next
chunk will be pushed in the next function call of push_targets, until stack_a is empty
*/

void	sort_100(t_stack *stack_a, t_stack *stack_b)
{
	index_a(stack_a);
	if (stack_a->nbrs <= 60)
		stack_a->chnks = 5;
	else if (stack_a->nbrs <= 100)
		stack_a->chnks = 7;
	else if (stack_a->nbrs <= 500)
		stack_a->chnks = 16;
	stack_a->trg = stack_a->nbrs / stack_a->chnks;
	push_targets(stack_a, stack_b);
	sort_10(stack_a, stack_b);
}

/*
sort 100 splits the stack into chunks and passes the indexes of those chunks
to stack_b. Before every push to stack_b, stack_b will be sorted in descending
order. If one chunk is completely pushed to stack_b, the next stack is being
handled.
For different stack sizes different chunk amounts are appropriate.
For 60-100 numbers i experimented with the chunks and figured out that 7
chunks give the best result in my case.
For 100-500 numbers 16 chunks gave the most effective result.
*/