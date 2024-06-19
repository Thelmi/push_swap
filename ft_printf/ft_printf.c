/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:09:06 by thelmy            #+#    #+#             */
/*   Updated: 2023/12/18 12:03:25 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		x;
	int		temp;

	va_start(args, format);
	i = 0;
	x = 0;
	while (format[i] != '\0')
	{
		temp = x;
		if (format[i] == '%')
		{
			i++;
			x += t_server(format[i], args);
		}
		else
			x += write(1, &format[i], 1);
		if (x < temp)
			return (-1);
		i++;
	}
	va_end(args);
	return (x);
}
