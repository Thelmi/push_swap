/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases_parse_one.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:06:42 by thelmy            #+#    #+#             */
/*   Updated: 2024/06/18 17:53:12 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int	t_atoi(const char *str)
{
	int				i;
	int				sign;
	unsigned long	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((result > INT_MAX / 10) || (sign == 1
				&& result == INT_MAX / 10 && str[i] - '0' > INT_MAX % 10)
			|| (sign == -1 && result > INT_MAX / 10)
			|| (result == INT_MAX / 10 && str[i] - '0' > (INT_MAX % 10) + 1))
			return (-1 * (sign == 1));
		result = (result * 10) + (str[i++] - '0');
	}
	return (result * sign);
}

int	t_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((unsigned char)c == (unsigned char)s[i])
			return (1);
		i++;
	}
	return (0);
}

int	is_integer(char *str)
{
	if (ft_strlen(str) > 2 && (t_atoi(str) == 0
			|| t_atoi(str) == -1))
		return (0);
	return (1);
}

int	isnot_term(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9')
			&& (str[i + 1] == '+' || str[i + 1] == '-'))
			return (0);
		i++;
	}
	return (1);
}

int	t_defence(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (str[i] == ' ')
		i++;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9')
			|| ((str[i] == '-' || str[i] == '+')
				&& (str[i + 1] >= '0' && str[i + 1] <= '9')))
			flag = 1;
		else if (flag && str[i] == ' ')
			flag = 1;
		else
			return (0);
		i++;
	}
	return (flag);
}
