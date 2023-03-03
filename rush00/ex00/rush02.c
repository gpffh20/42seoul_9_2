/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkli <seongkli@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:21:30 by seongkli          #+#    #+#             */
/*   Updated: 2023/02/12 12:31:12 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_putchar(char c);

void	ft_condition(int x, int y, int row_num, int col_num)
{
	if (row_num == 0 && col_num == 0)
		ft_putchar('A');
	else if (row_num == 0 && col_num == x - 1)
		ft_putchar('A');
	else if (row_num == y - 1 && col_num == 0)
		ft_putchar('C');
	else if (row_num == y - 1 && col_num == x - 1)
		ft_putchar('C');
	else if (row_num == 0 || row_num == y - 1)
		ft_putchar('B');
	else if (col_num == 0 || col_num == x - 1)
		ft_putchar('B');
	else
		ft_putchar(' ');
}

void	ft_rush(int x, int y)
{
	int	row_num;
	int	col_num;

	row_num = 0;
	while (row_num < y)
	{
		col_num = 0;
		while (col_num < x)
		{
			ft_condition(x, y, row_num, col_num);
			col_num++;
		}
		row_num++;
		ft_putchar('\n');
	}
}
