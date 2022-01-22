/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isstrnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfranke <dfranke@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:12:42 by dfranke           #+#    #+#             */
/*   Updated: 2022/01/21 23:07:19 by dfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_isstrnum(char *str)
{
	int	i;
	int len;

	i = 0;
	len = ft_strlen(str);
	while (ft_isspace(str[i]))
		i++;
		if (len == i)
			return (false);
	while (str[i] == PLUS || str[i] == MINUS)
		i++;
		if (len == i)
			return (false);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}