/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_terminate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfranke <dfranke@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 18:12:56 by dfranke           #+#    #+#             */
/*   Updated: 2022/01/22 17:55:25 by dfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_node	*temp;

	if (stack->top)
	{
		while (stack->top->below)
		{
			temp = stack->top->below;
			free(stack->top);
			stack->top = temp;
		}
	}
	free(stack->top);
	free(stack);
}

bool	terminate(int code)
{
	if (code == ERR)
	{
		ft_putendl_fd("Error", 2);
	}
	return (false);
}

/*
Prints Error on STDERR and returns false to stack->valid
*/