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


#ifndef list_H
# define list_H

// # include "./libft/libft.h"

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
typedef struct s_list
{
	int				data;
	struct s_list	*next;
}					t_list;

#endif