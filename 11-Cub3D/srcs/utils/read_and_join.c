/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_join.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:20:44 by abonnefo          #+#    #+#             */
/*   Updated: 2023/12/22 11:21:03 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*err_empty_file(char *s1)
{
	err("Error\nThe file is empty\n");
	free(s1);
	return (NULL);
}

int	open_file(char *map)
{
	int	fd;

	fd = open(map, O_RDWR);
	if (fd < 0)
		err("Error\nInvalid read\n");
	return (fd);
}

char	*ft_read_and_join(char *map)
{
	char	*s1;
	char	*s2;
	char	*temp;
	int		fd;

	fd = open_file(map);
	if (fd < 0)
		return (NULL);
	s1 = ft_calloc(sizeof(char), 1);
	if (s1 == NULL)
		return (NULL);
	s2 = get_next_line(fd);
	if (!s2)
		return (err_empty_file(s1));
	while (s2)
	{
		temp = s1;
		s1 = ft_strjoin(temp, s2);
		free(temp);
		free(s2);
		s2 = get_next_line(fd);
	}
	close(fd);
	return (s1);
}
