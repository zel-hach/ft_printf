/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 20:22:11 by zel-hach          #+#    #+#             */
/*   Updated: 2021/12/16 17:10:14 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb < 10)
		count += ft_putchar(nb + '0');
	else
	{
		count += ft_putunbr(nb / 10);
		count += ft_putunbr(nb % 10);
	}
	return (count);
}
