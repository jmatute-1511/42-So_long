/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 19:48:54 by jmatute-          #+#    #+#             */
/*   Updated: 2022/04/09 15:22:13 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_elements(char *map, int count, int *elements)
{
	if (map[count] == '0')
		elements[0] = 1;
	if (map[count] == 'E')
		elements[1] = 1;
	if (map[count] == 'P')
		elements[2] = 1;
	if (map[count] == 'C')
		elements[3] = 1;
}

int	size_of_high(char *map)
{
	int	high;
	int	count;

	count = 0;
	if (map[count] == '1')
		high = 1;
	else
		high = 0;
	while (map[count])
	{
		if (map[count] == '\n' && map[count + 1] == '1')
			high++;
		count++;
	}
	return (high);
}

int	size_of_widht(char *map)
{
	int	width;
	int	count;

	width = 0;
	count = 0;
	while (map[count] != '1')
		count++;
	while (map[width + count] != '\n')
		width++;
	return (width);
}

int	full_items(char *map)
{
	int	full_items;

	full_items = 0;
	while (*map)
	{
		if (*map == 'C')
			full_items++;
		map++;
	}
	return (full_items);
}
