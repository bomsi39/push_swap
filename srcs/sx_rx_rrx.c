/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sx_rx_rrx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfranke <dfranke@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:18:52 by dfranke           #+#    #+#             */
/*   Updated: 2022/01/21 23:27:54 by dfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sx(t_stack *stack)
{
	t_node	*fir;
	t_node	*sec;

	fir = stack->top;
	sec = stack->top->below;
	if (sec)
	{
		fir->below = sec->below;
		sec->below = fir;
		fir->above = sec;
		sec->above = NULL;
		stack->top = sec;
		if (sec == stack->bottom)
			stack->bottom = fir;
		else
			fir->below->above = fir;
	}
}

/* Comment */

void	rx(t_stack *stack)
{
	t_node	*fir;
	t_node	*lst;

	fir = stack->top;
	lst = stack->bottom;
	if (fir != lst)
	{
		fir->above = lst;
		lst->below = fir;
		fir->below->above = NULL;
		stack->top = fir->below;
		fir->below = NULL;
		stack->bottom = fir;
	}
}

/* Comment */

void	rrx(t_stack *stack)
{
	t_node	*fir;
	t_node	*lst;

	fir = stack->top;
	lst = stack->bottom;
	if (fir != lst)
	{
		lst->below = fir;
		fir->above = lst;
		lst->above->below = NULL;
		stack->bottom = lst->above;
		lst->above = NULL;
		stack->top = lst;
	}
}

/* Comment */

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	rx(stack_a);
	rx(stack_b);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rrx(stack_a);
	rrx(stack_b);
}
