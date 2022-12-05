/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmarti <migmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:08:27 by migmarti          #+#    #+#             */
/*   Updated: 2022/12/05 12:25:02 by migmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/* %s */

int	print_string(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[i])
		write (1, &s[i++], 1);
	return (i);
}
/* %i, %d */

int	print_numb(int nb)
{
	int	count;

	count = 0;
	if (nb < 0)
	{
		count += print_char('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		count += print_numbs(nb / 10);
		count += print_numbs(nb % 10);
	}
	if (nb < 10)
		count += print_char(nb + 48);
	return (count);
}
/* %u */

int	print_unsigned(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb < 10)
		count += print_char(nb + 48);
	if (nb >= 10)
	{
		count += print_unsigned(nb / 10);
		count += print_unsigned(nb % 10);
	}
	return (count);
}
/* %x, %X */

int	print_hexadecimal(unsigned long long nb, char c)
{
	int		count;
	char	*hexa;

	count = 0;
	if (c == 'x')
		hexa = "0123456789abcdef";
	if (c == 'X')
		hexa = "0123456789ABCDEF";
	if (nb < 16)
		count += print_char(hexa[nb]);
	if (nb >= 16)
	{
		count += print_hexadecimal(nb / 16, c);
		count += print_hexadecimal(nb % 16, c);
	}
	return (count);
}
/* %p */
/* x para imprimir minuscula */

int	print_pointer(unsigned long long nb)
{
	int	count;

	count = 0;
	if (!nb)
		write(1, "(nill)", 5);
	else
		write(1, "0x", 2);
	count += print_hexadecimal(nb, 'x');
	return (count + 2);
}
