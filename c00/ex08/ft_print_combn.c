/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 21:23:15 by eushin            #+#    #+#             */
/*   Updated: 2023/02/12 18:27:48 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_recursive(int *arr, int i, int val, int n)
{
	int		idx;
	char	c;

	if (i == n)
	{
		idx = 0;
		while (idx < n)
		{
			c = arr[idx] + '0';
			write(1, &c, 1);
			idx++;
		}
		if (arr[0] != 10 - n)
			write(1, ", ", 2);
		return ;
	}
	while (val < 10)
	{
		arr[i] = val;
		ft_recursive(arr, i + 1, val + 1, n);
		val++;
	}
}

void	ft_print_combn(int n)
{
	int	arr[10];
	int	i;
	int	val;

	i = 0;
	val = 0;
	ft_recursive(arr, i, val, n);
	return ;
}
