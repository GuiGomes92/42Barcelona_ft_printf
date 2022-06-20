/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbraga-g <gbraga-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:27:54 by gbraga-g          #+#    #+#             */
/*   Updated: 2022/06/20 18:22:29 by gbraga-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_type(va_list arg, char type)
{
	if (type == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if (type == '%')
		return (ft_putchar('%'));
	else if (type == 's')
		return (ft_putstr(va_arg(arg, char *)));
	else if (type == 'i' || type == 'd')
		return (ft_putint(va_arg(arg, int)));
	else if (type == 'u')
		return (ft_put_unsigned(va_arg(arg, unsigned int)));
	else if (type == 'p')
		return (ft_put_ptr(va_arg(arg, unsigned long long)));
	else if (type == 'x' || type == 'X')
		return (ft_put_int_hex(va_arg(arg, unsigned int), type));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;
	int		len;
	int		res;

	res = 0;
	i = 0;
	len = 0;
	va_start(arg, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			res = ft_check_type(arg, str[i + 1]);
			if (res == -1)
				return (-1);
			len += res;
			i++;
		}
		else
		{
			if (ft_putchar(str[i]) != 1)
				return (-1);
			len++;
		}
		i++;
	}
	va_end(arg);
	return (len);
}
