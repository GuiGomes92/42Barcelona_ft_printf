/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbraga-g <gbraga-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 21:09:42 by gbraga-g          #+#    #+#             */
/*   Updated: 2022/06/07 18:55:01 by gbraga-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdint.h>
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
int		ft_check_type(va_list arg, char type);
int		ft_putchar(int c);
int		ft_putstr(char *str);
int		ft_putint(int i);
int		get_num_len(unsigned int num);
void	ft_convert_hex(int num, char type);
int		ft_put_int_hex(unsigned int i, char type);
int		ft_convert_ptr(uintptr_t ptr);
int		ft_put_ptr(unsigned long long ptr);
int		ft_put_unsigned(unsigned int i);
int		get_len(unsigned int i);
char	*ft_uitoa(unsigned int num, int len);
int		ft_put_unsigned(unsigned int i);

#endif
