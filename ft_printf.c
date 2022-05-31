/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbraga-g <gbraga-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:27:54 by gbraga-g          #+#    #+#             */
/*   Updated: 2022/05/31 17:33:01 by gbraga-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int ft_check_type(va_list arg, char type)
{
	if (type == 'c')
		ft_putchar(va_arg(arg, int));
	else if (type == '%')
		ft_putchar('%');
	else if (type == 's')
		ft_putstr(va_arg(arg, char *));
	else if (type == 'i' || type == 'd')
		ft_putint(va_arg(arg, int));
	else if (type == 'u')
		ft_put_unsigned(va_arg(arg, unsigned int));
	else if (type == 'p')
		ft_put_ptr(va_arg(arg, unsigned long long));
	else if (type == 'x' || type == 'X')
		ft_put_int_hex(va_arg(arg, int), type);
	return (0);
}

int ft_printf(const char *str, ...)
{
	va_list arg;
	int		i;
	
	i = 0;
	va_start(arg, str);
	while (str[i] != '\0')
	{
		if(str[i] == '%')
		{
			ft_check_type(arg, str[i + 1]);
			i++;
		}
		else
			ft_putchar(str[i]);
		i++;
	}
	va_end(arg);
	return (0);
}

int main(void)
{
	int	i = 128l;
	void	*p;

	p = &i;
	ft_printf("Mine ptr: %p\n", p);
	printf("System ptr: %p\n", p);
}
