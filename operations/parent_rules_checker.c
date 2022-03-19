/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_rules_checker.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 15:40:02 by momeaizi          #+#    #+#             */
/*   Updated: 2022/02/15 10:54:31 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	swap(t_list **a, t_list **b)
{
	t_list	*second;

	if (ft_lstsize(*a) < 2)
		error(a, b);
	second = (*a)->next;
	(*a)->next = second->next;
	second->next = (*a);
	*a = second;
}

void	push(t_list **to, t_list **from)
{
	t_list	*node;

	if (!ft_lstsize(*from))
		error(to, from);
	node = *from;
	*from = (*from)->next;
	node->next = *to;
	*to = node;
}

void	rotate(t_list **a, t_list **b)
{
	t_list	*first;
	t_list	*last;
	int		size;

	size = ft_lstsize(*a);
	if (size < 1)
		error(a, b);
	if (size == 1)
		return ;
	first = *a;
	last = ft_lstlast(first);
	*a = (*a)->next;
	last->next = first;
	first->next = NULL;
}

void	reverse_rotate(t_list **a, t_list **b)
{
	t_list	*b4_last;
	t_list	*last;
	int		size;

	size = ft_lstsize(*a);
	if (size < 1)
		error(a, b);
	if (size == 1)
		return ;
	b4_last = ft_lstb4_last(*a);
	last = b4_last->next;
	b4_last->next = NULL;
	last->next = *a;
	*a = last;
}

void	rrr(t_list **a, t_list **b)
{
	reverse_rotate(a, b);
	reverse_rotate(b, a);
}
