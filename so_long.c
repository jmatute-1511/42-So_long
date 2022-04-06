/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:38:41 by jmatute-          #+#    #+#             */
/*   Updated: 2022/04/06 21:11:34 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	closewindow(t_data *data, int mode)
{
	if (mode != 0)
		mlx_destroy_window(data->mlx, data->win);
	free(data->map);
	free_matrix(data->matrix_map);
	exit (0);
	return (0);
}

void	start_variables(t_data *data, char **argv)
{
	data->map = fill_array_map(argv);
	data->matrix_map = ft_split(data->map, '\n');
	data->x_win = size_of_widht(data->map) * 32;
	data->y_win = size_of_high (data->map) * 32;
	data->x = find_ipoint(data->matrix_map, 'x');
	data->y = find_ipoint(data->matrix_map, 'y');
	data->full_items = full_items(data->map);
	data->high = 32;
	data->width = 32;
	data->n_items = 0;
	data->moves = 0;
	if (data->y_win <= 2)
	{
		printf("Error \nThe map does not meets the requirements\n");
		closewindow(data, 0);
	}
}

int	main(int argc, char **argv)
{
	t_data	data;
	char	*str;

	if (argc != 2)
		return (0);
	str = ft_strstr(argv[1], ".ber");
	if (str == 0)
	{
		printf("Error\n Map is not valid");
		return (0);
	}
	start_variables(&data, argv);
	check_error_map(&data);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, data.x_win, data.y_win, "so_long");
	create_images(&data, data.mlx);
	fill_window(&data, data.mlx, data.win, data.matrix_map);
	mlx_hook(data.win, 02, 1L << 0, select_action, &data);
	mlx_hook(data.win, 17, 1L << 2, closewindow, &data);
	mlx_loop(data.mlx);
	return (0);
}
