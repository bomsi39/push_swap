/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfranke <dfranke@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 18:50:27 by dfranke           #+#    #+#             */
/*   Updated: 2022/01/22 18:14:45 by dfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_node(t_stack *dst, t_node *node)
{
	t_node	*first;

	if (dst)
	{
		if (!dst->top)
		{
			dst->top = node;
			dst->bottom = node;
		}
		else
		{
			first = dst->top;
			node->below = first;
			first->above = node;
			dst->top = node;
		}
		dst->nbrs += 1;
	}
}

t_node	*pop_node(t_stack *src)
{
	t_node	*node;

	node = NULL;
	if (src->top && src)
	{
		if (src->top == src->bottom)
		{
			node = src->top;
			src->top = NULL;
			node->above = NULL;
			node->below = NULL;
			src->bottom = NULL;
		}
		else
		{
			node = src->top;
			src->top = src->top->below;
			node->above = NULL;
			node->below = NULL;
			src->top->above = NULL;
		}
		src->nbrs -= 1;
	}
	return (node);
}

void	px(t_stack *src, t_stack *dst)
{	
	t_node	*pop;

	if (src->nbrs != 0)
	{
		pop = pop_node(src);
		push_node(dst, pop);
	}
	else
		src->trg = 0;
}

/*
If source stack is not empty, first node will popped and pushed to the top
of dst stack.
*/