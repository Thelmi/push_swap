/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 15:39:00 by thelmy            #+#    #+#             */
/*   Updated: 2024/06/15 19:05:47 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	largestnsmallest(t_Node *list)
{
	t_Node	*tmp;
	int		min;
	int		max;

	tmp = list;
	min = INT_MAX;
	max = INT_MIN;
	while (tmp != NULL)
	{
		if (max < tmp -> data)
			max = tmp -> data;
		if (min > tmp -> data)
			min = tmp -> data;
		tmp = tmp -> next;
	}
	tmp = list;
	while (tmp != NULL)
	{
		tmp -> bmax = max;
		tmp -> bmin = min;
		tmp = tmp -> next;
	}
}

void	firstnlast(t_Node *stack)
{
	t_Node	*tmp;
	int		last;
	int		first;

	tmp = stack;
	last = lastnode(stack)->data;
	first = stack -> data;
	while (tmp != NULL)
	{
		tmp ->first = first;
		tmp ->last = last;
		tmp = tmp -> next;
	}
}

void	cheapest_one(t_Node *stack, int cost)
{
	t_Node	*tmp;

	tmp = stack;
	while (tmp != NULL)
	{
		tmp ->cheapest_cost = cost;
		tmp = tmp -> next;
	}
}

void	target_value(t_Node *stack, int target)
{
	t_Node	*tmp;

	tmp = stack;
	while (tmp != NULL)
	{
		tmp ->target = target;
		tmp = tmp -> next;
	}
}

void	listsize(t_Node *stacka, t_Node *stackb)
{
	t_Node	*tmp;
	int		count;

	tmp = stacka;
	count = 0;
	while (tmp != NULL && ++count)
		tmp = tmp -> next;
	tmp = stacka;
	while (tmp != NULL)
	{
		tmp -> stacka_size = count;
		tmp = tmp ->next;
	}
	tmp = stackb;
	count = 0;
	while (tmp != NULL && ++count)
		tmp = tmp ->next;
	tmp = stackb;
	while (tmp != NULL)
	{
		tmp -> stackb_size = count;
		tmp = tmp ->next;
	}
}
