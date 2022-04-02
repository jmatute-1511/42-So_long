/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:38:41 by jmatute-          #+#    #+#             */
/*   Updated: 2022/04/02 17:23:13 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int print_key(int key, t_data *data)
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
}
int main(void)
{
	t_data data;
	data.width = 16;
	data.high = 16;
	data.x = 199;
	data.y = 199;
	data.mlx = mlx_init();
	data.img2 = mlx_xpm_file_to_image(data.mlx,"./images/floor.xpm",&data.width,&data.high);
	data.img = mlx_xpm_file_to_image(data.mlx,"./images/up.xpm",&data.width,&data.high);
	data.win = mlx_new_window(data.mlx,400,400,"so_long");

	mlx_hook(data.win, 02, 1L<<0, print_key, &data);
	mlx_loop(data.mlx);

}