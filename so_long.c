/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:38:41 by jmatute-          #+#    #+#             */
/*   Updated: 2022/04/05 20:05:08 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int Close_Window(t_data *data, int mode)
{
	if (mode != 0)
		mlx_destroy_window(data->mlx, data->win);
	free(data->map);
	free_matrix(data->matrix_map);
	exit (0);
	return (0);
}
void	Start_Variables(t_data *data, char **argv)
{
	data->map = Fill_Array_Map(argv);
	data->matrix_map = ft_split(data->map, '\n');
	data->x_win = Size_of_widht(data->map) * 32;
	data->y_win = Size_of_high (data->map) * 32;
	data->x = Find_Ipoint(data->matrix_map, 'x');
	data->y = Find_Ipoint(data->matrix_map, 'y');
	data->Full_items = Full_Items(data->map);
	data->items = 0;
	data->moves = 0;
	if(data->y_win <=2)
	{
		printf("Error \nThe map does not meets the requirements\n");
		Close_Window(data, 0);
	}
}
int main(int argc, char **argv)
{
	t_data data;

	if(argc != 2)
		return (0);
	Start_Variables(&data, argv);
	Check_Error_Map(&data);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx,data.x_win,data.y_win,"so_long");
	Create_Images(&data, data.mlx);
	Fill_Window(&data,data.mlx,data.win,data.matrix_map);
	mlx_hook(data.win, 02, 1L<<0,Select_Action, &data);
	mlx_hook(data.win, 17, 1L << 2, Close_Window, &data);
	mlx_loop(data.mlx);
	return (0);
}