/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_int_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejinkim <sejinkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:12:19 by sejinkim          #+#    #+#             */
/*   Updated: 2023/03/02 10:27:46 by sejinkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int	**make_int_map(char **map, int size, int len, char *mark)
{
	int	**int_map;
	int	i;
	int	j;

	int_map = (int **) malloc(sizeof(int *) * (size + 1));
	int_map[0] = (int *) malloc(sizeof(int) * len);
	i = 0;
	while (i < len)
		int_map[0][i++] = 0;
	i = 0;
	while (++i < size + 1)
	{
		int_map[i] = (int *) malloc(sizeof(int) * len);
		int_map[i][0] = 0;
		j = 1;
		while (j < len)
		{
			if (map[i - 1][j - 1] == mark[0])
				int_map[i][j] = 1;
			if (map[i - 1][j - 1] == mark[1])
				int_map[i][j] = 0;
			j++;
		}
	}
	return (int_map);
}
