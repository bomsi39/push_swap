/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_10.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfranke <dfranke@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 11:54:00 by dfranke           #+#    #+#             */
/*   Updated: 2022/01/22 18:29:08 by dfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_10(t_stack *dst, t_stack *hold)
{
	int	half;
	int	h_num;

	h_num = hold->nbrs;
	while (3 < dst->nbrs && !issorted(dst))
	{
		get_min_max(dst);
		half = dst->nbrs / 2;
		if (dst->t_pos <= half)
		{
			while (1 < dst->t_pos--)
				ops_rx(dst, RX);
		}
		else
			while (dst->t_pos++ <= dst->nbrs)
				ops_rx(dst, RRX);
		if (!issorted(dst))
			ops_2(dst, hold, PX);
	}
	sort_3(dst);
	while (h_num < hold->nbrs || (issorted(hold) && 0 < hold->nbrs))
		ops_2(hold, dst, PX);
}

/*
sort_10 sorts stacks with up to 10 nodes.
For stack_a at first the smallest value needs to be found by get_min_max.
If the position of this number is in the first half of the stack, i use rx
to bring the number to the top of the stack.
If the position of this number is in the second half of the stack, i use rrx
to bring the number to the bottom and then the top of the stack.
This way is save operations.
If the smallest value is on top of the stack, i push it to the hold stack, who
collects the smallest values in the descending order.
If stack_a is sorted correctly, pa is used to push the collected numbers back
to the stack_a.
For stack_b the same function does the same in the inverted order. This will be
used by the sort_500 functions.
*/

void	sort_3(t_stack *stack)
{
	t_node	*fir;
	t_node	*sec;
	t_node	*lst;

	while (!issorted(stack))
	{
		fir = stack->top;
		sec = stack->top->below;
		lst = stack->bottom;
		if (stack->id == A && (fir->value < lst->value
				|| (fir->value > sec->value && sec->value > lst->value)))
			ops_sx(stack);
		else if (stack->id == B && (fir->value > lst->value
				|| (fir->value < sec->value && sec->value < lst->value)))
			ops_sx(stack);
		else if (stack->id == A && lst->value < sec->value)
			ops_rx(stack, RRX);
		else if (stack->id == B && fir->value > sec->value)
			ops_rx(stack, RRX);
		else if (stack->id == A && fir->value > sec->value)
			ops_rx(stack, RX);
		else if (stack->id == B && fir->value < sec->value)
			ops_rx(stack, RX);
	}
}

/*
sort_3 sorts stacks with 2-3 nodes. 
For stack_a the nodes will be sorted from lowest value at top to
highest at bottom.
For stack_b the nodes will be sorted in reverse from highest value at top to
lowest at bottom.
*/