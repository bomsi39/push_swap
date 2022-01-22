/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfranke <dfranke@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 16:47:49 by dfranke           #+#    #+#             */
/*   Updated: 2022/01/14 01:01:55 by dfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	strcount(char const *s, char c)
{
	int		i;
	int		j;
	int		string;

	i = 0;
	j = 0;
	string = 0;
	while (s[j] != '\0')
	{
		if (s[j] != c && string == 0)
		{
			string = 1;
			i++;
		}
		else if (s[j] == c)
			string = 0;
		j++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		start;
	size_t	i[2];

	if (!s)
		return (NULL);
	array = malloc((strcount(s, c) + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	i[0] = 0;
	i[1] = 0;
	start = -1;
	while (i[0] <= ft_strlen(s))
	{
		if (start < 0 && s[i[0]] != c)
			start = i[0];
		else if ((s[i[0]] == c || i[0] == ft_strlen(s)) && 0 <= start)
		{
			array[i[1]++] = ft_substr(s, start, i[0] - start);
			start = -1;
		}
		i[0]++;
	}
	array[i[1]] = 0;
	return (array);
}
