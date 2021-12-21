/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryesenia <ryesenia@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 19:11:33 by ryesenia          #+#    #+#             */
/*   Updated: 2021/12/21 18:18:24 by ryesenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_uint(va_list pereskok)
{
	int				count;
	unsigned int	u;

	count = 0;
	u = va_arg(pereskok, unsigned int);
	count = schet_simvolov(u);
	ft_putnbr_fd(u, 1);
	return (count);
}

int	print_pointer(va_list pereskok)
{
	int		count;
	void	*p;

	count = 2;
	p = va_arg(pereskok, void *);
	ft_putstr("0x");
	print_hex_pointer ((unsigned long long int)p, 'x', &count);
	return (count);
}

int	print_heximal(va_list pereskok, char flag)
{
	int				count;
	unsigned int	number;

	count = 0;
	number = va_arg(pereskok, unsigned int);
	print_hex(number, flag, &count);
	return (count);
}

int	flag_definition(const char *stroka, va_list pereskok)
{
	int	i;

	i = 0;
	if (stroka[0] == 'd' || stroka[0] == 'i')
		i = print_int(pereskok);
	else if (stroka[0] == 'c')
		i = print_char(pereskok);
	else if (stroka[0] == 's')
		i = print_stroka(pereskok);
	else if (stroka[0] == 'u')
		i = print_uint(pereskok);
	else if (stroka[0] == 'x' || stroka[0] == 'X')
		i = print_heximal(pereskok, stroka[0]);
	else if (stroka[0] == 'p')
		i = print_pointer(pereskok);
	else if (stroka[0] == '%')
	{
		ft_putchar_fd('%', 1);
		i = 1;
	}
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	int		i;
	va_list	pereskok;

	i = 0;
	count = 0;
	va_start(pereskok, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			count += flag_definition(&str[++i], pereskok);
			if (str[i] == '\0')
				break ;
		}
		else
		{		
			ft_putchar_fd(str[i], 1);
			count++;
		}			
		i++;
	}
	va_end (pereskok);
	return (count);
}
