/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_of_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:12:48 by jmatute-          #+#    #+#             */
/*   Updated: 2022/04/06 21:12:05 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_ipoint(char **matrix, char cordinate)
{
	int	c_x;
	int	c_y;

	c_y = 0;
	c_x = 0;
	while (matrix[c_y])
	{
		while (matrix[c_y][c_x])
		{
			if (matrix[c_y][c_x] == 'P')
			{
				if (cordinate == 'x')
					return (c_x);
				else if (cordinate == 'y')
					return (c_y);
			}
			c_x++;
		}
		c_x = 0;
		c_y++;
	}
	return (0);
}

int	end_game(int key, t_data *data)
{
	if (data->n_items == data->full_items)
	{
		if (key == RIGHT && data->matrix_map[data->y][data->x] == 'E')
			data->flag_end = 1;
		else if (key == LEFT && data->matrix_map[data->y][data->x] == 'E')
			data->flag_end = 1;
		else if (key == DOWN && data->matrix_map[data->y][data->x] == 'E')
			data->flag_end = 1;
		else if (key == UP && data->matrix_map[data->y][data->x] == 'E')
			data->flag_end = 1;
		if (data->flag_end == 1)
		{
			mlx_clear_window(data->mlx, data->win);
			mlx_put_image_to_window(data->mlx, data->win, \
			data->end_game, (data->x_win / 2) - 100, (data->y_win / 2) - 100);
			return (1);
		}
	}
	return (0);
}

int	crash(int key, t_data *data)
{
	if (key == RIGHT && data->matrix_map[data->y][data->x + 1] == '1')
		return (1);
	else if (key == LEFT && data->matrix_map[data->y][data->x - 1] == '1')
		return (1);
	else if (key == DOWN && data->matrix_map[data->y + 1][data->x] == '1')
		return (1);
	else if (key == UP && data->matrix_map[data->y - 1][data->x] == '1')
		return (1);
	return (0);
}

int	collect_items(int key, t_data *data)
{
	if (key == RIGHT && data->matrix_map[data->y][data->x] == 'C')
	{
		data->matrix_map[data->y][data->x] = '0';
		return (1);
	}
	if (key == LEFT && data->matrix_map[data->y][data->x] == 'C')
	{
		data->matrix_map[data->y][data->x] = '0';
		return (1);
	}
	if (key == DOWN && data->matrix_map[data->y][data->x] == 'C')
	{
		data->matrix_map[data->y][data->x] = '0';
		return (1);
	}
	if (key == UP && data->matrix_map[data->y][data->x] == 'C')
	{
		data->matrix_map[data->y][data->x] = '0';
		return (1);
	}
	return (0);
}

int	select_action(int key, t_data *data)
{
	if (key == CLOSE)
		closewindow(data, 0);
	else if (key == UP)
		up(key, data);
	else if (key == DOWN)
		down(key, data);
	else if (key == RIGHT)
		right(key, data);
	else if (key == LEFT)
		left(key, data);
	if (collect_items(key, data))
			data->n_items++;
	else if (end_game(key, data))
		return (key);
	if (!crash(key, data) && !end_game(key, data))
	{
		if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
		{
			data->moves++;
			printf("MOVES MADE -> ★ %d ★\n", data->moves);
		}
	}
	return (key);
}
