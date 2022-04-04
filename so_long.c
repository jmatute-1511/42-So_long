/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:38:41 by jmatute-          #+#    #+#             */
/*   Updated: 2022/04/04 19:23:04 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

/*int print_key(int key, t_data *data)
{
	int	aux;

	if (key == UP)
	{
		aux = data->y;

	}
	printf("\n%d --  %d  --- %d\n",key, data->x, data->y);
	return (key);
}*/
int main(int argc, char **argv)
{
	t_data data;

	data.map = Fill_Array_Map(argv);
	data.matrix_map = ft_split(data.map, '\n');
	data.x_win = Size_of_widht(data.map) * 32;
	data.y_win = Size_of_high (data.map) * 32;
	data.x = Find_Ipoint(data.matrix_map, 'x');
	data.y = Find_Ipoint(data.matrix_map, 'y');
	printf("---- x : %d ------ y : %d ----\n",data.x,data.y);
	free(data.map);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx,data.x_win,data.y_win,"so_long");
	Create_Images(&data, data.mlx);
	Fill_Window(&data,data.mlx,data.win,data.matrix_map);
	mlx_hook(data.win, 02, 1L<<0,Select_Action, &data);
	mlx_loop(data.mlx);

}