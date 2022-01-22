/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfranke <dfranke@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 10:12:12 by dfranke           #+#    #+#             */
/*   Updated: 2021/06/15 12:53:25 by dfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*u;
	char	*tmp;

	u = (char *)s;
	tmp = NULL;
	i = 0;
	while (u[i])
	{
		if (u[i] == c)
			tmp = u + i;
		i++;
	}
	if (u[i] == c)
		tmp = u + i;
	return (tmp);
}
