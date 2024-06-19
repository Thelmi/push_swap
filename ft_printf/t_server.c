/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_server.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:32:41 by thelmy            #+#    #+#             */
/*   Updated: 2023/12/16 19:11:20 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	t_server(char specifier, va_list args)
{
	if (specifier == 'c')
		return (t_putchar(va_arg(args, int)));
	if (specifier == 's')
		return (t_putstr(va_arg(args, char *)));
	if (specifier == 'p')
		return (t_putads(va_arg(args, void *)));
	if (specifier == 'd' || specifier == 'i')
		return (t_putnbr(va_arg(args, int)));
	if (specifier == 'u')
		return (t_putpnbr(va_arg(args, unsigned int)));
	if (specifier == 'x')
		return (t_puthex(va_arg(args, unsigned int), 0));
	if (specifier == 'X')
		return (t_puthex(va_arg(args, unsigned int), 1));
	if (specifier == '%')
		return (t_putchar('%'));
	else
		return (-1);
}
