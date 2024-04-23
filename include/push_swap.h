/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:47:44 by ttaquet           #+#    #+#             */
/*   Updated: 2024/04/23 08:42:39 by tom              ###   ########.fr       */
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

/******************************************************************************/
/*                                                                            */
/* algo                                                                       */
/*                                                                            */
/******************************************************************************/

void	ft_sort_three_node(t_list **head_a);
void	ft_turk_sort(t_list **a, t_list **b);

/******************************************************************************/
/*                                                                            */
/* instruction                                                                */
/*                                                                            */
/******************************************************************************/

void	reverse_rotate(char *stacks, t_list **a, t_list **b);
void	rotate(char *stacks, t_list **a, t_list **b);
void	push(char stacks, t_list **a, t_list **b);
void	swap(char *stacks, t_list **a, t_list **b);

/******************************************************************************/
/*                                                                            */
/* print_and_error                                                            */
/*                                                                            */
/******************************************************************************/

void	ft_error(t_list **a, t_list **b, char *error);
void	ft_print_stack(t_list **stack);

/******************************************************************************/
/*                                                                            */
/* rules                                                                      */
/*                                                                            */
/******************************************************************************/

void	ft_swap_nodes(t_list **stack);
void	ft_push_node(t_list **head_p, t_list **head_r);
void	ft_rev_rotate_stack(t_list **stack);
void	ft_rotate_stack(t_list **stack);

/******************************************************************************/
/*                                                                            */
/* utils                                                                      */
/*                                                                            */
/******************************************************************************/

int		ft_find_max(t_list **stack);
bool	ft_is_sorted(t_list **stack);
int		ft_stack_size(t_list	**stack);


#endif
