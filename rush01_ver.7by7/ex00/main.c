/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 05:10:33 by moson             #+#    #+#             */
/*   Updated: 2023/02/19 21:55:22 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	start_backtracking(int n, int **view);

int	print_ans(int **ans, int n)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			c = (char)(ans[i][j] + '0');
			write(1, &c, 1);
			if (j != n - 1)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (1);
}

int	print_error(int code)
{
	if (code == 0)
		write(2, "Wrong arguments\n", 17);
	if (code == 1)
		write(2, "Invalid map size\n", 18);
	if (code == 2)
		write(2, "Invalid Delimiter\n", 19);
	if (code == 3)
		write(2, "Argument is wrong number\n", 26);
	if (code == 4)
		write(2, "malloc() failed: NULL has returned\n", 36);
	return (1);
}

int	get_view(int n, char *argv1, int arg_len, int **view)
{
	int	count;

	*view = (int *)malloc(sizeof(int) * 4 * n);
	if (view == NULL && print_error(4))
		return (-1);
	count = 0;
	while (count < arg_len)
	{
		if (count % 2 == 0)
		{
			if ('1' <= argv1[count] && argv1[count] <= (n + '0'))
				(*view)[count / 2] = (int)(argv1[count] - '0');
			else if (print_error(3))
				return (-1);
		}
		else if ((count % 2 != 0) && argv1[count] != ' ' && print_error(2))
			return (-1);
		count++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	n;
	int	*view;
	int	arg_len;

	if (argc != 2 && print_error(0))
		return (-1);
	arg_len = 0;
	while (argv[1][arg_len] != '\0')
		arg_len++;
	if ((arg_len) == 0 && print_error(1))
		return (-1);
	n = 1;
	while (n < 10)
	{
		if (arg_len == 8 * n - 1)
			break ;
		n++;
	}
	if ((9 < n) && print_error(1))
		return (-1);
	view = NULL;
	if (get_view(n, argv[1], arg_len, &view) == -1)
		return (-1);
	return (start_backtracking(n, &view));
}
