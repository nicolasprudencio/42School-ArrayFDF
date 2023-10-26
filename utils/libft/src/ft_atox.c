/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:52:54 by nprudenc          #+#    #+#             */
/*   Updated: 2023/10/26 01:19:41 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	ft_isupper(int	c)
{
	if (c >= 65 && c <= 90)
		return (1);
	return (0);
}

unsigned int	ft_atox(char *hex)
{
	unsigned int	nbr;
	int				i;
	int				j;

	if (!hex)
		return (0xffffff);
	i = ft_strlen(hex) - 2;
	j = 2;
	nbr = 0;
	while (hex[j])
	{
		if (ft_isdigit(hex[j]))
			nbr += (hex[j] - 48) * pow(16, i--);
		if (ft_isupper(hex[j]))
			nbr += (hex[j] - 55) * pow(16, i--);
		else
			nbr += (hex[j] - 87) * pow(16, i--);
		j++;
	}
	return (nbr);
}
