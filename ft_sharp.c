/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sharp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 12:26:29 by zel-hach          #+#    #+#             */
/*   Updated: 2021/12/17 12:35:38 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_sharp_l(unsigned int nb, char *format)
{
	int	lenght;

	lenght = 0;
	if (nb == 0)
	lenght += write(1, "0", 1);
	else
	{
	lenght += write(1, "0x", 2);
	lenght += ft_puthexa(nb, format);
	}
	return (lenght);
}

int	ft_sharp_u(unsigned int nb, char *format)
{
	int	lenght;

	lenght = 0;
	if (nb == 0)
		lenght += write(1, "0", 1);
	else
	{
	lenght += write(1, "0X", 2);
	lenght += ft_puthexa(nb, format);
	}
	return (lenght);
}
