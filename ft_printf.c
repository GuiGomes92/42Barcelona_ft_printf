/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbraga-g <gbraga-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:27:54 by gbraga-g          #+#    #+#             */
/*   Updated: 2022/05/31 16:18:14 by gbraga-g         ###   ########.fr       */
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
}

static int ft_put_ptr(unsigned long long ptr)
{
	write(1, "0x", 2);
	ft_put_nb(ptr);	
	return (0);
}

static int ft_put_int_hex(int i, char type)
{
	int		mod;
	int		len;
	int		j;
	char	*str;
	const char	hex[] = "0123456789abcdef";
		
	j = i;
	len = 0;
	while (j > 0)
	{
		j = j / 16;
		len++;
	}
	str = malloc(len + 1 * sizeof(char));
	str[len] = '\0';
	while (i > 0)
	{
		len--;
		mod = i % 16;
		str[len] = hex[mod];
		i = i / 16;
	}
	j = 0; 
	if (type == 'x')
	{
		while (str[j] != '\0')
		{
			str[j] = ft_tolower(str[j]);
			j++;
		}
	}
	else if (type == 'X')
	{
		while (str[j] != '\0')
        {
            str[j] = ft_toupper(str[j]);
			j++;
        }
	}
	ft_putstr_fd(str, 1);
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
	//printf("System: %x\n", num_hex); 
}
