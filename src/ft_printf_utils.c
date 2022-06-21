/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbraga-g <gbraga-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 20:06:35 by gbraga-g          #+#    #+#             */
/*   Updated: 2022/06/21 13:12:35 by gbraga-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/libft.h"

int	ft_putchar(int c)
{
	if (write(1, &c, 1) != 1)
		return (-1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		if (write(1, "(null)", 6) != 6)
			return (-1);
		return (6);
	}
	while (str[i] != '\0')
	{
		if (ft_putchar(str[i]) != 1)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_putint(int i)
{
	int	len;

	len = 0;
	if (i == -2147483648)
	{
		if (write(1, "-2147483648", 11) != 11)
			return (-1);
		return (11);
	}
	if (i < 0)
	{
		if (write(1, "-", 1) != 1)
			return (-1);
		i = i * (-1);
		len++;
	}
	if (i >= 10)
	{
		len += ft_putint(i / 10);
		if (len == -1)
			return (-1);
		i = i % 10;
	}
	if (i < 10)
	{
		if (ft_putchar(i + '0') != 1)
			return (-1);
		len++;
	}
	return (len);
}
