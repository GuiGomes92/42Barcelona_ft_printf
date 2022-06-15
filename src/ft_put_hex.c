/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbraga-g <gbraga-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 20:21:51 by gbraga-g          #+#    #+#             */
/*   Updated: 2022/06/10 18:19:35 by gbraga-g         ###   ########.fr       */
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

void	ft_convert_hex(int num, char type)
{
	if (num <= 9)
		ft_putchar_fd((num + '0'), 1);
	else
	{
		if (type == 'x')
			ft_putchar_fd((num - 10 + 'a'), 1);
		else if (type == 'X')
			ft_putchar_fd((num - 10 + 'A'), 1);
	}
}

int	ft_put_int_hex(unsigned int i, char type)
{
	if (i == 0)
	{
		write(1, "0", 1);
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
			ft_convert_hex(i, type);
	}
	return (get_num_len(i));
}
