/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 19:12:05 by zel-hach          #+#    #+#             */
/*   Updated: 2021/12/17 12:24:41 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(int n);
int		ft_putunbr(unsigned int nb);
int		ft_putptr(unsigned long long nb, char *base);
int		ft_puthexa(unsigned int nb, char *base);
int		ft_sharp( va_list ap, const char format);
int		ft_format(va_list ap, const char format);
int		ft_sharp_l(unsigned int nb, char *format);
int		ft_sharp_u(unsigned int nb, char *format);
int		ft_espace(va_list ap, const char format);

#endif
