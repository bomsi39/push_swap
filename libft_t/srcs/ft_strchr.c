/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfranke <dfranke@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 16:26:56 by dfranke           #+#    #+#             */
/*   Updated: 2021/05/27 14:13:49 by dfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*sv;

	i = 0;
	sv = (char *)s;
	while (sv[i] != '\0')
	{
		if (sv[i] == c)
			return (sv + i);
		i++;
	}
	if (sv[i] == c)
		return (sv + i);
	return (NULL);
}
