/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbraga-g <gbraga-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:06:25 by gbraga-g          #+#    #+#             */
/*   Updated: 2022/06/07 17:16:06 by gbraga-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static char	*ft_malloc(int len)
{
	char	*ptr;

	ptr = (char *)malloc((len + 1) * sizeof(char));
	return (ptr);
}

static int	ft_getlen(int len, int n)
{
	if (n >= 0 && n <= 9)
	{
		len = len + 1;
		return (len);
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*ft_fillmem(char *ptr, int n, int neg, int len)
{
	int	i;

	i = len - 1;
	while (i >= neg)
	{
		ptr[i] = (n % 10) + 48;
		n = n / 10;
		i--;
	}
	ptr[len] = '\0';
	return (ptr);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		len;
	int		neg;

	len = 0;
	neg = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		n = n * -1;
		neg = 1;
		len++;
	}
	len = ft_getlen(len, n);
	ptr = ft_malloc(len);
	if (ptr == NULL)
		return (NULL);
	if (neg)
		ptr[0] = '-';
	ptr = ft_fillmem(ptr, n, neg, len);
	return (ptr);
}
