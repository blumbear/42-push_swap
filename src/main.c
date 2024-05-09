/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaquet <ttaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:18:58 by ttaquet           #+#    #+#             */
/*   Updated: 2024/05/07 18:12:10 by ttaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	**a;
	t_list	**b;
	bool	splitted;

	splitted = (ac == 2);
	if (ac < 2 || !av[1][0])
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
	ft_error(a, b, NULL);
}
