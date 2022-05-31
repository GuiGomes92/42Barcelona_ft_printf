/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbraga-g <gbraga-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 20:06:35 by gbraga-g          #+#    #+#             */
/*   Updated: 2022/05/31 20:09:53 by gbraga-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void ft_putchar(int c)
{
	write(1, &c, 1);
}

static void ft_putstr(char *str)
{
	int i;

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
