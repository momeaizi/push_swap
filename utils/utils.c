/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:39:39 by momeaizi          #+#    #+#             */
/*   Updated: 2022/02/15 10:57:17 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	abs(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

int	is_sorted(t_list *head)
{
	while (head && head->next)
	{
		if (head->nbr > head->next->nbr)
			return (0);
		head = head->next;
	}
	return (1);
}

void	fill(t_list *node, int *arr)
{
	int	i;

	i = 0;
	while (arr[i] != node->nbr)
		i++;
	node->nbr = i;
}

void	lst_2_arr(t_list **head)
{
	t_list	*lst;
	t_list	*node;
	int		*arr;
	int		i;

	lst = *head;
	node = lst;
	i = 0;
	arr = (int *)malloc(ft_lstsize(node) * sizeof(int));
	if (!arr)
		error(head, NULL);
	while (node)
	{
		arr[i] = node->nbr;
		node = node->next;
		i++;
	}
	quiqsort(arr, 0, i - 1);
	while (lst)
	{
		fill(lst, arr);
		lst = lst->next;
	}
	free(arr);
}

int	index1(t_list *head, int nbr)
{
	int	i;

	i = 0;
	while (head && head->nbr != nbr)
	{
		i++;
		head = head->next;
	}
	return (i);
}
