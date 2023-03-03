/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejinkim <sejinkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:22:45 by sejinkim          #+#    #+#             */
/*   Updated: 2023/03/02 11:56:14 by sejinkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

void	ft_putstr(char *str, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		write(1, str, 1);
		str++;
		i++;
	}
	write(1, "\n", 1);
}

int	ft_atoi(char *str, int *cnt)
{
	int	num;

	num = 0;
	if (!('0' <= *str && *str <= '9'))
		return (0);
	while ('0' <= *str && *str <= '9')
	{
		num = num * 10 + *str - '0';
		str++;
		(*cnt)++;
	}
	return (num);
}

char	**ft_malloc(int n)
{
	char	**map;

	map = (char **)malloc(sizeof(char *) * n);
	if (!map)
		return (0);
	map[n - 1] = 0;
	return (map);
}

int	ft_mark(char *mark, char *buff, int cnt)
{
	mark[0] = *(buff + cnt);
	if (mark[0] < 32 || 126 < mark[0])
		return (0);
	mark[1] = *(buff + cnt + 1);
	if (mark[1] < 32 || 126 < mark[1])
		return (0);
	mark[2] = *(buff + cnt + 2);
	if (mark[2] < 32 || 126 < mark[2])
		return (0);
	mark[3] = *(buff + cnt + 3);
	if (mark[3] != 10)
		return (0);
	if (mark[0] == mark[1] || mark[0] == mark[2] || mark[1] == mark[2])
		return (0);
	return (1);
}
