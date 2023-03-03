/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 20:02:47 by eushin            #+#    #+#             */
/*   Updated: 2023/02/19 21:20:16 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_row_start(int **ans, int *view, int idx, int n)
{
	int	max;
	int	cnt;
	int	start;

	max = 0;
	cnt = 0;
	start = 0;
	while (0 <= start && start <= n - 1)
	{
		if (max < ans[idx / n][start])
		{
			max = ans[idx / n][start];
			cnt++;
		}
		if (max == n)
			break ;
		start++;
	}
	if (cnt == view[2 * n + (idx / n)] && max == n)
		return (1);
	return (0);
}

int	check_row_end(int **ans, int *view, int idx, int n)
{
	int	max;
	int	cnt;
	int	start;

	max = 0;
	cnt = 0;
	start = n - 1;
	while (0 <= start && start <= n - 1)
	{
		if (max < ans[idx / n][start])
		{
			max = ans[idx / n][start];
			cnt++;
		}
		if (max == n)
			break ;
		start--;
	}
	if (cnt == view[3 * n + (idx / n)] && max == n)
		return (1);
	return (0);
}

int	check_col_start(int **ans, int *view, int idx, int n)
{
	int	max;
	int	cnt;
	int	start;

	max = 0;
	cnt = 0;
	start = 0;
	while (0 <= start && start <= n - 1)
	{
		if (max < ans[start][idx % n])
		{
			max = ans[start][idx % n];
			cnt++;
		}
		if (max == n)
			break ;
		start++;
	}
	if (cnt == view[0 * n + (idx % n)] && max == n)
		return (1);
	return (0);
}

int	check_col_end(int **ans, int *view, int idx, int n)
{
	int	max;
	int	cnt;
	int	start;

	max = 0;
	cnt = 0;
	start = n - 1;
	while (0 <= start && start <= n - 1)
	{
		if (max < ans[start][idx % n])
		{
			max = ans[start][idx % n];
			cnt++;
		}
		if (max == n)
			break ;
		start--;
	}
	if (cnt == view[1 * n + (idx % n)] && max == n)
		return (1);
	return (0);
}

int	check_height(int **ans, int *view, int idx, int n)
{
	int	max;
	int	cnt;

	max = 0;
	cnt = 0;
	if ((idx % n == n - 1) && (ans[idx / n][idx % n] != -1))
	{
		if (!check_row_start(ans, view, idx, n)
			|| !check_row_end(ans, view, idx, n))
			return (0);
	}
	if ((idx / n == n - 1) && (ans[idx / n][idx % n] != -1))
	{
		if (!check_col_start(ans, view, idx, n)
			|| !check_col_end(ans, view, idx, n))
			return (0);
	}
	return (1);
}
