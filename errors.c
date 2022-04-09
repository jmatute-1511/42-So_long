/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 11:23:40 by jmatute-          #+#    #+#             */
/*   Updated: 2022/04/09 17:29:10 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_is_square(char *map)
{
	int	line;
	int	aux_line;
	int	count;

	line = 0;
	aux_line = 0;
	count = 0;
	while (map[count])
	{
		if (map[count] == '\n' && map[count - 1] == '1')
		{
			if (aux_line != line && aux_line != 0)
				return (1);
			aux_line = line;
			line = 0;
		}
		if (map[count] != '\n')
			line++;
		count++;
	}
	if (aux_line != line && line != 0)
		return (1);
	return (0);
}

int	map_is_close(char *map, int lines)
{
	int	count;
	int	bucle;

	count = 0;
	bucle = 0;
	while (map[count] != '1')
		count++;
	while (bucle < lines)
	{
		while (map[count] != '\n' && map[count])
		{
			if (bucle == 0 && map[count] != '1')
				return (1);
			if (map[count - 1] == '\n' && map[count] != '1' && count != 0)
				return (1);
			if (map[count + 1] == '\n' && map[count] != '1')
				return (1);
			if (bucle == lines - 1 && map[count] != '1' )
				return (1);
			count++;
		}
		count++;
		bucle++;
	}
	return (0);
}

int	map_is_complete(char *map)
{
	int	count;
	int	count2;
	int	count3;
	int	elements[4];

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
		check_elements(map, count, elements);
		count++;
	}
	while (count2 != 4)
	{
		if (elements[count2] != 1)
			return (1);
		count2++;
	}
	return (0);
}

int	map_is_valid(char *map)
{
	while (*map != '\0')
	{
		if (*map == '1' || *map == '0' || *map == 'P' \
		|| *map == 'C' || *map == 'E' || *map == '\n')
			map++;
		else
			return (1);
	}
	return (0);
}

void	check_error_map(t_data *data)
{
	int	lines;

	lines = size_of_high(data->map);
	if (map_is_close(data->map, lines))
	{
		printf("Error \nSome Wall is open\n");
		closewindow(data, 0);
	}
	if (map_is_square(data->map))
	{
		printf("Error \nMap is not Square\n");
		closewindow(data, 0);
	}
	if (map_is_complete(data->map))
	{
		printf("Error \nMissign elements on the map\n");
		closewindow(data, 0);
	}
	if (map_is_valid(data->map))
	{
		printf("Error \nSome character in the map is not valid\n");
		closewindow(data, 0);
	}
}
