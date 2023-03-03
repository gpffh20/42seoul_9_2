/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 03:26:21 by eushin            #+#    #+#             */
/*   Updated: 2023/02/27 16:05:15 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;
	int	res;

	i = 1;
	res = 0;
	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (0);
	while (i <= nb / i)
	{
		if (nb % i == 0)
			res += 2;
		i++;
	}
	if (res > 2)
		return (0);
	else
		return (1);
}

int	ft_find_next_prime(int nb)
{
	int	is_prime;

	if (nb < 0)
		return (2);
	is_prime = ft_is_prime(nb);
	if (is_prime == 1)
		return (nb);
	else
	{
		while (is_prime == 0)
		{
			is_prime = ft_is_prime(nb);
			nb++;
		}
	}
	return (nb - 1);
}
