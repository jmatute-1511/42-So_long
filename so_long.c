/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:38:41 by jmatute-          #+#    #+#             */
/*   Updated: 2022/04/03 21:00:14 by jmatute-         ###   ########.fr       */
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
		data->y = data->y - 16;
		mlx_put_image_to_window(data->mlx, data->win, data->img2, data->x, data->y);
		mlx_put_image_to_window(data->mlx, data->win, data->img,data->x,data->y);
		mlx_put_image_to_window(data->mlx, data->win, data->img2, data->x, aux);
		//mlx_put_image_to_window(data->mlx, data->win, data->img,data->x,data->y);
	}
	printf("\n%d --  %d  --- %d\n",key, data->x, data->y);
	return (key);
}*/
int main(int argc, char **argv)
{
	t_data data;

	data.map = Fill_Array_Map(argv);
	data.x_win = Size_of_widht(data.map) * 32;
	data.y_win = Size_of_high (data.map) * 32;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx,data.x_win,data.y_win,"so_long");
	Fill_Window(&data,data.mlx,data.win,data.map);
	mlx_hook(data.win, 02, 1L<<0, print_key, &data);
	mlx_loop(data.mlx);

}