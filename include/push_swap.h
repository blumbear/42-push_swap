/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaquet <ttaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:47:44 by ttaquet           #+#    #+#             */
/*   Updated: 2024/04/10 18:29:08 by ttaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libamoa.h"

typedef struct s_avlist
{
	char	**list;
	bool	splitted;
}	t_avlist;

void	ft_error(t_list **a, t_list **b, char *error, bool splitted, char **list);
void	ft_print_stack(t_list **stack);

#endif
