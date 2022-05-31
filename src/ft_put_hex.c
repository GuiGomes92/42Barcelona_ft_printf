/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbraga-g <gbraga-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 20:21:51 by gbraga-g          #+#    #+#             */
/*   Updated: 2022/05/31 20:29:12 by gbraga-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int get_num_len(int num)
{
	int len;
	
	len = 0;
	while (num > 0)
	{
		num = num / 16;
		len++;
	}
	return (len);
}  

static char *ft_convert_hex(int num)
{
	int     mod;
	int     j;
	int     len;
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

static int ft_put_int_hex(int i, char type)
{   
	int     j;
	int     len;                                                        
	char    *str;

	j = 0;
	len = get_num_len(i);
	str = ft_convert_hex(i);
	while (str[j] != '\0')
	{
		if (type == 'x')
			str[j] = ft_tolower(str[j]);
		else if (type == 'X')
			str[j] = ft_toupper(str[j]);
		j++;
	}
	ft_putstr_fd(str, 1);
	return (0);
}  
