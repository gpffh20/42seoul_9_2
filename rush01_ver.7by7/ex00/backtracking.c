/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 20:02:38 by eushin            #+#    #+#             */
/*   Updated: 2023/02/19 21:55:11 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	check_height(int **ans, int *view, int idx, int n);
int	print_ans(int **ans, int n);

int	check_double(int **ans, int idx, int value, int n)
{
	int	x;

	x = 0;
	while (x < n)
	{
		if (ans[idx / n][x] == value || ans[x][idx % n] == value)
			return (1);
		x++;
	}
	return (0);
}

int	backtracking(int **ans, int *view, int idx, int n)
{
	int	value;

	value = 0;
	while (++value <= n)
	{
		if (!check_double(ans, idx, value, n))
			ans[idx / n][idx % n] = value;
		else
			continue ;
		if (!check_height(ans, view, idx, n))
		{
			ans[idx / n][idx % n] = -1;
			continue ;
		}
		if (idx < n * n - 1)
		{
			if (backtracking(ans, view, idx + 1, n))
				return (1);
		}
		else
			return (print_ans(ans, n));
		ans[idx / n][idx % n] = -1;
	}
	return (0);
}

void	free_malloc(int **ans, int **view, int n)
{
	int	i;

	i = -1;
	while (++i < n)
		free(ans[i]);
	free(ans);
	free(*view);
}

int	**set_ans(int **ans, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			ans[i][j] = -1;
			j++;
		}
		i++;
	}
	return (ans);
}

int	start_backtracking(int n, int **view)
{
	int	**ans;
	int	i;

	i = -1;
	ans = (int **)malloc(sizeof(int *) * n);
	if (!ans)
		return (0);
	while (++i < n)
	{
		ans[i] = (int *)malloc(sizeof(int) * n);
		if (!ans[i])
			return (0);
	}
	ans = set_ans(ans, n);
	if (!backtracking(ans, *view, 0, n))
		write(2, "No possible cases\n", 19);
	free_malloc(ans, view, n);
	return (0);
}
