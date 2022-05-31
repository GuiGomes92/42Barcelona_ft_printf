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

static int get_num_len(int num)
{
	int	len;
	len = 0;

	while (num > 0)
	{
		num = num / 16;
		len++;
	}
	return (len);
}

static char	*ft_convert_hex(int num)
{
	int     mod;
	int     j;
	int		len;
	char    *str;
	const char  hex[] = "0123456789abcdef";

	j = num;
	len = get_num_len(num);
	str = malloc(len + 1 * sizeof(char));
	str[len] = '\0';
	while (j > 0)
	{   
		len--;
		mod = j % 16;
		str[len] = hex[mod];
		j = j / 16;
	}
	return (str);	
}

static int ft_convert_ptr(uintptr_t ptr)
{
	char    	*str;
	int			len;
	uintptr_t	num;
	int			mod;
	const char  hex[] = "0123456789abcdef";

	num = ptr;
	len = 0;
	while (num > 0)
	{   
		num = num / 16;
		len++;
	}
	str = malloc(len + 1 * sizeof(char));
	str[len] = '\0';
	num = ptr;
	while (num > 0)
	{
		len--;
		mod = num % 16;
		str[len] = hex[mod];
		num = num / 16;
	}
	ft_putstr_fd(str, 1);
	return (len);
}

static int ft_put_ptr(unsigned long long ptr)
{
	write(1, "0x", 2);
	ft_convert_ptr(ptr);	
	return (0);
}

static int ft_put_int_hex(int i, char type)
{
	int		j;
	int		len;
	char	*str;
	
	j = 0;
	len = get_num_len(i);
	str = ft_convert_hex(i);
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
	int	i = 128l;
	void	*p;

	p = &i;
	ft_printf("Mine ptr: %p\n", p);
	printf("System ptr: %p\n", p);
}
