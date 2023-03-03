/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:30:46 by eushin            #+#    #+#             */
/*   Updated: 2023/02/13 18:17:45 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ('A' <= str[i] && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	if ('a' <= str[0] && str[0] <= 'z')
		str[0] -= 32;
	i = 1;
	while (str[i])
	{
		if (!('a' <= str[i - 1] && str[i - 1] <= 'z')
			&& !('A' <= str[i - 1] && str[i - 1] <= 'Z')
			&& !('0' <= str[i - 1] && str[i - 1] <= '9'))
		{
			if ('a' <= str[i] && str[i] <= 'z')
				str[i] -= 32;
		}
		i++;
	}
	return (str);
}
