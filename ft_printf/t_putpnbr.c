/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_putpnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:16:30 by thelmy            #+#    #+#             */
/*   Updated: 2023/12/16 16:16:43 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	t_putpnbr(unsigned int n)
{
	int	count;
	int	x;

	count = 0;
	if (n >= 10)
	{
		x = t_putpnbr(n / 10);
		if (x == -1)
			return (x);
		count += x;
		x = t_putpnbr(n % 10);
		if (x == -1)
			return (x);
		count += x;
	}
	else
	{
		x = t_putchar(n + '0');
		if (x == -1)
			return (x);
		count += x;
	}
	return (count);
}
