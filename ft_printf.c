/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbraga-g <gbraga-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:27:54 by gbraga-g          #+#    #+#             */
/*   Updated: 2022/05/28 18:21:48 by gbraga-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void ft_putchar(int c)
{
	write(1, &c, 1);
}

static void ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

static int ft_putint(int i)
{
	ft_putnbr_fd(i, 1);
	return (0);
}

static int ft_put_unsigned(unsigned int i)
{
	char c;

	//if (i >= 0 && i <= 9)
	//	write(1, &i, 1);
	//	Put numbers less than 10;
	if (i >= 10)
	{
		ft_putint(i / 10);
		ft_putint(i % 10);
	}
	else
	{
		c = i + '0';
		write(1, &c, 1);
	}
	return (0);
}

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
	int	i = 23;
	char c = 'B';
	char *str = "Que tal?";
	unsigned int j = 35;
	ft_printf("Hello %c\n", c);
	ft_printf("Hello %%\n", c);
	ft_printf("Hello %s\n", str);
	ft_printf("Hello, %i\n" , i);
	ft_printf("Hello, %u\n", j);

}
/*
• %p The void * pointer argument has to be printed in hexadecimal format.
• %x Prints a number in hexadecimal (base 16) lowercase format.
• %X Prints a number in hexadecimal (base 16) uppercase format.
*/
