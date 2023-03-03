/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:21:03 by eushin            #+#    #+#             */
/*   Updated: 2023/02/22 21:33:37 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int			i;
	long long	size;
	int			*str;

	if (min >= max)
		return (0);
	size = max - min;
	str = (int *)malloc(sizeof(long long) * (size + 1));
	if (!str)
		return (-1);
	i = 0;
	while (min < max)
	{
		str[i] = min;
		i++;
		min++;
	}
	str[i] = 0;
	*range = str;
	return (i);
}
