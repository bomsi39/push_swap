/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfranke <dfranke@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:00:06 by dfranke           #+#    #+#             */
/*   Updated: 2022/01/23 12:30:12 by dfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (2 <= argc)
	{
		stack_a = parse(argv, argc);
		if (stack_a->valid)
		{
			stack_b = create_stack();
			alg_manager(stack_a, stack_b);
			free_stack(stack_b);
		}
		free_stack(stack_a);
	}
	return (0);
}

/*
Push_swap reads the given arguments, checks their validation & adds them
in parse to stack_a. 
If the input is valid, an empty stack_b will be created.
A suitable algorithm for the given stack lengh will be determined and
executed in alg_manager.
Stacks will be freed.
*/
