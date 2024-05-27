/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:47:44 by ttaquet           #+#    #+#             */
/*   Updated: 2024/05/27 02:28:23 by tom              ###   ########.fr       */
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

/**
 * @brief This function call functions to sort the stack 'a'
 * 
 * @param a The stack 'a'
 * @param b The stack 'b'
 */
void	ft_turk_sort(t_list **a, t_list **b);

/******************************************************************************/
/*                                                                            */
/* all_set                                                                    */
/*                                                                            */
/******************************************************************************/

/**
 * @brief This function set the index of every nodes of stack 'a' and 'b'
 * 
 * @param a The stack 'a'
 * @param b The stack 'b'
 */
void	set_index(t_list **a, t_list **b);

/**
 * @brief This function set the cost of every nodes of stack 'a' and 'b'
 * 
 * @param a The stack 'a'
 * @param b The stack 'b'
 */
void	set_cost(t_list **a, t_list **b, char stack);

/**
 * @brief This function set the target of every nodes of stack 'a' and 'b'
 * 
 * @param a The stack 'a'
 * @param b The stack 'b'
 */
void	set_target(t_list **a, t_list **b, char from);

/**
 * @brief This function set 'above mediane' of every nodes of stack 'a' and 'b'
 * 
 * @param a The stack 'a'
 * @param b The stack 'b'
 */
void	set_mediane(t_list **a, t_list **b);

/******************************************************************************/
/*                                                                            */
/* fill_stack                                                                 */
/*                                                                            */
/******************************************************************************/

/**
 * @brief This function fill the stack 'b'
 * 
 * @param a The stack 'a'
 * @param b The stack 'b'
 * @param a_size The size of the stack 'a'
 */
void	ft_fill_stack_b(t_list **a, t_list **b, int a_size);

/**
 * @brief This function fills the stack 'a' with every value given in
 * the arguments
 * 
 * @param list The list of value
 * @param a The stack 'a'
 * @param splitted A boolean indicating whether the list has been split or not
 */
void	ft_fill_stack_a(char **list, t_list **a, bool splitted);

/**
 * @brief This function fills the stack 'b' if the stack contains 5
 * values or fewer
 * 
 * @param a The stack 'a'
 * @param b The stack 'b'
 */
void	ft_fill_stack_b_five(t_list **a, t_list **b);

/**
 * @brief This function places the value with the smallest cost
 * on the top of stack 'b'
 * 
 * @param a The stack 'a'
 * @param b The stack 'b'
 * @param min_cost The node with the smallest cost in stack 'b'
 */
void	ft_place_on_top_second(t_list **a, t_list **b, t_list *min_cost);

/******************************************************************************/
/*                                                                            */
/* ft_opti                                                                    */
/*                                                                            */
/******************************************************************************/

void	ft_opti(t_list **a, t_list **b, t_list *min_cost);
void	ft_rev_rotate_test(t_list **a, t_list **b, t_list *min_cost);
void	ft_opti_bis(t_list **a, t_list **b, t_list *min_cost, int tmp);

/******************************************************************************/
/*                                                                            */
/* instruction                                                                */
/*                                                                            */
/******************************************************************************/

/**
 * @brief Shift all elements of stack 'stacks' down by one position.
 * The last element becomes the first
 * 
 * @param stacks The stack 'a' , 'b', or both
 * @param a The stack 'a'
 * @param b The stack 'b'
 * @param print A boolean indicating whether the instruction has to be
 * printed or not
 */
void	reverse_rotate(char *stacks, t_list **a, t_list **b, bool print);

/**
 * @brief Shift all elements of stack 'stacks' up by one position.
 * The first element becomes the last
 * 
 * @param stacks The stack 'a' , 'b', or both
 * @param a The stack 'a'
 * @param b The stack 'b'
 * @param print A boolean indicating whether the instruction has to be
 * printed or not
 */
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

/**
 * @brief This function prints 'error', frees all allocated memory,
 * and stops the program
 * 
 * @param a The stack 'a'
 * @param b The stack 'b'
 * @param error The error has to be print
 */
void	ft_error(t_list **a, t_list **b, char *error);

/**
 * @brief This function print the stack 'a' and 'b'
 * 
 * @param head_a The head of the stack 'a'
 * @param head_b The head of the stack 'b'
 */
void	ft_print_stack(t_list **head_a, t_list **head_b);

/******************************************************************************/
/*                                                                            */
/* research_fonction                                                          */
/*                                                                            */
/******************************************************************************/

/**
 * @brief This function find the smallest value of the stack 'stack'
 * 
 * @param stack The stack 'a' or 'b'
 * @return t_list* The node with the smallest value in the stack 'stack'
 */
t_list	*ft_find_min(t_list **stack);

/**
 * @brief This function find the biggest value of the stack 'stack'
 * 
 * @param stack The stack 'a' or 'b'
 * @return t_list* The node with the biggest value in the stack 'stack'
 */
t_list	*ft_find_max(t_list **stack);

/**
 * @brief This function find the smallest cost of the stack 'stack'
 * 
 * @param stack The stack 'a' or 'b'
 * @return t_list* The node with the smallest cost in the stack 'stack'
 */
t_list	*find_min_cost(t_list **stack);

/**
 * @brief This function find the target value of the node 'node' in
 * the stack 'stack'
 * 
 * @param stack The stack 'a' or 'b'
 * @param node The stack 'a' or 'b'
 * @param direction The direction of the push, 'a' to 'b' or 'b' to 'a'
 */
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

/**
 * @brief This function returns whether The stack is sorted or not
 * 
 * @param stack The stack 'a' or 'b'
 * @return true The stack is sorted
 * @return false The stack is not sorted
 */
bool	ft_is_sorted(t_list **stack);

/**
 * @brief This function return the stack's size
 * 
 * @param stack the stack 'a' or 'b'
 * @return int The stack's size
 */
int		ft_stack_size(t_list	**stack);

/**
 * @brief This function checks if the stack contains duplicates
 * 
 * @param stack The stack 'a'
 * @return true The stack not contain any duplicates
 * @return false The stack contain duplicates
 */
bool	ft_is_not_double(t_list **stack);

/**
 * @brief This function checks whether every character of the string is
 * digit or not
 * 
 * @param str The string
 * @return true Every character of the string is a digit
 * @return false The string contains characters that are not digits
 */
bool	ft_all_isdigit(char *str);

/**
 * @brief This function returns the number of instructions required
 * to place the node on the top of the stack
 * 
 * @param node The node
 * @param stack_size The size of the stack 'a' or 'b'
 * @return int the number of instructions required to place the node on
 * the top of the stack
 */
int		node_to_top(t_list *node, int stack_size);

#endif
