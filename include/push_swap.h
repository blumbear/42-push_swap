/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:47:44 by ttaquet           #+#    #+#             */
/*   Updated: 2024/05/09 00:54:18 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libamoa.h"

/******************************************************************************/
/*                                                                            */
/* algo                                                                       */
/*                                                                            */
/******************************************************************************/

void	ft_sort_five_node(t_list **a, t_list **b);
void	ft_sort_three_node(t_list **head_a);
void	ft_turk_sort(t_list **a, t_list **b);

/******************************************************************************/
/*                                                                            */
/* all_set                                                                    */
/*                                                                            */
/******************************************************************************/

void	set_index(t_list **a, t_list **b);
void	select_cost(t_list **a, t_list **b, char stack);
void	set_target(t_list **a, t_list **b, char from);
void	set_mediane(t_list **a, t_list **b);

/******************************************************************************/
/*                                                                            */
/* fill_stack                                                                 */
/*                                                                            */
/******************************************************************************/

void	ft_fill_stack_b(t_list **a, t_list **b, int a_size);
void	ft_fill_stack_a(char **list, t_list **a, bool splitted);
void	ft_fill_stack_b_five(t_list **a, t_list **b);
void	ft_place_on_top_second(t_list **a, t_list **b, t_list *min_cost);

/******************************************************************************/
/*                                                                            */
/* instruction                                                                */
/*                                                                            */
/******************************************************************************/

void	reverse_rotate(char *stacks, t_list **a, t_list **b, bool print);
void	rotate(char *stacks, t_list **a, t_list **b, bool print);

/**
 * @brief This function push the node on the top of stack a or b on the top of
 * 'stacks'
 * 
 * @param stacks The stack where we push the node and print pa or pb
 * @param a The stack a
 * @param b The stack b
 */
void	push(char stacks, t_list **a, t_list **b, bool print);

/**
 * @brief This function swap the first two nodes of the 'stacks' and print
 * sa, sb or ss
 * 
 * @param stacks The stack where we will swap the first two nodes
 * @param a The stack a
 * @param b The stack b
 */
void	swap(char *stacks, t_list **a, t_list **b, bool print);

/******************************************************************************/
/*                                                                            */
/* print_and_error                                                            */
/*                                                                            */
/******************************************************************************/

void	ft_error(t_list **a, t_list **b, char *error);
void	ft_print_stack(t_list **head_a, t_list **head_b);

/******************************************************************************/
/*                                                                            */
/* research_fonction                                                          */
/*                                                                            */
/******************************************************************************/

t_list	*ft_find_min(t_list **stack);
t_list	*ft_find_max(t_list **stack);
t_list	*find_min_cost(t_list **stack);
void	ft_find_target(t_list **stack, t_list *node, char *direction);

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

bool	ft_is_sorted(t_list **stack);
int		ft_stack_size(t_list	**stack);
int		ft_is_not_double(t_list **stack);
int		ft_all_isdigit(char *str);

#endif
