/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:49:57 by abonnefo          #+#    #+#             */
/*   Updated: 2024/01/15 09:34:29 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	key_press(int key, t_data *data)
{
	if (key == KEY_W)
		data->keys.w = 1;
	if (key == KEY_A)
		data->keys.a = 1;
	if (key == KEY_S)
		data->keys.s = 1;
	if (key == KEY_D)
		data->keys.d = 1;
	if (key == KEY_C)
		data->mouse_on = !data->mouse_on;
	if (key == KEY_LEFT)
		data->keys.rot_left = 1;
	if (key == KEY_RIGHT)
		data->keys.rot_right = 1;
	if (key == KEY_ESCAPE)
	{
		free_all(data);
		exit(0);
	}
	return (0);
}

int	key_release(int key, t_data *data)
{
	if (key == KEY_W)
		data->keys.w = 0;
	if (key == KEY_A)
		data->keys.a = 0;
	if (key == KEY_S)
		data->keys.s = 0;
	if (key == KEY_D)
		data->keys.d = 0;
	if (key == KEY_LEFT)
		data->keys.rot_left = 0;
	if (key == KEY_RIGHT)
		data->keys.rot_right = 0;
	return (0);
}
