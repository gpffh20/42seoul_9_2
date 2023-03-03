/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 02:51:16 by eushin            #+#    #+#             */
/*   Updated: 2023/03/01 14:24:25 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_atoi(char *str);
int		plus(int num1, int num2);
int		minus(int num1, int num2);
int		multiple(int num1, int num2);
int		division(int num1, int num2);
int		modulo(int num1, int num2);
void	ft_putnbr(int nb);

int	ft_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	print_error(int n)
{
	if (n == 1)
		write(2, "Stop : division by zero", 23);
	if (n == 2)
		write(2, "Stop : modulo by zero", 21);
	return (0);
}

int	calculate(int num1, int num2, char c, int (*op[5])(int, int))
{

	if (c == '+')
		ft_putnbr(op[0](num1, num2));
	else if (c == '-')
		ft_putnbr(op[1](num1, num2));
	else if (c == '*')
		ft_putnbr(op[2](num1, num2));
	else if (c == '/')
	{
		if (num2 == 0)
			return (print_error(1));
		ft_putnbr(op[3](num1, num2));
	}
	else if (c == '%')
	{
		if (num2 == 0)
			return (print_error(2));
		ft_putnbr(op[4](num1, num2));
	}
	else
		write(1, "0", 1);
	return (0);
}

int	main(int ac, char *av[])
{
	int	num1;
	int	num2;
	int	(*op[5])(int, int);

	if (ac != 4)
		return (0);
	num1 = ft_atoi(av[1]);
	num2 = ft_atoi(av[3]);
	op[0] = plus;
	op[1] = minus;
	op[2] = multiple;
	op[3] = division;
	op[4] = modulo;
	if (ft_len(av[2]) != 1)
	{
		write(1, "0\n", 2);
		return (0);
	}
	calculate(num1, num2, av[2][0], op);
	write(1, "\n", 1);
	return (0);
}
