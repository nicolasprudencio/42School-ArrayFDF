/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 20:37:46 by nprudenc          #+#    #+#             */
/*   Updated: 2023/05/20 17:56:33 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		counter;
	int		i;
	char	*str;

	counter = ft_strlen(s) + 1;
	str = malloc(counter * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

// char	*ft_strdup(const char *src)
// {
// 	char	*dest;
// 	int		len;
// 	int		i;

// 	i = 0;
// 	len = ft_strlen(src);
// 	dest = malloc((len + 1) * sizeof(char));
// 	if (!dest)
// 		return (NULL);
// 	while (src[i])
// 	{
// 		dest[i] = src[i];
// 		i++;
// 	}
// 	dest[i] = '\0';
// 	return (dest);
// }
