/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quiqsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:38:57 by momeaizi          #+#    #+#             */
/*   Updated: 2022/02/15 10:55:46 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	partition(int *arr, int start, int end)
{
	int	tmp;
	int	pivot;
	int	index;

	index = start;
	pivot = arr[end];
	while (start <= end)
	{
		if (arr[start] <= pivot)
		{
			tmp = arr[start];
			arr[start] = arr[index];
			arr[index] = tmp;
			index++;
		}
		start++;
	}
	return (index - 1);
}

void	quiqsort(int *arr, int start, int end)
{
	int	index;

	if (start < end)
	{
		index = partition(arr, start, end);
		quiqsort(arr, index + 1, end);
		quiqsort(arr, start, index - 1);
	}
}

void	sort_3(t_list **a)
{
	while (!is_sorted(*a))
	{
		if ((*a)->nbr > (*a)->next->nbr && (*a)->nbr < ft_lstlast(*a)->nbr)
			sa(a);
		else if ((*a)->nbr > (*a)->next->nbr && (*a)->nbr > ft_lstlast(*a)->nbr)
			ra(a);
		else if (ft_lstlast(*a)->nbr < (*a)->next->nbr)
			rra(a);
	}
}

void	sort_5(t_list **a, t_list **b)
{
	int	i;

	i = 2;
	while (i)
	{
		if ((*a)->nbr <= 1)
		{
			pb(b, a);
			i--;
		}
		else if ((*a)->next->nbr <= 1)
			sa(a);
		else if (ft_lstlast(*a)->nbr <= 1)
			rra(a);
		else
			ra(a);
	}
	sort_3(a);
	while (*b)
	{
		if ((*b)->next)
			if ((*b)->nbr < (*b)->next->nbr)
				sb(b);
		pa(a, b);
	}
}

void	sort_struct(t_three *arr)
{
	t_three	var;
	int		i;
	int		j;

	i = -1;
	while (++i < 3)
	{
		j = i;
		while (++j < 3)
		{
			if (arr[i].distance > arr[j].distance)
			{
				var = arr[i];
				arr[i] = arr[j];
				arr[j] = var;
			}
		}
	}
}
