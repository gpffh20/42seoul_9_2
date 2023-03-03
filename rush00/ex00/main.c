/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 11:47:17 by eushin            #+#    #+#             */
/*   Updated: 2023/02/12 16:53:09 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_rush(int x, int y);

int	ft_atoi(const char *str)
{
	int			i;
	int			is_valid;
	long long	num;

	i = 0;
	num = 0;
	is_valid = 0;
	if (str[i] == '+')
		i++;
	while ('0' <= str[i] && str[i] <= '9')
	{
		is_valid = 1;
		num = num * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] != 0)
		return (0);
	if (is_valid != 1)
		return (0);
	if (num > 2147483647)
		return (0);
	return (num);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	main(int argc, char *argv[])
{
	int	x;
	int	y;

	if (argc != 3)
		return (0);
	if (ft_strlen(argv[1]) > 12 || ft_strlen(argv[2]) > 12)
		return (0);
	x = ft_atoi(argv[1]);
	y = ft_atoi(argv[2]);
	if (x == 0 || y == 0)
		return (0);
	ft_rush(x, y);
	return (0);
}
