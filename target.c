/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 15:55:29 by thelmy            #+#    #+#             */
/*   Updated: 2024/06/15 17:38:34 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int	positiona_at_top(int position_ab[2],
	t_Node *tmpa, t_Node *tmpb, t_Node *stackb)
{
	int	cost;

	if (position_ab[1] <= tmpb ->stackb_size / 2)
	{
		if (position_ab[1] == 1 && stackb ->stackb_size == 2
			&& !(tmpa->data > tmpb->first
				&& tmpa->data < tmpb->last))
			cost = 2;
		else if (position_ab[1] == 2 && stackb ->stackb_size == 2)
			cost = 1;
		else if (position_ab[0] == 1 && position_ab[1] == 1
			&& tmpa->data > tmpb->first
			&& tmpa->data < tmpb->last)
			cost = 1;
		else if (position_ab[0] > position_ab[1])
			cost = position_ab[0];
		else
			cost = position_ab[1] + 1;
	}
	else
		cost = position_ab[0] + (tmpb ->stackb_size - position_ab[1]);
	return (cost);
}

int	positiona_at_bottom(int position_ab[2],
	t_Node *tmpa, t_Node *tmpb)
{
	int	cost;

	if (position_ab[1] <= tmpb->stackb_size / 2)
	{
		cost = (tmpa ->stacka_size + 2) - position_ab[0] + position_ab[1];
		if (tmpa->data > tmpb->first && tmpa->data < tmpb->last)
			cost--;
	}
	else
	{
		if ((tmpa ->stacka_size + 1) - position_ab[0]
			> tmpb ->stackb_size - position_ab[1])
			cost = (tmpa -> stacka_size + 2) - position_ab[0];
		else
			cost = (tmpb ->stackb_size - position_ab[1]) + 1;
	}
	return (cost);
}

void	update_cheapest(t_Node *tmp_ab[2], int position_ab_cost[2],
	t_Node *stacka, t_Node *stackb)
{
	int	cost;

	if (position_ab_cost[0] <= (tmp_ab[0]->stacka_size + 1) / 2)
		cost = positiona_at_top(position_ab_cost,
				tmp_ab[0], tmp_ab[1], stackb);
	else
		cost = positiona_at_bottom(position_ab_cost,
				tmp_ab[0], tmp_ab[1]);
	if (cost < position_ab_cost[2])
	{
		position_ab_cost[2] = cost;
		tmp_ab[0]->positiona = position_ab_cost[0];
		tmp_ab[1]-> positionb = position_ab_cost[1];
		positionab(stacka, stackb, position_ab_cost[0], position_ab_cost[1]);
		target_value(stacka, tmp_ab[0]-> data);
		target_value(stackb, tmp_ab[0]-> data);
	}
}

int	target_2(t_Node *tmp_ab[2], int position_ab_cost[2],
	t_Node *stacka, t_Node *stackb)
{
	while (tmp_ab[1] != NULL)
	{
		if ((tmp_ab[1]->next != NULL && (tmp_ab[0]->data < tmp_ab[1]->data
					&& tmp_ab[0]->data > tmp_ab[1]->next->data))
			|| (tmp_ab[1]->data == tmp_ab[1]->bmin && (tmp_ab[0]->data
					> tmp_ab[1]->bmax || tmp_ab[0]->data < tmp_ab[1]->bmin))
			|| (tmp_ab[0]->data > tmp_ab[1]->first
				&& tmp_ab[0]->data < tmp_ab[1]->last))
		{
			update_cheapest(tmp_ab, position_ab_cost, stacka, stackb);
			break ;
		}
		position_ab_cost[1]++;
		tmp_ab[1] = tmp_ab[1]-> next;
	}
	return (position_ab_cost[2]);
}

void	target(t_Node *stacka, t_Node *stackb)
{
	t_Node	*tmp_ab[2];
	int		position_ab_cost[3];

	tmp_ab[0] = stacka;
	tmp_ab[1] = stackb;
	position_ab_cost[2] = INT_MAX;
	position_ab_cost[0] = 0;
	position_ab_cost[1] = 1;
	listsize((stacka), (stackb));
	largestnsmallest((stackb));
	firstnlast(stackb);
	while (tmp_ab[0] != NULL)
	{
		position_ab_cost[0]++;
		tmp_ab[1] = stackb;
		position_ab_cost[1] = 1;
		position_ab_cost[2] = target_2(tmp_ab,
				position_ab_cost, stacka, stackb);
		tmp_ab[0] = tmp_ab[0]->next;
	}
	cheapest_one(stacka, position_ab_cost[2]);
	cheapest_one(stackb, position_ab_cost[2]);
}
