/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:12:51 by nprudenc          #+#    #+#             */
/*   Updated: 2023/05/15 15:51:37 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*end;
	int		counter;

	counter = ft_strlen(s);
	end = (char *)s + counter;
	if (!s)
		return (NULL);
	if (c == '\0')
		return (end);
	while (end != s)
	{	
		if (*end == (char)c)
			return ((char *)end);
		end--;
	}
	if ((char)c == (char)*end)
		return ((char *)end);
	return (NULL);
}
