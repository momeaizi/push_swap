/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 15:33:42 by momeaizi          #+#    #+#             */
/*   Updated: 2022/02/14 11:38:43 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strcmp(char *s1, const char *s2)
{
	int	i;

	i = -1;
	while (s1[++i] || s2[i])
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	return (0);
}

int	check(char *rule, t_list **a, t_list **b)
{
	if (!ft_strcmp(rule, "sa\n"))
		sa(a, b);
	else if (!ft_strcmp(rule, "sb\n"))
		sb(b, a);
	else if (!ft_strcmp(rule, "ss\n"))
		ss(a, b);
	else if (!ft_strcmp(rule, "pa\n"))
		pa(a, b);
	else if (!ft_strcmp(rule, "pb\n"))
		pb(b, a);
	else if (!ft_strcmp(rule, "ra\n"))
		ra(a, b);
	else if (!ft_strcmp(rule, "rb\n"))
		rb(b, a);
	else if (!ft_strcmp(rule, "rr\n"))
		rr(a, b);
	else if (!ft_strcmp(rule, "rra\n"))
		rra(a, b);
	else if (!ft_strcmp(rule, "rrb\n"))
		rrb(b, a);
	else if (!ft_strcmp(rule, "rrr\n"))
		rrr(a, b);
	else
		return (0);
	return (1);
}

void	checker(t_list **a, t_list **b)
{
	char	*rule;

	while (1)
	{
		rule = get_line();
		if (!rule)
			return ;
		if (!check(rule, a, b))
			error(a, b);
		free(rule);
	}
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (0);
	while (--ac > 0)
		ft_atoi(&a, av[ac]);
	checker(&a, &b);
	if (is_sorted(a) && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_lstclear(&a);
}
