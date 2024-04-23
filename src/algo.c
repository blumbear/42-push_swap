/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 08:05:44 by tom               #+#    #+#             */
/*   Updated: 2024/04/23 08:26:00 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three_node(t_list **head_a)
{
	int		max;

	max = ft_find_max(head_a);
	if (ft_is_sort(head_a))
		return ;
	if (ft_lstlast(*head_a)->content != max)
	{
		if ((*head_a)->content == max)
			rotate("a", head_a, NULL);
		else
			reverse_rotate("a", head_a, NULL);
	}
	if (!ft_is_sort(head_a))
		swap("a", head_a, NULL);
}
