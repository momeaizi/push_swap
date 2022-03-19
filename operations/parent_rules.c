/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_rules.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:48:58 by momeaizi          #+#    #+#             */
/*   Updated: 2022/02/15 10:54:19 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_list **head)
{
	t_list	*second;

	if (ft_lstsize(*head) < 2)
		exit (1);
	second = (*head)->next;
	(*head)->next = second->next;
	second->next = (*head);
	*head = second;
}

void	push(t_list **to, t_list **from)
{
	t_list	*node;

	if (!ft_lstsize(*from))
		exit (1);
	node = *from;
	*from = (*from)->next;
	node->next = *to;
	*to = node;
}

void	rotate(t_list **head)
{
	t_list	*first;
	t_list	*last;

	if (ft_lstsize(*head) < 2)
		exit (1);
	first = *head;
	last = ft_lstlast(first);
	*head = (*head)->next;
	last->next = first;
	first->next = NULL;
}

void	reverse_rotate(t_list **head)
{
	t_list	*b4_last;
	t_list	*last;

	if (ft_lstsize(*head) < 2)
		return ;
	b4_last = ft_lstb4_last(*head);
	last = b4_last->next;
	b4_last->next = NULL;
	last->next = *head;
	*head = last;
}

void	rrr(t_list **a, t_list **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}
