/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfranke <dfranke@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:00:37 by dfranke           #+#    #+#             */
/*   Updated: 2021/05/28 09:59:55 by dfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*thaystack;
	char	*tneedle;
	size_t	i;
	size_t	j;

	thaystack = (char *)haystack;
	tneedle = (char *)needle;
	i = 0;
	if (*tneedle == '\0')
		return (thaystack);
	while (thaystack[i] != '\0' && i < len)
	{
		j = 0;
		while (thaystack[i + j] == tneedle[j] && thaystack[i + j] != '\0'
			&& (i + j) < len)
			j++;
		if (needle[j] == '\0')
			return (&thaystack[i]);
		i++;
	}
	return (NULL);
}
