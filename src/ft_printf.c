/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbraga-g <gbraga-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:27:54 by gbraga-g          #+#    #+#             */
/*   Updated: 2022/06/07 18:40:02 by gbraga-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_type(va_list arg, char type)
{
	int	len;

	len = 0;
	if (type == 'c')
		len += ft_putchar(va_arg(arg, int));
	else if (type == '%')
		len += ft_putchar('%');
	else if (type == 's')
		len += ft_putstr(va_arg(arg, char *));
	else if (type == 'i' || type == 'd')
		len += ft_putint(va_arg(arg, int));
	else if (type == 'u')
		len += ft_put_unsigned(va_arg(arg, unsigned int));
	else if (type == 'p')
		len += ft_put_ptr(va_arg(arg, unsigned long long));
	else if (type == 'x' || type == 'X')
		len += ft_put_int_hex(va_arg(arg, int), type);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(arg, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			len += ft_check_type(arg, str[i + 1]);
			i++;
		}
		else
			len += ft_putchar(str[i]);
		i++;
	}
	va_end(arg);
	return (len);
}
