/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmarti <migmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 09:28:38 by migmarti          #+#    #+#             */
/*   Updated: 2022/12/05 12:25:44 by migmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	print_char(char c);
int	print_string(char *s);
int	print_numb(int nb);
int	print_unsigned(unsigned int nb);
int	print_hexadecimal(unsigned long long nb, char c);
int	print_pointer(unsigned long long nb);
int	ft_printf(const char *s, ...);

#endif
