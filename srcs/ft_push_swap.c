/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfranke <dfranke@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:00:06 by dfranke           #+#    #+#             */
/*   Updated: 2022/01/21 14:48:22 by dfranke          ###   ########.fr       */
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

/* Comment */