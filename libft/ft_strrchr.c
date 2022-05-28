/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbraga-g <gbraga-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 12:58:59 by gbraga-g          #+#    #+#             */
/*   Updated: 2022/05/12 15:42:56 by gbraga-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			len;
	int			i;
	const char	*p;

	len = ft_strlen(s);
	p = s + len;
	i = len;
	if (!s)
		return (0);
	while (i >= 0)
	{
		if (*p == (char)c)
			return ((char *)p);
		p--;
		i--;
	}
	return (0);
}
