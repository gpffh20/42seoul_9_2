/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_map_solve.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejinkim <sejinkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 09:37:37 by eushin            #+#    #+#             */
/*   Updated: 2023/03/02 11:56:00 by sejinkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int	input_map_solve(void)
{
	t_point	point;
	int		j;
	int		*arr;
	char	*mark;

	point.size = 0;
	point.len = 0;
	mark = (char *) malloc(sizeof(char) * 4);
	if (!mark)
		return (free_malloc(mark));
	point.map1 = input_map(&point, mark);
	point.map2 = make_int_map(point.map1, point.size, point.len + 1, mark);
	j = 0;
	arr = find_sq(point.map2, point.size, point.len);
	fill_mark(mark, point.map1, arr);
	while (j < point.size)
		ft_putstr(point.map1[j++], point.len);
	free(arr);
	free_char_map(point.map1);
	free_int_map(point.map2, point.size);
	return (0);
}

char	**input_map(t_point *point, char *mark)
{
	char	*buff;
	int		cnt;
	int		i;

	cnt = 0;
	buff = (char *) malloc(sizeof(char) * BUFF_SIZE);
	if (!buff)
		return ((char **)(long)(0 * close(0)));
	read(0, buff, BUFF_SIZE);
	(*point).size = ft_atoi(buff, &cnt);
	if ((*point).size == 0)
		return ((char **)(long long)print_error());
	if (!ft_mark(mark, buff, cnt))
		exit(print_error());
	(*point).map1 = ft_malloc((*point).size + 1);
	i = -1;
	while (++i < (*point).size)
	{
		read(0, buff, BUFF_SIZE);
		input_map_line(buff, point, mark, i);
	}
	return ((*point).map1 + free_malloc(buff) + 0 * close(0));
}

void	input_map_line(char *buff, t_point *point, char *mark, int i)
{
	int	read_len;
	int	j;

	read_len = input_str_malloc(buff, point, i);
	if ((*point).len == 0)
		(*point).len = read_len;
	j = 0;
	while (j < read_len)
	{
		if (buff[j] == mark[0])
			(*point).map1[i][j] = mark[0];
		else if (buff[j] == mark[1])
			(*point).map1[i][j] = mark[1];
		else
			exit(print_error());
		j++;
	}
	(*point).map1[i][j + 1] = 0;
}

int	input_str_malloc(char *buff, t_point *point, int i)
{
	int	read_len;

	read_len = 0;
	while ((int)buff[read_len] != 10)
		read_len++;
	if (read_len == 0)
		return (print_error());
	if ((*point).len == 0)
		(*point).len = read_len;
	else
		if (read_len != (*point).len)
			exit(print_error());
	(*point).map1[i] = (char *)malloc(sizeof(char) * (read_len + 1));
	if (!(*point).map1[i])
		return (0);
	return (read_len);
}
