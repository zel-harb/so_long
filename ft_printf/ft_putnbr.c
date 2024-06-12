/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:15:44 by zel-harb          #+#    #+#             */
/*   Updated: 2023/12/07 09:23:29 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *len)
{
	if (n == -2147483648)
		ft_putstr("-2147483648", len);
	else
	{
		if (n < 0)
		{
			ft_putchar('-', len);
			n = -n;
		}
		if (n < 10)
			ft_putchar(n + '0', len);
		else
		{
			ft_putnbr(n / 10, len);
			ft_putnbr(n % 10, len);
		}
	}
}
