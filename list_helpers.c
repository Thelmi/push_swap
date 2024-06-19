/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:33:00 by thelmy            #+#    #+#             */
/*   Updated: 2024/06/15 17:57:49 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_Node	*lastnode(t_Node *list)
{
	t_Node	*tmp;

	tmp = list;
	while (tmp -> next != NULL)
		tmp = tmp -> next;
	return (tmp);
}

t_Node	*create_node(int value)
{
	t_Node	*newnode;

	newnode = malloc(sizeof(t_Node));
	if (!newnode)
		return (NULL);
	newnode -> data = value;
	newnode -> next = NULL;
	return (newnode);
}

t_Node	*add_front(t_Node **node, int value)
{
	t_Node	*newnode;

	newnode = create_node(value);
	newnode -> next = *node;
	*node = newnode;
	return (*node);
}

t_Node	*add_back(t_Node *list, int val)
{
	t_Node	*newnode;
	t_Node	*tmp;

	if (list == NULL)
		return (create_node(val));
	newnode = create_node(val);
	tmp = list;
	while (tmp ->next != NULL)
		tmp = tmp ->next;
	tmp -> next = newnode;
	return (newnode);
}
