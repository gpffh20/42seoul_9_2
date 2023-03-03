/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:24:09 by eushin            #+#    #+#             */
/*   Updated: 2023/02/15 14:17:45 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	src_len;
	unsigned int	dst_len;
	unsigned int	idx;

	src_len = 0;
	dst_len = 0;
	idx = 0;
	while (src[src_len])
		src_len++;
	while (dest[dst_len])
		dst_len++;
	if (dst_len < size)
	{
		while ((idx < size - dst_len - 1) && src[idx])
		{
			dest[dst_len + idx] = src[idx];
			idx++;
		}
		dest[dst_len + idx] = 0;
		return (src_len + dst_len);
	}
	else
		return (size + src_len);
}
