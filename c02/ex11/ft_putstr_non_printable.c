/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:38:53 by eushin            #+#    #+#             */
/*   Updated: 2023/02/13 21:45:24 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	int				i;
	unsigned char	a;
	unsigned char	b;

	i = 0;
	if (!str)
		return ;
	while ((unsigned char)str[i])
	{
		if (!(32 <= (unsigned char)str[i] && (unsigned char)str[i] <= 127))
		{
			a = (unsigned char)str[i] / 16;
			b = (unsigned char)str[i] % 16;
			write(1, "\\", 1);
			write(1, &"0123456789abcdef"[a], 1);
			write(1, &"0123456789abcdef"[b], 1);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}
