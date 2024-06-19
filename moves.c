/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:55:36 by thelmy            #+#    #+#             */
/*   Updated: 2024/06/19 22:14:50 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	swap(t_Node *list)
{
	int	swp;

	if (list == NULL)
		return ;
	swp = list -> data;
	list -> data = list -> next -> data;
	list -> next -> data = swp;
}

void	double_swap(t_Node *listA, t_Node *listB)
{
	if (listB == NULL || listA == NULL)
		return ;
	swap(listA);
	swap(listB);
	ft_printf("ss\n");
}

void	push(t_Node **listA, t_Node **listB)
{
	t_Node	*tmp;

	if (*listA == NULL || *listB == NULL)
		return ;
	tmp = *listA;
	*listA = (*listA)-> next;
	tmp -> next = *listB;
	*listB = tmp;
}
