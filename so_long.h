#ifndef SO_LONG_H
#define SO_LONG_H

#include <mlx.h>
#include <unistd.h>
#include "./libft/libft.h"
#include "./get_next_line/get_next_line_bonus.h"
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
#ifndef CLOSE
#define CLOSE	53
#endif
typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*Floor;
	void	*Items;
	void	*Wall;
	void	*Up;
	void	*Left;
	void	*Right;
	void	*Down;
	void	*Sprite;
	void	*Exit;
	int		items;
	int		Full_items;
	int		moves;
	int		x;
	int		y;
	int 	f_x;
	int		f_y;
	int		x_win;
	int		y_win;
	char	*map;
	char **matrix_map;
	int		high;
	int		width;
}			t_data;
// ERRORS FUCTIONS
int Map_is_Square(char *map);
int Map_is_Close(char * map, int lines);
void Check_elements(char *map, int count,int *elements);
int Map_is_Complete(char *map);
int Map_is_Valid(char *map);
void Check_Error_Map(t_data *data);

// GET NEXT LINE
int	get_next_line(int fd, char **line);

// UTILS MAP
char *Fill_Array_Map(char **argv);
int Size_of_high(char *map);
int Size_of_widht(char *map);
int Full_Items(char *map);
//FILL WINDOW
void Create_Images(t_data *data, void *mlx);
void Fill_Window(t_data *data, void *mlx, void *win, char **map);
// LOGIC OF MOVES
int Select_Action(int key, t_data *data);
int Find_Ipoint(char **matrix,char cordinate);
// ClOSE WINDWOW
int Close_Window(t_data *data, int mode);

#endif