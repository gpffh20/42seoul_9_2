/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_sq.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejinkim <sejinkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 21:40:01 by eushin            #+#    #+#             */
/*   Updated: 2023/03/02 10:28:30 by sejinkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int	ft_min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

int	*arr_malloc(void)
{
	int	*arr;

	arr = (int *)malloc(sizeof(int) * 3);
	if (!arr)
		return (0);
	return (arr);
}

int	*find_sq(int **map, int size, int len)
{
	int	i;
	int	j;
	int	*arr;

	i = 0;
	arr = arr_malloc();
	while (++i < size + 1)
	{
		j = 0;
		while (++j < len + 1)
		{
			if (map[i][j])
			{
				map[i][j] = ft_min(map[i - 1][j], map[i][j - 1]);
				map[i][j] = ft_min(map[i][j], map[i - 1][j - 1]) + 1;
			}
			if (map[i][j] > arr[0])
			{
				arr[0] = map[i][j];
				arr[1] = i - 1;
				arr[2] = j - 1;
			}
		}
	}
	return (arr);
}

void	fill_mark(char *mark, char **map, int *arr)
{
	int	i;
	int	j;

	i = arr[1] - arr[0] + 1;
	while (i <= arr[1])
	{
		j = arr[2] - arr[0] + 1;
		while (j <= arr[2])
		{
			map[i][j] = mark[2];
			j++;
		}
		i++;
	}
	free(mark);
}
