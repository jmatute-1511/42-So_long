/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 19:48:54 by jmatute-          #+#    #+#             */
/*   Updated: 2022/04/03 19:53:57 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void Check_elements(char *map, int count,int *elements)
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
int Size_of_high(char *map)
{
	int high;
	int count;

	high = 1;
	count = 0;
	while (map[count])
	{
		if (map[count] == '\n')
			high++;
		count++;
	}
	return (high);
}
int Size_of_widht(char *map)
{
	int width;

	width = 0;
	while (map[width] != '\n')
		width++;
	return(width);
}
