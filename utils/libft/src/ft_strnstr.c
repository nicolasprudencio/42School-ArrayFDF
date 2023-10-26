/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:00:13 by nprudenc          #+#    #+#             */
/*   Updated: 2023/08/11 18:03:54 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int	ft_strncmp(const char *s1, const char *s2, size_t n)
// {
// 	if (!n)
// 		return (0);
// 	while (--n && *s1 && *s1 == *s2)
// 	{
// 		s1++;
// 		s2++;
// 	}
// 	return ((unsigned char) *s1 - (unsigned char) *s2);
// }

// int	ft_strlen(const char *s)
// {
// 	int	i;

// 	i = 0;
// 	while (*s)
// 	{
// 		i++;
// 		s++;
// 	}
// 	return (i);
// }


char	*ft_strnstr(const char *big, const char *little, size_t len)
{	
	size_t	l_size;

	if (!len && !big)
		return (0);
	l_size = ft_strlen(little);
	if (!l_size)
		return ((char *)big);
	while (*big && len-- >= l_size)
	{
		if (ft_strncmp(big, little, l_size) == 0)
			return ((char *)big);
		big++;
	}
	return (NULL);
}
