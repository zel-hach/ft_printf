/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 20:21:11 by zel-hach          #+#    #+#             */
/*   Updated: 2021/12/16 17:12:34 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_ptr(unsigned long long nb)
{
	int	count;

	count = 0;
	while (nb != 0)
	{
		count ++;
		nb = nb / 16;
	}
	return (count);
}

void	print_ptr(unsigned long long nb, const char *base)
{
	if (nb >= 16)
	{
		print_ptr(nb / 16, base);
		print_ptr(nb % 16, base);
	}
	else
		ft_putchar(base[nb]);
}

int	ft_putptr(unsigned long long nb, char *base)
{
	int	count;

	count = 0;
	count += write(1, "0x", 2);
	if (nb == 0)
	{
		write(1, "0", 1);
		count++;
	}
	else
	{
		print_ptr(nb, base);
		count += count_ptr(nb);
	}
	return (count);
}
