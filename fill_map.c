/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 17:24:04 by jmatute-          #+#    #+#             */
/*   Updated: 2022/04/10 16:51:12 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*bucle(char *aux_map, char *line, char *map, int fd)
{
	int	bolean;

	bolean = get_next_line(fd, &line);
	while (bolean != 0)
	{
		if (line[0] != '\n' && map)
		{
			aux_map = ft_strnjoin(3, map, "\n", line);
			free(map);
			map = ft_strdup(aux_map);
			free(aux_map);
		}
		else if (line[0] != '\n')
			map = ft_strdup(line);
		free(line);
		bolean = get_next_line(fd, &line);
	}
	if (map)
	{
		aux_map = ft_strnjoin(3, map, "\n", line);
		free(map);
	}
	free(line);
	return (aux_map);
}

char	*fill_array_map(char **argv)
{
	int		fd;
	char	*map;
	char	*aux_map;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	map = NULL;
	aux_map = NULL;
	map = bucle(aux_map, line, map, fd);
	return (map);
}

void	create_images(t_data *data, void *mlx)
{
	data->end_game = mlx_xpm_file_to_image(mlx, "./images/you_win.xpm", \
	&data->width, &data->high);
	data->floor = mlx_xpm_file_to_image(mlx, "./images/floor.xpm", \
	&data->width, &data->high);
	data->wall = mlx_xpm_file_to_image(mlx, "./images/wall.xpm", \
	&data->width, &data->high);
	data->exit = mlx_xpm_file_to_image(mlx, "./images/exit.xpm", \
	&data->width, &data->high);
	data->items = mlx_xpm_file_to_image(mlx, "./images/colectable.xpm", \
	&data->width, &data->high);
	data->up = mlx_xpm_file_to_image(mlx, "./images/up.xpm", \
	&data->width, &data->high);
	data->down = mlx_xpm_file_to_image(mlx, "./images/down.xpm", \
	&data->width, &data->high);
	data->left = mlx_xpm_file_to_image(mlx, "./images/left.xpm", \
	&data->width, &data->high);
	data->right = mlx_xpm_file_to_image(mlx, "./images/right.xpm", \
	&data->width, &data->high);
}

void	select_images(t_data *data, char c, void *mlx, void *win)
{
	mlx_put_image_to_window(mlx, win, data->floor, data->f_x, data->f_y);
	if (c == '1')
		mlx_put_image_to_window(mlx, win, data->wall, data->f_x, data->f_y);
	if (c == 'C')
		mlx_put_image_to_window(mlx, win, data->items, data->f_x, data->f_y);
	if (c == 'E')
		mlx_put_image_to_window(mlx, win, data->exit, data->f_x, data->f_y);
	if (c == 'P')
		mlx_put_image_to_window(mlx, win, data->right, data->f_x, data->f_y);
}

void	fill_window(t_data *data, void *mlx, void *win, char **map)
{
	int	count;
	int	count2;

	count = 0;
	count2 = 0;
	data->f_x = 0;
	data->f_y = 0;
	while (map[count])
	{
		while (map[count][count2])
		{
			select_images(data, map[count][count2], mlx, win);
			data->f_x += 32;
			count2++;
		}
		data->f_x = 0;
		data->f_y += 32;
		count2 = 0;
		count++;
	}
}
