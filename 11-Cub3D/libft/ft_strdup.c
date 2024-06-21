/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:54:36 by abonnefo          #+#    #+#             */
/*   Updated: 2023/11/27 12:22:52 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Cette fonction permet de dupliquer une chaîne de caractères

#include "../includes/libft.h"

char	*ft_strdup(char *s)
{
	char	*dest;
	int		i;

	i = 0;
	dest = malloc(sizeof(*dest) * (ft_strlen(s) + 1));
	if (dest == 0)
		return (NULL);
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
