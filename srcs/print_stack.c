/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfranke <dfranke@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:45:24 by dfranke           #+#    #+#             */
/*   Updated: 2022/01/22 18:13:25 by dfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	t_node	*print;

	print = stack->top;
	if (stack->top)
	{
		while (print->below)
		{
			ft_putendl_fd(ft_itoa(print->value), 1);
			print = print->below;
		}
		ft_putendl_fd(ft_itoa(print->value), 1);
		ft_putstr_fd("Numbers: ", 1);
		ft_putendl_fd(ft_itoa(stack->nbrs), 1);
	}
}

/*
Stack & stack->nbrs is being printed to the STDOUT just for testing purposes
*/