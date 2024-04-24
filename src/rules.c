/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 07:08:25 by tom               #+#    #+#             */
/*   Updated: 2024/04/24 14:52:42 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_nodes(t_list **stack)
{
	int tmp;

	tmp = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = tmp;
}

void	ft_push_node(t_list **head_p, t_list **head_r)
{
	t_list	*new_node;
	t_list	*tmp;

	if (!*head_p)
		return ;
	new_node = ft_lstnew((*head_p)->content);
	new_node->next = *head_r;
	*head_r = new_node;
	tmp = *head_p;
	*head_p = (*head_p)->next;
	free(tmp);
}

void	ft_rotate_stack(t_list **stack)
{
	t_list *new_node;
	t_list *tmp;

	if (!stack)
		return ;
	new_node = ft_lstnew((*stack)->content);
	ft_lstadd_back(stack, new_node);
	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
}

void	ft_rev_rotate_stack(t_list **stack)
{
	t_list	*last;
	t_list	*before_last;

	before_last = *stack;
	last = before_last->next;
	while (last->next)
	{
		before_last = before_last->next;
		last = before_last->next;
	}
	before_last->next = NULL;
	last->next = *stack;
	*stack = last;
}
