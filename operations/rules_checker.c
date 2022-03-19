/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:44:43 by momeaizi          #+#    #+#             */
/*   Updated: 2022/02/15 10:55:29 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	ra(t_list **a, t_list **b)
{
	rotate(a, b);
}

void	rb(t_list **b, t_list **a)
{
	rotate(b, a);
}

void	rr(t_list **a, t_list **b)
{
	rotate(a, b);
	rotate(b, a);
}

void	rrb(t_list **b, t_list **a)
{
	reverse_rotate(b, a);
}

void	rra(t_list **a, t_list **b)
{
	reverse_rotate(a, b);
}
