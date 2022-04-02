#ifndef SO_LONG_H
#define SO_LONG_H

#include <mlx.h>
#include "./libft/libft.h"
#include "get_next_line_bonus.h"
#ifndef UP
#define UP		13
#endif
#ifndef RIGHT
#define RIGHT	2
#endif
#ifndef DOWN
#define DOWN	1
#endif
#ifndef LEFT
#define LEFT	0
#endif
typedef struct s_data
{
	void *mlx;
	int		x;
	int		y;
	void	*img2;
	void *img;
	int high;
	int width;
	char *addr;
	int bits_pixels;
	int line_length;
	void *win;
	int endian;
}			t_data;
int	get_next_line(int fd, char **line);

#endif