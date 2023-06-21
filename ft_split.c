/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:09:35 by smeixoei          #+#    #+#             */
/*   Updated: 2023/06/20 17:01:05 by smeixoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		if ((s[i] != c) && (s[i + 1] == c || s[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

static int	strchr_pos(char const *s, char c)
{
	char	*ptr;
	int		pos_c;

	ptr = ft_strchr(s, (int)c);
	if (ptr == 0)
		pos_c = ft_strlen(s);
	else
		pos_c = ptr - s;
	return (pos_c);
}

static void	*free_mallocs(char **main_string)
{
	int	i;

	i = 0;
	while (main_string[i] != (void *)0)
	{
		free(main_string[i]);
		i++;
	}
	free(main_string);
	return (NULL);
}

static char	**complete_array(char const *s, char c, char **main_string)
{
	int	pos_c;
	int	i;

	i = 0;
	while (*s != '\0')
	{
		if ((*s == c) && (*s))
			s++;
		else if (*s != c)
		{
			pos_c = strchr_pos(s, c);
			if (pos_c)
			{	
				main_string[i] = ft_substr(s, 0, pos_c);
				if (!main_string[i])
					return (free_mallocs(main_string));
				i++;
				s += pos_c;
			}
			else
				s++;
		}
	}
	main_string[i] = NULL;
	return (main_string);
}

char	**ft_split(char const *s, char c)
{
	char	**main_string;

	if (s == NULL)
		return (NULL);
	main_string = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!main_string)
		return (NULL);
	main_string = complete_array(s, c, main_string);
	return (main_string);
}
