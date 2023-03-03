/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:44:24 by eushin            #+#    #+#             */
/*   Updated: 2023/03/02 20:15:49 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	read_buff(char buff[20], char *filename)
{
	int	fd;
	int	i;

	fd = open(filename, O_RDONLY);
	if (fd < 0 || read(fd, buff, 19))
	{
		write(2, "Cannot read file.\n", 18);
		return ;
	}
	if (read(fd, buff, 18))
		buff[19] = 0;
	return ;
}

int	main(int ac, char *av[])
{
	char	buff[20];

	if (ac == 1)
	{
		write(2, "File name missing.\n", 19);
		return (0);
	}
	if (ac >= 3)
	{
		write(2, "Too many arguments.\n", 20);
		return (0);
	}
	read_buff(buff, av[1]);
	return (0);
}
