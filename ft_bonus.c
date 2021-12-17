/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 20:44:22 by zel-hach          #+#    #+#             */
/*   Updated: 2021/12/17 12:27:25 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_plus(int n)
{
	int	lenght;

	lenght = 0;
	if (n < 0)
		lenght += ft_putnbr(n);
	else
	{
		lenght += write(1, "+", 1);
		lenght += ft_putnbr(n);
	}
	return (lenght);
}

int	ft_putnbr_espace(int n)
{
	int	lenght;

	lenght = 0;
	if (n < 0)
		lenght += ft_putnbr(n);
	else
	{
		lenght += write(1, " ", 1);
		lenght += ft_putnbr(n);
	}
	return (lenght);
}

int	ft_sharp(va_list ap, const char format)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (format == 'x')
		count += ft_sharp_l(va_arg(ap, unsigned int), "0123456789abcdef");
	if (format == 'X')
		count += ft_sharp_u(va_arg(ap, unsigned int), "0123456789ABCDEF");
	if (format == 'd' || format == 'i')
		count += ft_putnbr_plus(va_arg(ap, int));
	return (count);
}

int	ft_espace(va_list ap, const char format)
{
	int	count;

	count = 0;
	if (format == 'd' || format == 'i')
	{
		count += ft_putnbr_espace(va_arg(ap, int));
	}
	else if (format == 's')
	{
		count += ft_putstr(va_arg(ap, char *));
	}
	return (count);
}
