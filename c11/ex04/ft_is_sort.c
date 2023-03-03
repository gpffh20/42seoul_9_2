/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 22:05:55 by eushin            #+#    #+#             */
/*   Updated: 2023/03/01 11:18:16 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;

	if (length <= 2)
		return (1);
	i = 0;
	while ((i < length - 1) && f(tab[i], tab[i + 1]) == 0)
		i++;
	while ((i < length - 1) && f(tab[i], tab[i + 1]) >= 0)
	{
		i++;
		if ((i < length - 1) && f(tab[i], tab[i + 1]) < 0)
			return (0);
	}
	while ((i < length - 1) && f(tab[i], tab[i + 1]) <= 0)
	{
		i++;
		if ((i < length - 1) && f(tab[i], tab[i + 1]) > 0)
			return (0);
	}
	return (1);
}
