/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gridlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 22:26:31 by nprudenc          #+#    #+#             */
/*   Updated: 2023/09/18 14:21:30 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_gridlen(char **grid)
{	
	int	i;

	if (!grid)
		return (0);
	i = -1;
	while (grid[++i])
		;
	return (i);
}
// change the name to gridlen