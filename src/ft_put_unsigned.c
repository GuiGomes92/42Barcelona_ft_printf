/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbraga-g <gbraga-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 20:11:19 by gbraga-g          #+#    #+#             */
/*   Updated: 2022/06/07 18:48:06 by gbraga-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/libft.h"

int	get_len(unsigned int i)
{
	int	len;

	len = 0;
	while (i != 0)
	{
		i = i / 10;
		len++;
	}
	return (len);
}

char	*ft_uitoa(unsigned int num, int len)
{
	char	*ptr;
	int		i;

	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	ptr[len] = '\0';
	i = len - 1;
	while (num != 0)
	{
		ptr[i] = (num % 10) + 48;
		num = num / 10;
		i--;
	}
	return (ptr);
}

int	ft_put_unsigned(unsigned int i)
{
	int		len;
	char	*str;

	if (i == 0)
	{
		len = write(1, "0", 1);
	}
	else
	{
		len = get_len(i);
		str = ft_uitoa(i, len);
		ft_putstr_fd(str, 1);
		free (str);
	}
	return (len);
}
