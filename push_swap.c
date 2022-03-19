/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:56:56 by momeaizi          #+#    #+#             */
/*   Updated: 2022/02/19 10:26:44 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	int		size;

	a = NULL;
	b = NULL;
	while (--ac)
		ft_atoi(&a, av[ac]);
	size = ft_lstsize(a);
	lst_2_arr(&a);
	if (!is_sorted(a) && size <= 3)
		sort_3(&a);
	else if (!is_sorted(a) && size <= 5)
		sort_5(&a, &b);
	if (!is_sorted(a))
		partitions(&a, &b);
	while (b)
		pa(&a, &b);
	if (a && a->next && a->nbr > a->next->nbr)
		sa(&a);
	return (0);
}
