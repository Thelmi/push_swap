/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_helpers_two.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 15:43:57 by thelmy            #+#    #+#             */
/*   Updated: 2024/06/15 16:19:25 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	positionab(t_Node *stacka, t_Node *stackb, int positiona, int positionb)
{
	t_Node	*tmp;

	tmp = stacka;
	while (tmp != NULL)
	{
		tmp ->positiona = positiona;
		tmp ->positionb = positionb;
		tmp = tmp -> next;
	}
	tmp = NULL;
	tmp = stackb;
	while (tmp != NULL)
	{
		tmp ->positiona = positiona;
		tmp ->positionb = positionb;
		tmp = tmp -> next;
	}
}

void	mixer(t_Node **stacka, t_Node **stackb)
{
	while (*stacka != NULL)
	{
		target(*stacka, *stackb);
		makemoves(stacka, stackb);
	}
	rotate_pushback(stacka, stackb);
}

void	smallest_position(t_Node *stacka)
{
	t_Node	*tmp;
	int		count;

	count = 1;
	tmp = stacka;
	while (tmp != NULL)
	{
		if (stacka -> bmin == tmp ->data)
		{
			stacka -> positiona = count;
			break ;
		}
		count++;
		tmp = tmp -> next;
	}
}

int	isascending(t_Node *list)
{
	t_Node	*tmp;

	tmp = list;
	while (tmp -> next != NULL)
	{
		if (tmp -> data > tmp -> next-> data)
			return (0);
		tmp = tmp -> next;
	}
	return (1);
}
