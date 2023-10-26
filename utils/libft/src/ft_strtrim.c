/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:11:59 by nprudenc          #+#    #+#             */
/*   Updated: 2023/05/22 14:58:35 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		end;
	int		start;
	int		size;

	if (!s1)
		return (NULL);
	end = ft_strlen(s1);
	start = 0;
	while (ft_strchr(set, s1[start]))
		start++;
	while (ft_strchr(set, s1[end - 1]))
		end--;
	size = end - start;
	if (size <= 0)
		size = 1;
	return (ft_substr(s1, start, size));
}

/*enquanto o retorno do ft_strcchr na posição start for verdadeiro, vamos 
andando ao longo da nossa string, até encontrarmos um caractere diferente
do qual procuramos. Quando isso ocorre entramos no while que vem decrescendo
posições na string, até encontrar um caractere diferente. após isso verificamos
se nosso size é <= 0, para que não aloquemos uma área de memória inválida, para
isso setamos o size = 1, para que tenhamos espaço para colocar o 
caractere nulo*/
