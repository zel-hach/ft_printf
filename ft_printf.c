/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 18:45:11 by zel-hach          #+#    #+#             */
/*   Updated: 2021/12/17 14:32:13 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list ap, const char format)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += ft_putchar(va_arg(ap, int ));
	else if (format == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (format == 'p')
		count += ft_putptr((unsigned long long)va_arg(ap, void *),
				"0123456789abcdef");
	else if (format == 'd' || format == 'i')
		count += ft_putnbr(va_arg(ap, int));
	else if (format == 'u')
		count += ft_putunbr(va_arg(ap, unsigned int));
	else if (format == 'x')
		count += ft_puthexa(va_arg(ap, unsigned int),
				"0123456789abcdef");
	else if (format == 'X')
		count += ft_puthexa(va_arg(ap, unsigned int),
				"0123456789ABCDEF");
	else if (format == '%')
		count += write(1, "%", 1);
	return (count);
}

int	ft_prr(const char *format, int *i, va_list ap)
{
	int	print_count;

	print_count = 0;
	if (format[*i + 1] == '#' || format[*i + 1] == '+')
	{
		while (format[*i + 1] == '#' || format[*i + 1] == '+')
			*i = *i + 1;
		print_count += ft_sharp(ap, format[*i + 1]);
		*i = *i + 1;
	}
	else if (format[*i + 1] == ' ')
	{
		while (format[*i + 1] == ' ')
			*i = *i + 1;
		print_count += ft_espace(ap, format[*i + 1]);
		*i = *i + 1;
	}
	else
	{
		*i = *i + 1;
		print_count += ft_format(ap, format[*i]);
	}
	return (print_count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		print_count;

	i = 0;
	print_count = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
			print_count += ft_prr(format, &i, ap);
		else
			print_count += ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (print_count);
}
