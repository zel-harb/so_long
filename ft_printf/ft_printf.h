/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:16:53 by zel-harb          #+#    #+#             */
/*   Updated: 2023/12/05 01:41:46 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
void	ft_putchar(char c, int *len);
void	ft_putstr(char *c, int *len);
void	ft_putnbr_base(unsigned int nbr, char Xx, int *len);
void	ft_putnbr(int n, int *len);
void	ft_putaddr(void *addr, int *len);
void	ft_putnbr_unsigned(unsigned int n, int *len);
#endif
