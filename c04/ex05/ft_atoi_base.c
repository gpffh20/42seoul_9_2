/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 00:08:00 by eushin            #+#    #+#             */
/*   Updated: 2023/02/16 00:14:03 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_base(char *base)
{
	int	len;
	int	j;

	len = 0;
	while (base[len])
	{
		if (base[len] == '+' || base[len] == '-'
			|| (9 <= base[len] && base[len] <= 13)
			|| base[len] == 32)
			return (0);
		j = 1;
		while (base[len + j])
		{
			if (base[len] == base[len + j])
				return (0);
			j++;
		}
		len++;
	}
	return (len);
}

long long	change_base(char *str, char *base, int base_len, int idx)
{
	int			j;
	int			flag;
	long long	number;

	number = 0;
	while (str[idx])
	{
		j = 0;
		flag = 0;
		while (base[j])
		{
			if (str[idx] == base[j])
			{
				number = number * base_len + j;
				flag = 1;
				break ;
			}
			j++;
		}
		if (flag == 0)
			return (number);
		idx++;
	}
	return (number);
}

int	ft_atoi_base(char *str, char *base)
{
	int			base_len;
	int			i;
	int			flag;
	long long	num;

	base_len = check_base(base);
	if (base_len <= 1)
		return (0);
	i = 0;
	flag = 1;
	num = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			flag *= -1;
		i++;
	}
	num = change_base(str, base, base_len, i);
	return (flag * num);
}
