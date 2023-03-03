/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:12:26 by eushin            #+#    #+#             */
/*   Updated: 2023/02/22 21:33:21 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int			i;
	long long	size;
	int			*range;

	if (min >= max)
		return (0);
	size = max - min;
	range = (int *)malloc(sizeof(long long) * (size + 1));
	if (!range)
		return (0);
	i = 0;
	while (min < max)
	{
		range[i] = min;
		i++;
		min++;
	}
	range[i] = 0;
	return (range);
}
