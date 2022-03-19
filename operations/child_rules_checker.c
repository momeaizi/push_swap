/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_rules_checker.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:43:28 by momeaizi          #+#    #+#             */
/*   Updated: 2022/02/15 10:55:08 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	sa(t_list **a, t_list **b)
{
	swap(a, b);
}

void	sb(t_list **b, t_list **a)
{
	swap(b, a);
}

void	ss(t_list **a, t_list **b)
{
	swap(a, b);
	swap(b, a);
}

void	pa(t_list **a, t_list **b)
{
	push(a, b);
}

void	pb(t_list **b, t_list **a)
{
	push(b, a);
}
