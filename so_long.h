/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 20:19:54 by jmatute-          #+#    #+#             */
/*   Updated: 2022/04/09 17:57:53 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include	<mlx.h>
# include	<unistd.h>
# include	<stdio.h>
# include	"./libft/libft.h"
# include	"./get_next_line/get_next_line_bonus.h"
# ifndef UP
#  define UP		13
# endif
# ifndef RIGHT
#  define RIGHT	2
# endif
# ifndef DOWN
#  define DOWN	1
# endif
# ifndef LEFT
#  define LEFT	0
# endif
# ifndef CLOSE
#  define CLOSE	53
# endif

typedef struct s_data
{
	int		flag_end;
	void	*mlx;
	void	*win;
	void	*end_game;
	void	*floor;
	void	*items;
	void	*wall;
	void	*up;
	void	*left;
	void	*right;
	void	*down;
	void	*exit;
	int		n_items;
	int		full_items;
	int		moves;
	int		x;
	int		y;
	int		f_x;
	int		f_y;
	int		x_win;
	int		y_win;
	char	*map;
	char	**matrix_map;
	int		high;
	int		width;
}			t_data;
// ERRORS FUCTIONS
int		map_is_square(char *map);
int		map_is_close(char *map, int lines);
int		map_is_complete(char *map);
int		map_is_valid(char *map);
void	check_error_map(t_data *data);
void	check_elements(char *map, int count, int *elements);

// GET NEXT LINE
int		get_next_line(int fd, char **line);
// UTILS MAP
char	*fill_array_map(char **argv);
int		size_of_high(char *map);
int		size_of_widht(char *map);
int		full_items(char *map);
//FILL WINDOW
void	create_images(t_data *data, void *mlx);
void	fill_window(t_data *data, void *mlx, void *win, char **map);
void	select_images(t_data *data, char c, void *mlx, void *win);
// LOGIC OF MOVES
int		select_action(int key, t_data *data);
int		find_ipoint(char **matrix, char cordinate);
int		end_game(int key, t_data *data);
int		crash(int key, t_data *data);
int		collect_items(int key, t_data *data);
// MOVES
int		up(int key, t_data *data);
int		down(int key, t_data *data);
int		right(int key, t_data *data);
int		left(int key, t_data *data);
// ClOSE WINDWOW
int		closewindow(t_data *data, int mode);

#endif