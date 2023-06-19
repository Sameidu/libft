/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:09:35 by smeixoei          #+#    #+#             */
/*   Updated: 2023/06/19 16:27:19 by smeixoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_words(const char *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (((s[i] != c) && (s[i + 1] == c)) || s[i + 1] == '\0')
			count++;
		i++;
	}
	return (count);
}

char	**ft_fill_array(char **aux, char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		k;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		j = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (s[j] == '\0')
			return (aux);
		else
		{
			aux[k++] = ft_substr(s, j, i - j);
			if (!aux[k])
				ft_free_array();
		}
	}
	return (aux);
}

char	**ft_split(char const *s, char c)
{
	char	**aux;
	int		nwords;

	if (!s)
		return (NULL);
	nwords = ft_count_words(s, c);
	aux = ft_calloc((nwords + 1), sizeof(char *));
	if (!aux)
		return (NULL);
	aux = ft_fill_array(aux, s, c);
	return (aux);
}
