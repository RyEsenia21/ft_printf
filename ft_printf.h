/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryesenia <ryesenia@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 19:11:19 by ryesenia          #+#    #+#             */
/*   Updated: 2021/12/21 18:20:24 by ryesenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

void	ft_putchar_fd(char a, int fd);

int		schet_simvolov(long long int a);

int		ft_strlen(char *d);

void	print_hex(unsigned int num, char c, int *count);

void	ft_putstr(char *f);

void	ft_putnbr_fd(long long int n, int fd);

int		print_int(va_list pereskok);

int		print_char(va_list pereskok);

int		print_stroka(va_list pereskok);

int		print_uint(va_list pereskok);

int		print_pointer(va_list pereskok);

int		print_heximal(va_list pereskok, char flag);

int		flag_definition(const char *stroka, va_list pereskok);

int		ft_printf(const char *str, ...);

void	print_hex_pointer(unsigned long long int num, char c, int *count);

#endif
