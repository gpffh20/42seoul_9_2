/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:25:46 by eushin            #+#    #+#             */
/*   Updated: 2023/02/17 19:57:40 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
	return ;
}

int	main(int ac, char *av[])
{
	char	*tmp;
	int		i;
	int		j;

	i = 1;
	while (i < ac)
	{
		j = 1;
		while (i + j < ac)
		{
			if (ft_strcmp(av[i], av[i + j]) > 0)
			{
				tmp = av[i];
				av[i] = av[i + j];
				av[i + j] = tmp;
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (av[++i])
		ft_putstr(av[i]);
	return (0);
}
