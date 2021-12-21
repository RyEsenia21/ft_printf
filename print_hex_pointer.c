/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryesenia <ryesenia@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 21:31:10 by ryesenia          #+#    #+#             */
/*   Updated: 2021/12/21 18:08:01 by ryesenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(char a, int fd)
{
	write (fd, &a, 1);
}

int	schet_simvolov(long long int a)
{
	int	i;

	i = 0;
	if (a == 0)
		return (1);
	if (a < 0)
	{	
		a = -a;
		i = 1;
	}	
	while (a > 0)
	{
		a = (a / 10);
		i++;
	}
	return (i);
}

int	ft_strlen(char *d)
{
	int	i;

	i = 0;
	while (d[i] != '\0')
		i++;
	return (i);
}

void	print_hex(unsigned int num, char c, int *count)
{
	static const char	upper[] = "0123456789ABCDEF";
	static const char	lower[] = "0123456789abcdef";

	if (num / 16)
		print_hex(num / 16, c, count);
	(*count)++;
	if (c == 'x')
		ft_putchar_fd(lower[num % 16], 1);
	else
		ft_putchar_fd(upper[num % 16], 1);
}

void	print_hex_pointer(unsigned long long int num, char c, int *count)
{
	static const char	upper[] = "0123456789ABCDEF";
	static const char	lower[] = "0123456789abcdef";

	if (num / 16)
		print_hex_pointer(num / 16, c, count);
	(*count)++;
	if (c == 'x')
		ft_putchar_fd(lower[num % 16], 1);
	else
		ft_putchar_fd(upper[num % 16], 1);
}
