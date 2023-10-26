/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:25:11 by nprudenc          #+#    #+#             */
/*   Updated: 2023/05/22 11:44:34 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;
	unsigned char		c_char;

	str = (const unsigned char *)s;
	c_char = (unsigned char) c;
	while (n--)
	{
		if (*str == c_char)
			return ((void *)str);
		str++;
	}
	return (NULL);
}
