/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 19:59:36 by jmatute-          #+#    #+#             */
/*   Updated: 2022/04/06 21:07:07 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	up(int key, t_data *data)
{
	int	aux;

	if (crash(key, data))
		return (0);
	else
	{
		aux = data->y;
		data->y = data->y - 1;
		if (data->matrix_map[data->y][data->x] == 'C')
			mlx_put_image_to_window(data->mlx, data->win, \
			data->floor, data->x * 32, data->y * 32);
		if (data->matrix_map[aux][data->x] == 'E')
			mlx_put_image_to_window(data->mlx, data->win, \
			data->exit, data->x * 32, aux * 32);
		else
			mlx_put_image_to_window(data->mlx, data->win, \
			data->floor, data->x * 32, aux * 32);
		mlx_put_image_to_window(data->mlx, data->win, \
		data->up, data->x * 32, data->y * 32);
	}
	return (0);
}

int	down(int key, t_data *data)
{
	int	aux;

	if (crash(key, data))
		return (0);
	else
	{
		aux = data->y;
		data->y = data->y + 1;
		if (data->matrix_map[data->y][data->x] == 'C')
			mlx_put_image_to_window(data->mlx, data->win, \
			data->floor, data->x * 32, data->y * 32);
		if (data->matrix_map[aux][data->x] == 'E')
			mlx_put_image_to_window(data->mlx, data->win, \
			data->exit, data->x * 32, aux * 32);
		else
			mlx_put_image_to_window(data->mlx, data->win, \
			data->floor, data->x * 32, aux * 32);
		mlx_put_image_to_window(data->mlx, data->win, \
		data->down, data->x * 32, data->y * 32);
	}
	return (0);
}

int	right(int key, t_data *data)
{
	int	aux;

	if (crash(key, data))
		return (0);
	else
	{
		aux = data->x;
		data->x = data->x + 1;
		if (data->matrix_map[data->y][data->x] == 'C')
			mlx_put_image_to_window(data->mlx, data->win, \
			data->floor, data->x * 32, data->y * 32);
		if (data->matrix_map[data->y][aux] == 'E')
			mlx_put_image_to_window(data->mlx, data->win, \
			data->exit, aux * 32, data->y * 32);
		else
			mlx_put_image_to_window(data->mlx, data->win, \
			data->floor, aux * 32, data->y * 32);
		mlx_put_image_to_window(data->mlx, data->win, \
		data->right, data->x * 32, data->y * 32);
	}
	return (0);
}

int	left(int key, t_data *data)
{
	int	aux;

	if (crash(key, data))
		return (0);
	else
	{
		aux = data->x;
		data->x = data->x - 1;
		if (data->matrix_map[data->y][data->x] == 'C')
			mlx_put_image_to_window(data->mlx, data->win, \
			data->floor, data->x * 32, data->y * 32);
		if (data->matrix_map[data->y][aux] == 'E')
			mlx_put_image_to_window(data->mlx, data->win, \
			data->exit, aux * 32, data->y * 32);
		else
			mlx_put_image_to_window(data->mlx, data->win, \
			data->floor, aux * 32, data->y * 32);
		mlx_put_image_to_window(data->mlx, data->win, \
		data->left, data->x * 32, data->y * 32);
	}
	return (0);
}
