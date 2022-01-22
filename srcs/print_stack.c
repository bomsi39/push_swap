/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfranke <dfranke@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:45:24 by dfranke           #+#    #+#             */
/*   Updated: 2022/01/21 14:49:49 by dfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"

void	print_stack(t_stack *stack)
{
	t_node	*print;

	print = stack->top;
	if (stack->top)
	{
		while (print->below)
		{
			printf("%d\n", print->value);
			print = print->below;
		}
		printf("%d\nNumbers: %d\n", stack->bottom->value, stack->nbrs);
	}
}
