/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 20:28:06 by eushin            #+#    #+#             */
/*   Updated: 2023/02/27 14:13:32 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi_base(char *str, char *base);
int	check_base(char *base);

int	check_size(long long num, int base)
{
	int	size;

	size = 1;
	while (num / base > 0)
	{
		num /= base;
		size++;
	}
	return (size);
}

char	*fill_string(long long num, int base, char *base_to)
{
	int		size;
	char	*new_str;

	if (num < 0)
		size = check_size(-num, base) + 1;
	else
		size = check_size(num, base);
	new_str = (char *)malloc(sizeof(char) * (size + 1));
	if (!new_str)
		return (NULL);
	new_str[size] = 0;
	while (size > 0)
	{
		if (num < 0)
			num *= -1;
		new_str[size - 1] = base_to[num % base];
		num /= base;
		size--;
	}
	return (new_str);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long long		num;
	int				base;
	char			*new_str;

	if (check_base(base_from) <= 1 || (check_base(base_to) <= 1))
		return (0);
	num = ft_atoi_base(nbr, base_from);
	base = check_base(base_to);
	new_str = fill_string(num, base, base_to);
	if (num < 0)
		*new_str = '-';
	return (new_str);
}