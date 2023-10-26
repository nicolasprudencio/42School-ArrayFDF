/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:29:32 by nicolas           #+#    #+#             */
/*   Updated: 2023/05/22 15:09:44 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_digits_amount(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i = 1;
	else
	{
		while (n)
		{
			n /= 10;
			i++;
		}
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			n_size;
	long int	nb;

	n_size = get_digits_amount(n);
	nb = n;
	if (nb < 0)
	{
		nb *= -1;
		n_size++;
	}
	str = malloc((n_size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[n_size] = '\0';
	while (n_size--)
	{
		str[n_size] = '0' + nb % 10;
		nb /= 10;
	}
	if (n < 0)
		*str = '-';
	return (str);
}
