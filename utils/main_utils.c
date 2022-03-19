/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:48:30 by momeaizi          #+#    #+#             */
/*   Updated: 2022/02/19 10:39:59 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	error(t_list **a, t_list **b)
{
	write(2, "ERROR\n", 6);
	ft_lstclear(a);
	if (b && *b)
		ft_lstclear(b);
	exit(1);
}

int	is_duplicated(t_list *head, int nbr)
{
	while (head)
	{
		if (nbr == head->nbr)
			return (1);
		head = head->next;
	}
	return (0);
}

void	ft_atoi(t_list **head, char *str)
{
	char		signe;
	int			i;
	long		nbr;

	i = 0;
	nbr = 0;
	signe = 1;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
		signe = ++i * -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = (nbr * 10) + (str[i++] - 48);
		if (nbr - 1 > INT_MAX)
			error(head, NULL);
	}
	if (str[i - 1] == '+' || str[i - 1] == '-' || str[i] \
	|| is_duplicated(*head, nbr * signe) || !i)
		error(head, NULL);
	else
		ft_lstaddfront(head, nbr * signe);
}
