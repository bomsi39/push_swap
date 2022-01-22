/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfranke <dfranke@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:53:49 by dfranke           #+#    #+#             */
/*   Updated: 2022/01/21 23:32:25 by dfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h" 

void	use_op(t_stack *stack_a, t_stack *stack_b, char *name)
{
	if (!ft_strcmp(name, "sa\n"))
		sx(stack_a);
	else if (!ft_strcmp(name, "sb\n"))
		sx(stack_b);
	else if (!ft_strcmp(name, "ra\n"))
		rx(stack_a);
	else if (!ft_strcmp(name, "rb\n"))
		rx(stack_b);
	else if (!ft_strcmp(name, "rra\n"))
		rx(stack_a);
	else if (!ft_strcmp(name, "rrb\n"))
		rx(stack_b);
	else if (!ft_strcmp(name, "pa\n"))
		px(stack_b, stack_a);
	else if (!ft_strcmp(name, "pb\n"))
		px(stack_a, stack_b);
	else if (!ft_strcmp(name, "rr\n"))
		rr(stack_a, stack_b);
	else if (!ft_strcmp(name, "rrr\n"))
		rrr(stack_a, stack_b);
}

void	get_ops(t_stack *stack_a, t_stack *stack_b)
{
	char	*op;
	int		i;

	stack_b->id = B;
	op = NULL;
	i = 0;
	while (op || i == 0)
	{
		i = 1;
		op = get_next_line(0);
		use_op(stack_a, stack_b, op);
		if (op[0] == '\n')
			return ;
	}
}

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
			get_ops(stack_a, stack_b);
			print_stack(stack_a);
			if (issorted(stack_a))
				ft_putendl_fd("OK", 1);
			else
				ft_putendl_fd("KO", 1);
			free_stack(stack_b);
		}
		free_stack(stack_a);
	}
	return (0);
}
