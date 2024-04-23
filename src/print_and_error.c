/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_and_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:27:38 by ttaquet           #+#    #+#             */
/*   Updated: 2024/04/23 07:07:11 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	del_fun(int n)
{
	(void)n;
}

void	ft_print_stack(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp)
	{
		ft_printf("%d\n", tmp->content);
		tmp = tmp->next;
	}
}

void	ft_error(t_list **a, t_list **b, char *error)
{
	if (a)
	{
		ft_lstclear(a, del_fun);
		free(a);
	}
	if (b)
	{
		ft_lstclear(b, del_fun);
		free(b);
	}
	if (error && ft_strncmp(error, "Usage :", 7) == 0)
		ft_printf("%s\n", error);
	else if (error)
		ft_printf("Error : %s\n", error);
	exit(0);
}
