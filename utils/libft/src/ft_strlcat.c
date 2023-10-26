/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:08:41 by nprudenc          #+#    #+#             */
/*   Updated: 2023/05/23 13:12:48 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_size;
	size_t	dst_size;
	size_t	i;

	if ((!dst || !src) && !size)
		return (0);
	src_size = ft_strlen(src);
	dst_size = ft_strlen(dst);
	i = 0;
	if ((!src || !dst) && size == 0)
		return (0);
	if (dst_size >= size)
		return (src_size + size);
	if (size > 0)
	{
		while (src[i] && i < size - dst_size - 1)
		{
			dst[dst_size + i] = src[i];
			i++;
		}
	}
	dst[dst_size + i] = '\0';
	return (src_size + dst_size);
}
