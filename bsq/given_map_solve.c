/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   given_map_solve.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejinkim <sejinkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:12:33 by sejinkim          #+#    #+#             */
/*   Updated: 2023/03/02 11:55:50 by sejinkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int	given_map_solve(char *av)
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
	point.map1 = read_char_map(&point, mark, av);
	if (!point.map1)
		return (print_error());
	point.map2 = make_int_map(point.map1, point.size, point.len, mark);
	j = 0;
	arr = find_sq(point.map2, point.size, point.len - 1);
	fill_mark(mark, point.map1, arr);
	while (j < point.size)
		ft_putstr(point.map1[j++], point.len - 1);
	free(arr);
	free_char_map(point.map1);
	free_int_map(point.map2, point.size);
	return (0);
}

char	**read_char_map(t_point *point, char *mark, char *filename)
{
	int		fd;
	char	*buff;
	char	**map;
	int		cnt;

	cnt = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return ((char **)(long long)print_error());
	buff = (char *) malloc(sizeof(char) * BUFF_SIZE);
	if (!buff)
		return ((char **)(long)(0 * close(fd)));
	read(fd, buff, BUFF_SIZE);
	(*point).size = ft_atoi(buff, &cnt);
	if (!ft_mark(mark, buff, cnt))
		return (0);
	map = (char **)malloc(sizeof(char *) * ((*point).size + 1));
	if (!map)
		return ((char **)(long)(free_malloc(buff) + 0 * close(fd)));
	map[(*point).size] = 0;
	(*point).len = fill_char_map(buff + cnt + 3, map, point);
	if (!(*point).len)
		return (0);
	return (map + free_malloc(buff) + 0 * close(fd));
}

int	fill_char_map(char *buff, char **map, t_point *point)
{
	int	read_len;
	int	i;
	int	j;
	int	idx;

	i = -1;
	j = 1;
	(*point).len = 0;
	while (++i < (*point).size)
	{
		read_len = str_malloc(buff + i * (*point).len, map, i, point);
		if (!read_len)
			return (0);
		idx = 0;
		while (idx < read_len)
		{
			if (!buff_to_map(buff, map[i], j, idx))
				return (0);
			j++;
			idx++;
		}
		map[i][idx + 1] = 0;
	}
	return (read_len);
}

int	str_malloc(char *buff, char **map, int i, t_point *point)
{
	int	read_len;

	read_len = 1;
	while ((int)buff[read_len] != 10)
		read_len++;
	if (read_len == 0)
		return (0);
	if ((*point).len == 0)
		(*point).len = read_len;
	else
		if (read_len != (*point).len)
			return (0);
	*(map + i) = (char *)malloc(sizeof(char) * read_len);
	if (!*(map + i))
		return (0);
	return (read_len);
}

int	buff_to_map(char *buff, char *map, int j, int idx)
{
	if (buff[j] == *(buff - 3))
		map[idx] = *(buff - 3);
	else if (buff[j] == *(buff - 2))
		map[idx] = *(buff - 2);
	else if (buff[j] != 10)
		return (0);
	return (1);
}
