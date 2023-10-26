/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:04:28 by nprudenc          #+#    #+#             */
/*   Updated: 2023/09/15 00:01:19 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2, int free_params)
{
	size_t	s1_len;
	size_t	s2_len;
	int		i;
	int		j;
	char	*str;

	if (!s1)
		return (NULL);
	i = -1;
	j = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2) + 1;
	str = ft_calloc((s1_len + s2_len), sizeof(char));
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	while (s2[j])
		str[i++] = s2[j++];
	if (free_params > 0)
		free(s1);
	if (free_params > 1)
		free(s2);
	return (str);
}
