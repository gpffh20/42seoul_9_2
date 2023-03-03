/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 12:14:31 by eushin            #+#    #+#             */
/*   Updated: 2023/02/12 12:30:49 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_putchar(char c);

void	ft_condition(int x, int y, int row_num, int col_num)
{
	if (row_num == 0 && col_num == 0)
		ft_putchar('o');
	else if (row_num == y - 1 && col_num == x - 1)
		ft_putchar('o');
	else if (row_num == 0 && col_num == x - 1)
		ft_putchar('o');
	else if (row_num == y - 1 && col_num == 0)
		ft_putchar('o');
	else if (row_num == 0 || row_num == y - 1)
		ft_putchar('-');
	else if (col_num == 0 || col_num == x - 1)
		ft_putchar('|');
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
