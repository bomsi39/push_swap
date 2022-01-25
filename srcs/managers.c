/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   managers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfranke <dfranke@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 12:16:33 by dfranke           #+#    #+#             */
/*   Updated: 2022/01/25 11:39:50 by dfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	alg_manager(t_stack *stack_a, t_stack *stack_b)
{
	if (!issorted(stack_a) && stack_a->nbrs > 0)
	{
		if (stack_a->nbrs <= 3)
			sort_3(stack_a);
		else if (stack_a->nbrs <= 10)
			sort_10(stack_a, stack_b);
		else if (stack_a->nbrs <= 500)
			sort_100(stack_a, stack_b);
	}
}

/*
Manages three different sorting algorithms,
One for numbers 2-3.
One for numbers 4 - 10.
One for numbers 11 - 500.
*/

void	ops_sx(t_stack *stack)
{
	if (stack->id == A)
	{
		sx(stack);
		ft_putendl_fd("sa", 1);
	}
	if (stack->id == B)
	{
		sx(stack);
		ft_putendl_fd("sb", 1);
	}
}

/*
Holds sx and prints correct operation
*/

void	ops_rx(t_stack *stack, int op)
{
	if (stack->id == A && op == RX)
	{	
		rx(stack);
		ft_putendl_fd("ra", 1);
	}
	else if (stack->id == B && op == RX)
	{	
		rx(stack);
		ft_putendl_fd("rb", 1);
	}
	else if (stack->id == A && op == RRX)
	{	
		rrx(stack);
		ft_putendl_fd("rra", 1);
	}
	else if (stack->id == B && op == RRX)
	{	
		rrx(stack);
		ft_putendl_fd("rrb", 1);
	}
}

/*
Holds rx && rrx and prints correct operation
*/

void	ops_2(t_stack *src, t_stack *dst, int op)
{
	if (dst->id == A && op == PX)
	{	
		px(src, dst);
		ft_putendl_fd("pa", 1);
	}
	else if (dst->id == B && op == PX)
	{	
		px(src, dst);
		ft_putendl_fd("pb", 1);
	}
	else if (op == RR)
	{
		rr(src, dst);
		ft_putendl_fd("rr", 1);
	}
	else if (op == RRR)
	{
		rrr(src, dst);
		ft_putendl_fd("rrr", 1);
	}
}

/*
Holds px, rr & rrr and prints correct operation
*/