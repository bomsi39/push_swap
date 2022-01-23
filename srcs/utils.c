/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfranke <dfranke@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 10:14:46 by dfranke           #+#    #+#             */
/*   Updated: 2022/01/22 19:43:55 by dfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	duplicates(t_stack *stack)
{
	t_node	*check;
	t_node	*compare;
	int		i;

	i = 0;
	check = stack->top;
	while (i < stack->nbrs && stack)
	{
		compare = check->below;
		while (compare)
		{
			if (check->value == compare->value)
				return (true);
		compare = compare->below;
		}
	check = check->below;
	i++;
	}
	return (false);
}

/*
Checks the stack for duplicates and returns true / false
*/

bool	issorted(t_stack *stack)
{
	t_node	*compare;
	int		i;

	i = 1;
	compare = stack->top;
	while (i < stack->nbrs)
	{
		if (stack->id == A && compare->value > compare->below->value)
			return (false);
		if (stack->id == B && compare->value < compare->below->value)
			return (false);
		compare = compare->below;
		i++;
	}
	if (!stack->top)
		return (false);
	return (true);
}

/*
Checks if the stack is sorted.
For stack a in ascending order.
For stack b in descending order.
*/

void	positions(t_stack *stack)
{
	t_node	*node;
	int		i;

	i = 0;
	node = stack->top;
	while (i < stack->nbrs)
	{
		node->pos = i + 1;
		if (node->below)
			node = node->below;
		i++;
	}
}

/*
Fills node->position with the position of the node in the stack
*/

void	get_min_max(t_stack *stack)
{
	t_node	*node;
	t_node	*min_max;

	node = stack->top;
	min_max = node;
	positions(stack);
	while (node->below)
	{	
		if (stack->id == A && min_max->value > node->below->value)
			min_max = node->below;
		else if (stack->id == B && min_max->value < node->below->value)
			min_max = node->below;
		node = node->below;
	}
	stack->t_pos = min_max->pos;
}

/*
Determines the minimum value of stack_a and gives its position to
stack-t_pos.
For stack_b it determines the maximum of the stack.
*/

void	get_target(t_stack *stack_a)
{
	t_node	*fir;
	t_node	*lst;

	positions(stack_a);
	fir = stack_a->top;
	lst = stack_a->bottom;
	while (fir->below)
	{	
		if (fir->index < stack_a->trg)
		{
			stack_a->t_pos = fir->pos;
			return ;
		}
		else if (lst->index < stack_a->trg)
		{
			stack_a->t_pos = lst->pos;
			return ;
		}
		fir = fir->below;
		lst = lst->above;
	}
}

/*
Determines the targets and give its position to
stack-t_pos.
Searches from top and bottom per loop.
*/