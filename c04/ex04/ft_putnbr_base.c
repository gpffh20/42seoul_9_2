/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:14:29 by eushin            #+#    #+#             */
/*   Updated: 2023/02/15 18:02:41 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb, int i, char *base)
{
	long long	llnb;

	llnb = (long long)nb;
	if (llnb < 0)
	{
		llnb *= -1;
		write(1, "-", 1);
	}
	if (llnb / i > 0)
	{
		ft_putnbr(llnb / i, i, base);
	}
	write(1, &base[llnb % i], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	len;
	int	j;

	len = 0;
	while (base[len])
	{
		if (base[len] == '+' || base[len] == '-')
			return ;
		j = 1;
		while (base[len + j])
		{
			if (base[len] == base[len + j])
				return ;
			j++;
		}
		len++;
	}
	if (len <= 1)
		return ;
	ft_putnbr(nbr, len, base);
}
