/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:18:58 by ttaquet           #+#    #+#             */
/*   Updated: 2024/04/24 02:22:40 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_fill_stack_a(char **list, t_list **a, bool splitted)
{
	long int	tmp;
	int	i;

	i = 0;
	while (list[i])
	{
		tmp = ft_atoi(list[i]);
		if (tmp > MAX_INT || tmp < MIN_INT)
		{
			if (splitted)
				ft_free_double_array(list);
			ft_error(a, NULL, "The int must be between MIN_INT and MAX_INT");
		}
		if (ft_intlen(tmp) != ft_strlen(list[i]) && tmp != 0)
		{
			if (splitted)
				ft_free_double_array(list);
			ft_error(a, NULL, "An char is in the int list");
		}
		ft_lstadd_back(a, ft_lstnew((int)tmp));
		i++;
	}
}

int	ft_is_not_double(t_list **stack)
{
	t_list	*tmp_a;
	t_list	*tmp_b;

	tmp_a = *stack;
	while(tmp_a)
	{
		tmp_b = tmp_a->next;
		while(tmp_b)
		{
			if (tmp_a->content == tmp_b->content)
				return (0);
			tmp_b = tmp_b->next;
		}
		tmp_a = tmp_a->next;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_list	**a;
	t_list	**b;
	bool	splitted;

	splitted = (ac == 2);
	if (ac < 2)
		ft_error(NULL, NULL, "Usage : ./push_swap <int list>");
	av++;
	if (ac == 2)
		av = ft_split(*av, ' ');
	a = malloc(sizeof(t_list *));
	*a = NULL;
	ft_fill_stack_a(av, a, splitted);
	if (splitted)
		ft_free_double_array(av);
	if (!ft_is_not_double(a))
		ft_error(a, NULL, "The int list contains double");
	if (ft_is_sorted(a))
		ft_error(a, NULL, NULL);
	b = malloc(sizeof(t_list *));
	*b = NULL;
	ft_turk_sort(a, b);
	//ft_print_stack(a, b);
	ft_error(a, b, NULL);
}
