/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbraga-g <gbraga-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:17:10 by gbraga-g          #+#    #+#             */
/*   Updated: 2022/05/16 15:21:34 by gbraga-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (needle[0] == '\0')
		return ((char *)haystack);
	i = 0;
	j = 1;
	while (*haystack && (j + i) <= len)
	{
		if (haystack[i] == needle[i])
		{
			if (needle[++i] == '\0')
				return ((char *)haystack);
		}
		else
		{
			haystack++;
			j++;
			i = 0;
		}
	}
	return (NULL);
}
