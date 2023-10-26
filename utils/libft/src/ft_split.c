/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:37:55 by nprudenc          #+#    #+#             */
/*   Updated: 2023/09/15 07:17:03 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_cnt(const char *s, char c)
{
	int	words;
	int	control;

	words = 0;
	control = 0;
	while (*s)
	{
		if (*s != c && control == 0)
		{
			control = 1;
			words++;
		}
		else if (*s == c)
			control = 0;
		s++;
	}
	return (words);
}

static char	*ft_strmalloc(char **str, char c)
{	
	int		s_len;
	char	*str_cpy;

	s_len = 0;
	while ((*str)[s_len] == c)
		(*str)++;
	while ((*str)[s_len] != c && (*str)[s_len])
		s_len++;
	str_cpy = malloc((s_len + 1) * sizeof(char));
	if (!str_cpy)
		return (NULL);
	ft_strlcpy(str_cpy, *str, s_len + 1);
	while (**str != c && **str != 0)
		(*str)++;
	return (str_cpy);
}

char	**ft_split(char const *s, char c)
{
	char	**str_arr;
	int		words;
	int		i;

	if (!s)
		return (NULL);
	words = word_cnt(s, c);
	str_arr = malloc((words + 1) * sizeof(char *));
	i = 0;
	if (!str_arr)
		return (NULL);
	while (i < words)
	{	
		str_arr[i] = ft_strmalloc((char **)&s, c);
		i++;
	}
	str_arr[i] = NULL;
	return (str_arr);
}
