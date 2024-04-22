/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:52:55 by thelmy            #+#    #+#             */
/*   Updated: 2024/04/21 19:37:46 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "./libft/libft.h"

typedef struct s_list
{
	int				data;
	struct s_list	*next;
}					t_list;

#endif