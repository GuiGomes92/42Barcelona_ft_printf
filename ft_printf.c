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

static void ft_put_nb(uintptr_t ptr)
{
	// Putting numbers backwords: fix it.
	uintptr_t temp;
	while (ptr > 0)
	{
		temp = ptr % 16;
		if (temp <= 9)
			ft_putchar_fd((temp + '0'), 1);
		else
			ft_putchar_fd((temp - 10 + 'a'), 1);
		ptr = ptr / 16;
	}
	/*
	if (ptr >= 16)
	{
		ft_put_nb(ptr / 16);
		ft_put_nb(ptr % 16);
	}
	else 
	{
		if (ptr <= 9)
			ft_putchar_fd((ptr + '0'), 1);
		else
		{
			ft_putchar_fd((ptr - 10 + 'a'), 1);
		}
	}
	*/
}

static int ft_put_ptr(unsigned long long ptr)
{
	write(1, "0x", 2);
	ft_put_nb(ptr);	
	return (0);
}

static int ft_put_int_hex(int i, char type)
{
	// Divide by 16
	// mod the number 
	// if < 9 print number
	// if >= 10 print number plus a
	int	mod;
	while (i > 0)
	{
		mod = i % 16;

		if (mod <= 9)
			ft_putchar_fd((mod + '0'), 1);
		else
		{
			ft_putchar_fd((mod - 10 + 'a'), 1);	
		}
		i = i / 16;
	}
	printf("%c", type);
	/*
	if (type == 'x')
		printf("x %i", i);
	if (type == 'X')
		printf("X %i", i);
	*/
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
	/*
	int		i = 23;
	int		k = 40;
	void	*p;
	p = &i;
	char	c = 'B';
	char	*str = "Que tal?";
	unsigned int j = 35;
	*/
	int     num_hex = 1128;
	/*
	ft_printf("Char: %c\n", c);
	ft_printf("Percentage: %%\n", c);
	ft_printf("String: %s\n", str);
	ft_printf("Integer: %i %i\n", i, k);
	ft_printf("Unsigned Int: %u\n", j);
	ft_printf("Ptr Hex: %p\n", p);
	printf("System: %p\n", p);
	*/
	ft_printf("Mine: %x\n", num_hex);
	printf("System: %x\n", num_hex); 
}
/*
• %x Prints a number in hexadecimal (base 16) lowercase format.
• %X Prints a number in hexadecimal (base 16) uppercase format.
*/
