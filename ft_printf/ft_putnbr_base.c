/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:15:36 by zel-harb          #+#    #+#             */
/*   Updated: 2023/12/07 23:33:16 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(unsigned int nbr, char Xx, int *len)
{
	char			*base;

	if (Xx == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (nbr < 16)
		ft_putchar(base[nbr], len);
	else
	{
		ft_putnbr_base(nbr / 16, Xx, len);
		ft_putnbr_base(nbr % 16, Xx, len);
	}
}
