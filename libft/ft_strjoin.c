/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 11:56:30 by jmatute-          #+#    #+#             */
/*   Updated: 2022/04/08 22:08:51 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	bucles(const char *s2, int count2, int count, char *p)
{
	while (s2[count2])
	{
		(p[count] = s2[count2]);
		(count += 1);
		(count2 += 1);
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*p;
	int		count;
	int		count2;

	count = 0;
	count2 = 0;
	if (!s2 || !s1)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	p = malloc(len + 1);
	if (!p)
		return (NULL);
	while (s1[count])
	{
		(p[count] = s1[count]);
		(count++);
	}
	bucles(s2, count2, count, p);
	p[len] = '\0';
	return (p);
}
