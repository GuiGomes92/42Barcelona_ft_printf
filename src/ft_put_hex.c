/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbraga-g <gbraga-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 20:21:51 by gbraga-g          #+#    #+#             */
/*   Updated: 2022/06/20 21:42:16 by gbraga-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/libft.h"

int	get_num_len(unsigned int num)
{
	unsigned int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

int	ft_convert_hex(int num, char type)
{
	int		c;
	char	x;

	if (type == 'x')
		x = 'a';
	else if (type == 'X')
		x = 'A';
	if (num <= 9)
	{
		c = num + '0';
		if (write(1, &c, 1) != 1)
			return (-1);
	}
	else
	{
		c = (num - 10) + x;
		if (write(1, &c, 1) != 1)
			return (-1);
	}
	return (0);
}

int	ft_put_int_hex(unsigned int i, char type)
{
	if (i == 0)
	{
		if (write(1, "0", 1) != 1)
			return (-1);
		return (1);
	}
	else
	{
		if (i >= 16)
		{
			ft_put_int_hex((i / 16), type);
			ft_put_int_hex((i % 16), type);
		}
		else
		{
			if (ft_convert_hex(i, type) == -1)
				return (-1);
		}
	}
	return (get_num_len(i));
}
