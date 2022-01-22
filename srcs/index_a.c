/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfranke <dfranke@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 10:19:27 by dfranke           #+#    #+#             */
/*   Updated: 2022/01/21 14:28:32 by dfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_s(t_node *node, t_node *node2)
{
	int	tmp;

	tmp = node->value;
	node->value = node2->value;
	node2->value = tmp;
}

/* Comment */

void	sort_s(t_stack *stack_i)
{
	t_node	*start;
	t_node	*node;
	t_node	*min;

	start = stack_i->top;
	node = NULL;
	min = NULL;
	while (start->below)
	{
		min = start;
		node = start->below;
		while (node)
		{
			if (min->value > node->value)
				min = node;
			node = node->below;
		}
		swap_s(start, min);
		start = start->below;
	}
	positions(stack_i);
}

/* Comment */

void	pass_index(t_stack *stack_a, t_stack *stack_i)
{
	t_node	*node_a;
	t_node	*node_i;
	int		i;
	int		j;

	i = 0;
	node_a = stack_a->top;
	while (i < stack_a->nbrs)
	{
		node_i = stack_i->top;
		j = 0;
		while (j < stack_i->nbrs)
		{
			if (node_a->value == node_i->value)
				node_a->index = node_i->pos - 1;
			node_i = node_i->below;
			j++;
		}
		node_a = node_a->below;
		i++;
	}
}

/* Comment */

void	copy_stack(t_stack *src, t_stack *dst)
{
	t_node	*node;

	node = src->top;
	create_node(dst, node->value);
	while (node->below)
	{
		node = node->below;
		create_node(dst, node->value);
	}
}

/* Comment */

void	index_a(t_stack *stack)
{
	t_stack	*stack_i;

	stack_i = create_stack();
	copy_stack(stack, stack_i);
	sort_s(stack_i);
	pass_index(stack, stack_i);
	free_stack(stack_i);
}

/* Comment */