/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stroka.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryesenia <ryesenia@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 21:32:28 by ryesenia          #+#    #+#             */
/*   Updated: 2021/12/21 18:10:47 by ryesenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *f)
{
	int	p;

	p = ft_strlen(f);
	write(1, f, p);
}

void	ft_putnbr_fd(long long int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}

int	print_int(va_list pereskok)
{
	int	count;
	int	number;

	count = 0;
	number = va_arg(pereskok, int);
	count = schet_simvolov(number);
	ft_putnbr_fd(number, 1);
	return (count);
}

int	print_char(va_list pereskok)
{
	int	c;

	c = va_arg(pereskok, int);
	ft_putchar_fd(c, 1);
	return (1);
}

int	print_stroka(va_list pereskok)
{
	char	*s;

	s = va_arg(pereskok, char *);
	if (s == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	ft_putstr(s);
	return (ft_strlen(s));
}
