/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 11:23:40 by jmatute-          #+#    #+#             */
/*   Updated: 2022/04/05 20:02:47 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int Map_is_Square(char *map)
{
	int line;
	int aux_line;
	int count;

	line = 0;
	aux_line = 0;
	count = 0;
	while (map[count])
	{
		if(map[count] == '\n' || map[count + 1] == '\0')
		{
			if (map[count + 1] == '\0')
				line++;
			if (line != aux_line && aux_line != 0)
				return(1);
			aux_line = line;
			line = 0;
		}
		else
			line++;
		count++;
	}
	return(0);

}

int Map_is_Close(char * map, int lines)
{
	int count;
	int bucle;

	count = 0;
	bucle = 0;
	while(bucle < lines)
	{
		while (map[count] != '\n' && map[count])
		{
			if ( bucle == 0  && map[count] != '1')
				return(1);
			if ( map[count - 1] == '\n' && map[count] != '1' && count != 0)
				return(1);
			if ( map[count + 1] == '\n' && map[count] != '1')
				return(1);
			if ( bucle == lines - 1  && map[count] != '1' )
				return (1);
			count++;
		}
		count++;
		bucle++;
	}
	return (0);
}

int Map_is_Complete(char *map)
{
	int count;
	int count2;
	int count3;
	int elements[4];

	count = 0;
	count2 = 0;
	count3 = 0;
	while (count3 < 4)
	{
		elements[count3] = 0;
		count3++;
	}
	while (map[count])
	{
		Check_elements(map,count,elements);
		count++;
	}
	while (count2 != 4 )
	{
		if (elements[count2] != 1)
		 return (1);
		count2++;
	}
	return (0);
}

int Map_is_Valid(char *map)
{
	while (*map != '\0')
	{
		if(*map == '1' || *map == '0' || *map == 'P' \
		|| *map == 'C' || *map == 'E' || *map == '\n')
			map++;
		else
			return (1);
	}
	return (0);
}

void Check_Error_Map(t_data *data)
{
	if (Map_is_Square(data->map))
	{
		printf("Error \nMap is not Square\n");
		Close_Window(data, 0);
	}
	if (Map_is_Close(data->map,data->y_win))
	{
		printf("Error \nSome Wall is open\n");
		Close_Window(data, 0);
	}
	if (Map_is_Complete(data->map))
	{
		printf("Error \nMissign elements on the map\n");
		Close_Window(data, 0);
	}
	if (Map_is_Valid(data->map))
	{
		printf("Error \nSome characte in the map is not valid\n");
		Close_Window(data, 0);
	}
}