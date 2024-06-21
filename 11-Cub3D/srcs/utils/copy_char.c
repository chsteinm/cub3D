/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:43:09 by bfresque          #+#    #+#             */
/*   Updated: 2024/01/16 11:57:47 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*copy_after_space(char *str)
{
	char	*pos;

	str += 2;
	while (*str && *str == ' ')
		str++;
	pos = ft_strdup(str);
	return (pos);
}

char	*copy_from(char *str, char c_start)
{
	char	*pos;
	char	*dest;
	int		size;

	pos = ft_strchr(str, c_start);
	if (pos != NULL)
	{
		size = ft_strlen(pos);
		dest = malloc(sizeof(char) * (size + 1));
		if (!dest)
			return (NULL);
		ft_strcpy(dest, pos);
		return (dest);
	}
	else
		return (NULL);
}
