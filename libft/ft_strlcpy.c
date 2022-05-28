/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbraga-g <gbraga-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:36:24 by gbraga-g          #+#    #+#             */
/*   Updated: 2022/05/11 17:48:41 by gbraga-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	srclen;

	srclen = ft_strlen(src);
	i = 0;
	if (!dstsize)
		return (srclen);
	if (dstsize > 0)
	{
		while (i != dstsize - 1)
		{
			if (src[i] != '\0')
			{
				dst[i] = src[i];
			}
			else
			{
				break ;
			}
			i++;
		}
		dst[i] = '\0';
	}
	return (srclen);
}
