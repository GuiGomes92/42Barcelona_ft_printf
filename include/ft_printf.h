/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbraga-g <gbraga-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 21:09:42 by gbraga-g          #+#    #+#             */
/*   Updated: 2022/06/21 18:14:23 by gbraga-g         ###   ########.fr       */
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
int		ft_protect_func(const char *str, va_list arg, int len);
int		ft_putchar(int c);
int		ft_putstr(char *str);
int		ft_putint(int j);
int		get_num_len(unsigned int num);
int		ft_convert_hex(int num, char type);
int		ft_put_int_hex(unsigned int i, char type);
int		get_ptr_len(unsigned long long ptr);
int		ft_puthex(unsigned long long ptr);
int		ft_put_ptr(unsigned long long ptr);
int		get_len(unsigned int i);
int		ft_put_unsigned(unsigned int i);
char	*ft_uitoa(unsigned int num, int len);

#endif
