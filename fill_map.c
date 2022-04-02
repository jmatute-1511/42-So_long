/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 17:24:04 by jmatute-          #+#    #+#             */
/*   Updated: 2022/04/02 21:00:25 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char *Fill_Array_Map(char **argv)
{
	int		fd;
	int		bolean;
	char	*map;
	char	*aux_map;
	char	*line;

	fd = open(argv[1],O_RDONLY);
	bolean = 1;
	map = NULL;
	while (bolean != 0)
	{
		bolean = get_next_line(fd, &line);
		if (map)
		{
			aux_map = ft_strnjoin(3,map,"\n",line);
			free(map);
			map = ft_strdup(aux_map);
			free(aux_map);
		}
		else
			map = ft_strdup(line);
		free(line);
	}
	return(map);
}
int Map_Is_Square(char *map)
{
	int line;
	int aux_line;
	int count;

	line = 0;
	aux_line = 0;
	count = 0;
	while (map[count])
	{
		if(map[count] == "\n")
		{
			aux_line = line;
			if (line != aux_line)
				return(1);
			line = 0;
		}
		line++;
		count++;
	}
	return(0);

}
int Check_Error_Map(char *map)
{
	if (Map_Is_Square(map))
		return(1)

}
int main(int argc, char **argv)
{
	char *map;
	map = Fill_Array_Map(argv);
	printf("%s",map);
	return(0);
}