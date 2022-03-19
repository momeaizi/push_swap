/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:47:49 by momeaizi          #+#    #+#             */
/*   Updated: 2022/02/19 10:40:55 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_lstsize(t_list *head)
{
	int	i;

	i = 0;
	while (head)
	{
		i++;
		head = head->next;
	}
	return (i);
}

t_list	*ft_lstlast(t_list *head)
{
	while (head->next)
		head = head->next;
	return (head);
}

t_list	*ft_lstb4_last(t_list *head)
{
	while (head->next->next)
		head = head->next;
	return (head);
}

void	ft_lstclear(t_list **head)
{
	t_list	*current;

	while (*head)
	{
		current = *head;
		*head = (*head)->next;
		free(current);
	}
}

void	ft_lstaddfront(t_list **head, long nbr)
{
	t_list	*node;

	if (nbr < INT_MIN || nbr > INT_MAX)
		error(head, NULL);
	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
	{
		ft_lstclear(head);
		exit (1);
	}
	node->nbr = nbr;
	node->next = *head;
	*head = node;
}
