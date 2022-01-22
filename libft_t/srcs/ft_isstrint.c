/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isstrint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfranke <dfranke@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 18:05:01 by dfranke           #+#    #+#             */
/*   Updated: 2022/01/16 19:16:59 by dfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_isstrint(char *str)
{
	if(!ft_isstrnum(str) || (ft_atol(str) < -2147483647 || 2147483647 < ft_atol(str)))
		return (false);
	return (true);
}
