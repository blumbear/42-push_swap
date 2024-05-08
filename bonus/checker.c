/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaquet <ttaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:08:58 by ttaquet           #+#    #+#             */
/*   Updated: 2024/05/07 18:23:31 by ttaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	instruction(t_list **a, t_list **b, char *line)
{
	if (ft_strcmp(line, "sa\n") == 0)
		swap("a", a, b, 1);
	else if (ft_strcmp(line, "sb\n") == 0)
		swap("b", a, b, 1);
	else if (ft_strcmp(line, "ss\n") == 0)
		swap("ab", a, b, 1);
	else if (ft_strcmp(line, "ra\n") == 0)
		rotate("a", a, b, 1);
	else if (ft_strcmp(line, "rb\n") == 0)
		rotate("b", a, b, 1);
	else if (ft_strcmp(line, "rr\n") == 0)
		rotate("ab", a, b, 1);
	else if (ft_strcmp(line, "rra\n") == 0)
		reverse_rotate("a", a, b, 1);
	else if (ft_strcmp(line, "rrb\n") == 0)
		reverse_rotate("b", a, b, 1);
	else if (ft_strcmp(line, "rrr\n") == 0)
		reverse_rotate("ab", a, b, 1);
	else if (ft_strcmp(line, "pa\n") == 0)
		push('a', a, b, 1);
	else if (ft_strcmp(line, "pb\n") == 0)
		push('b', a, b, 1);
	else
		return (0);
	return (1);
}

void	loop(t_list **a, t_list **b)
{
	char	*line;
	int		success;

	line = get_next_line(0);
	if (!line)
	{
		if (ft_is_sorted(a))
			ft_printf("OK\n");
		free(line);
		return ;
	}
	while (line)
	{
		success = instruction(a, b, line);
		free(line);
		if (!success)
			ft_error(a, b, "An instruction is not correct");
		line = get_next_line(0);
	}
	if (ft_is_sorted(a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
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
	loop(a, b);
	ft_print_stack(a, b);
	ft_error(a, b, NULL);
}
