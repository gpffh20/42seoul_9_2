/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejinkim <sejinkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 21:38:59 by eushin            #+#    #+#             */
/*   Updated: 2023/03/02 11:55:38 by sejinkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEADER_H
# define FT_HEADER_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# define BUFF_SIZE 1000000000

typedef struct s_point
{
	char	**map1;
	int		**map2;
	int		size;
	int		len;
}	t_point;

int		print_error(void);
int		input_map_solve(void);
char	**input_map(t_point *point, char *mark);
void	input_map_line(char *buff, t_point *point, char *mark, int i);
int		input_str_malloc(char *buff, t_point *point, int i);
int		*find_sq(int **map, int size, int len);
void	fill_mark(char *mark, char **map, int *arr);
void	ft_putstr(char *str, int len);
int		ft_atoi(char *str, int *cnt);
char	**ft_malloc(int n);
int		ft_mark(char *mark, char *buff, int cnt);
int		free_malloc(char *buff);
int		free_char_map(char **str);
int		free_int_map(int **str, int size);
int		given_map_solve(char *av);
char	**read_char_map(t_point *point, char *mark, char *filename);
int		fill_char_map(char *buff, char **map, t_point *point);
int		str_malloc(char *buff, char **map, int i, t_point *point);
int		buff_to_map(char *buff, char *map, int j, int idx);
int		**make_int_map(char **map, int size, int len, char *mark);

#endif
