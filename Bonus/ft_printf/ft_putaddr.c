/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 02:07:12 by zel-harb          #+#    #+#             */
/*   Updated: 2023/12/07 23:14:51 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putaddr_hex(unsigned long nbr, int *len)
{
	char	*base;

	base = "0123456789abcdef";
	if (nbr < 16)
		ft_putchar(base[nbr], len);
	else
	{
		ft_putaddr_hex(nbr / 16, len);
		ft_putaddr_hex(nbr % 16, len);
	}
}

void	ft_putaddr(void *addr, int *len)
{
	unsigned long	ptr;

	ptr = (unsigned long)addr;
	ft_putstr("0x", len);
	ft_putaddr_hex(ptr, len);
}
