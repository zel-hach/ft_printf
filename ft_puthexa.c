/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 14:25:07 by zel-hach          #+#    #+#             */
/*   Updated: 2021/12/16 17:12:12 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_hexadecimal(unsigned int nb)
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

void	print_hexa(unsigned int nb, char *base)
{
	if (nb >= 16)
	{
		print_hexa(nb / 16, base);
		print_hexa(nb % 16, base);
	}
	else
		ft_putchar(base[nb]);
}

int	ft_puthexa(unsigned int nb, char *base)
{
	if (nb == 0)
		return (write(1, "0", 1));
	print_hexa(nb, base);
	return (count_hexadecimal(nb));
}
