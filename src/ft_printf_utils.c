/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbraga-g <gbraga-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 20:06:35 by gbraga-g          #+#    #+#             */
/*   Updated: 2022/06/21 17:56:28 by gbraga-g         ###   ########.fr       */
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

int	ft_putint(int j)
{
	char	*num;
	int		len;

	num = ft_itoa(j);
	if (!num)
		return (-1);
	len = ft_putstr(num);
	free (num);
	return (len);
}
