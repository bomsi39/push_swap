/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfranke <dfranke@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 11:45:59 by dfranke           #+#    #+#             */
/*   Updated: 2022/01/22 18:11:35 by dfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_str(char *argv, t_stack *stack)
{
	int		i;
	char	**nbrs;

	i = 0;
	nbrs = ft_split(argv, SPACE);
	while (nbrs[i])
	{
		if (!ft_isstrint(nbrs[i]))
			stack->valid = terminate(ERR);
		create_node(stack, atol(nbrs[i]));
		free(nbrs[i]);
		i++;
	}
	free(nbrs);
}

/*
Argument will get seperated, checked if they are integers and added to stack
*/

void	parse_nbr(char **argv, t_stack *stack)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!ft_isstrint(argv[i]))
			stack->valid = terminate(ERR);
		create_node(stack, atol(argv[i]));
		i++;
	}
}

/*
Arguments are checked if they are integers and added to stack
*/

t_stack	*parse(char **argv, int argc)
{
	t_stack	*stack;

	stack = create_stack();
	if (!ft_isstrnum(argv[1]) && argc == 2)
		parse_str(argv[1], stack);
	else
		parse_nbr(argv, stack);
	if (duplicates(stack) && stack->valid)
		stack->valid = terminate(ERR);
	return (stack);
}

/*
parse takes arguments, checks them if they are a string "43 23 12" or
an array "43" "23" "12"
If str, parsing is done via parse_str.
If array, parsing is done via parse_nbr.
Finally the created stack will be checked for duplicate numbers.
*/