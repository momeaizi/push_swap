/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:51:24 by momeaizi          #+#    #+#             */
/*   Updated: 2022/02/19 10:39:42 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

struct	s_info
{
	int	min;
	int	mid;
	int	max;
	int	size;
	int	part;
};

struct	s_list
{
	int				nbr;
	struct s_list	*next;
};

struct s_three
{
	int	distance;
	int	nbr;
};

typedef struct s_info	t_info;
typedef struct s_three	t_three;
typedef struct s_list	t_list;
/*						push_swap.c						*/
void	error(t_list **a, t_list **b);
int		is_duplicated(t_list *head, int nbr);
void	ft_atoi(t_list **head, char *str);
/*						sort.c							*/
void	push_part(t_list **a, t_list **b, t_info var);
void	partitions(t_list **a, t_list **b);
void	push_element(t_list **b, t_list **a, int nbr);
void	push_back(t_list **a, t_list **b);
/*						quiqsort.c						*/
int		partition(int *arr, int start, int end);
void	quiqsort(int *arr, int start, int end);
void	sort_3(t_list **a);
void	sort_5(t_list **a, t_list **b);
void	sort_struct(t_three *arr);
/*						utils.c							*/
int		abs(int nbr);
int		is_sorted(t_list *head);
void	fill(t_list *node, int *arr);
void	lst_2_arr(t_list **head);
int		index1(t_list *head, int nbr);
/*						parent_rules.c					*/
void	swap(t_list **head);
void	push(t_list **to, t_list **from);
void	rotate(t_list **head);
void	reverse_rotate(t_list **head);
void	rrr(t_list **a, t_list **b);
/*						child_rules.c					*/
void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	pb(t_list **b, t_list **a);
/*						rules.c							*/
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
void	rrb(t_list **b);
void	rra(t_list **a);
/*						list.c							*/
int		ft_lstsize(t_list *head);
t_list	*ft_lstlast(t_list *head);
t_list	*ft_lstb4_last(t_list *head);
void	ft_lstclear(t_list **head);
void	ft_lstaddfront(t_list **head, long nbr);

#endif
