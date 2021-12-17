/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 19:05:36 by zel-hach          #+#    #+#             */
/*   Updated: 2021/12/16 17:13:16 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	count_nbr(int nb)
{
	int	count;

	count = 0;
	if (nb == 0)
		count = 1;
	if (nb < 0)
		count += 1;
	while (nb != 0)
	{
		count ++;
		nb = nb / 10;
	}
	return (count);
}

int	ft_putnbr(int n)
{
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(n * (-1));
	}
	else if (n >= 0 && n <= 9)
		ft_putchar(n + 48);
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	return (count_nbr(n));
}
