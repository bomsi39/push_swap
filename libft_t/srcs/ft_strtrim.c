/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfranke <dfranke@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:39:22 by dfranke           #+#    #+#             */
/*   Updated: 2021/06/15 11:22:33 by dfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	tlen;
	char	*trim;

	if (!s1 || !set)
		return (NULL);
	while (ft_strchr(set, *s1) && *s1)
		s1++;
	tlen = ft_strlen(s1);
	while (ft_strchr(set, s1[tlen - 1]) && *s1)
		tlen--;
	trim = ft_substr(s1, 0, tlen);
	return (trim);
}
