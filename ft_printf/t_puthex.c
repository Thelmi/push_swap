/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_puthex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 20:15:37 by thelmy            #+#    #+#             */
/*   Updated: 2023/12/14 18:06:25 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	t_puthex(unsigned long n, int cap)
{
	char	*base;
	int		count;
	int		x;

	count = 0;
	if (cap == 0)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n >= 16)
	{
		x = t_puthex(n / 16, cap);
		if (x == -1)
			return (-1);
		count += x;
	}
	x = t_putchar(base[n % 16]);
	if (x == -1)
		return (x);
	return (count + x);
}
