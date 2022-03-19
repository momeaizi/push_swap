/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:39:51 by momeaizi          #+#    #+#             */
/*   Updated: 2022/02/15 11:23:27 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_part(t_list **a, t_list **b, t_info	var)
{
	int	i;

	i = 0;
	while (i < var.part)
	{
		if ((*a)->nbr >= var.min && (*a)->nbr <= var.max)
		{
			pb(b, a);
			if ((*b)->next && (*b)->nbr > var.mid)
				rb(b);
			i++;
		}
		else
			ra(a);
	}
}

void	partitions(t_list **a, t_list **b)
{
	t_info	var;
	int		devider;

	devider = 3;
	var.size = ft_lstsize(*a);
	if (var.size > 100)
		devider = 4;
	var.part = ((var.size - 3) / devider) + 1;
	var.min = 0;
	var.max = var.min + var.part - 1;
	var.mid = (var.max + var.min) / 2;
	while (var.size > 3)
	{
		push_part(a, b, var);
		var.size = ft_lstsize(*a);
		devider = 3;
		if (var.size > 100)
			devider = 4;
		var.min += var.part;
		var.part = ((var.size - 3) / devider) + 1;
		var.max += var.part;
		var.mid = (var.max + var.min) / 2;
	}
	sort_3(a);
	push_back(a, b);
}

void	push_element(t_list **b, t_list **a, int nbr)
{
	int	ind;
	int	size;

	ind = index1(*b, nbr);
	size = ft_lstsize(*b);
	while (*b)
	{
		if ((*b)->nbr == nbr)
		{
			pa(a, b);
			return ;
		}
		else if ((*b)->next && (*b)->next->nbr == nbr)
			sb(b);
		else if (ind >= (size / 2))
			rrb(b);
		else if (ind < (size / 2))
			rb(b);
	}
}

void	push_3(t_list **a, t_list **b, t_three *arr, int min)
{
	int	i;

	i = 3;
	while (--i >= 0)
	{
		push_element(b, a, arr[i].nbr);
		if (arr[i].nbr == min && i > 0)
			ra(a);
		if ((*a)->next && (*a)->nbr > (*a)->next->nbr)
			sa(a);
	}
	if (ft_lstb4_last(*a)->nbr > ft_lstlast(*a)->nbr)
		rra(a);
}

void	push_back(t_list **a, t_list **b)
{
	t_three	*arr;
	int		nbr;
	int		size;
	int		i;

	arr = (t_three *)malloc(3 * sizeof(t_three));
	if (!arr)
		error(a, b);
	size = ft_lstsize(*b);
	nbr = size - 1;
	i = 0;
	while (size >= 3)
	{
		i = -1;
		while (++i < 3)
		{
			arr[i].nbr = nbr;
			arr[i].distance = abs((index1(*b, nbr) - (ft_lstsize(*b) / 2)));
			nbr--;
		}
		sort_struct(arr);
		push_3(a, b, arr, nbr + 1);
		size -= 3;
	}
	free(arr);
}
