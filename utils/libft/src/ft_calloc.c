/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:06:59 by nprudenc          #+#    #+#             */
/*   Updated: 2023/05/24 19:34:30 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*str;
	size_t	size_max;
	size_t	i;

	i = 0;
	size_max = nmemb * size;
	if (size_max && size_max / size != nmemb)
		return (NULL);
	str = malloc(size_max);
	if (!str)
		return (NULL);
	while (i < size_max)
		str[i++] = 0;
	return (str);
}
