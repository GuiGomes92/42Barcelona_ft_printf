/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbraga-g <gbraga-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 20:11:19 by gbraga-g          #+#    #+#             */
/*   Updated: 2022/06/03 18:46:07 by gbraga-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/libft.h"

int ft_put_unsigned(unsigned int i)
{            
	char	c;
	int		len;
	
	len = 0;
	if (i >= 10)
	{           
		ft_putint(i / 10);
		ft_putint(i % 10);
	}           
	else        
	{           
		c = i + '0';    
		len += write(1, &c, 1);
	}
	return (len);
}  
