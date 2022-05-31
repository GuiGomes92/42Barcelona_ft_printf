/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbraga-g <gbraga-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 21:09:42 by gbraga-g          #+#    #+#             */
/*   Updated: 2022/05/31 21:16:49 by gbraga-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFT_H
# define FT_LIBFT_H
# include <stdint.h>
# include <stdarg.h>

int ft_printf(const char *str, ...);
int ft_check_type(va_list arg, char type);
void ft_putchar(int c);
void ft_putstr(char *str);
int ft_putint(int i);
int get_num_len(int num);
char *ft_convert_hex(int num);
int ft_put_int_hex(int i, char type);
int ft_convert_ptr(uintptr_t ptr);
int ft_put_ptr(unsigned long long ptr);
int ft_put_unsigned(unsigned int i);

#endif
