/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:30:30 by eushin            #+#    #+#             */
/*   Updated: 2023/02/27 13:44:59 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

void	print(int *board, int *cnt)
{
	int		i;
	char	c;

	i = -1;
	while (++i < 10)
	{
		c = board[i] + '0';
		write(1, &c, 1);
	}
	cnt[0] += 1;
	write(1, "\n", 1);
}

void	backtracking(int i, int queen, int *cnt, int *board)
{
	int	j;
	int	is_put;

	i = -1;
	if (queen == 10)
		print(board, cnt);
	while (++i < 10)
	{
		is_put = 1;
		j = -1;
		while (++j < queen)
		{
			if (board[j] == i || ft_abs(queen - j) == ft_abs(i - board[j]))
			{
				is_put = 0;
				break ;
			}
		}
		if (is_put)
		{
			board[queen] = i;
			backtracking(-1, queen + 1, cnt, board);
		}
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	board[10];
	int	cnt[1];
	int	i;

	cnt[0] = 0;
	i = -1;
	while (++i < 10)
		board[i] = -1;
	backtracking(-1, 0, cnt, board);
	return (cnt[0]);
}

/*
#include <stdio.h>
int main()
{
	printf("%d", ft_ten_queens_puzzle());
	return (0);
}
*/