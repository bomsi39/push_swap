/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_10.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfranke <dfranke@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 11:54:00 by dfranke           #+#    #+#             */
/*   Updated: 2022/01/22 01:17:18 by dfranke          ###   ########.fr       */
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
