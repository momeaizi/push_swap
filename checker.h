/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:40:14 by momeaizi          #+#    #+#             */
/*   Updated: 2022/02/14 12:42:50 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>

struct	s_list
{
	int				nbr;
	struct s_list	*next;
};
typedef struct s_list	t_list;
/*                      get_line.c                      */
void	ft_strcpy(char	*dst, char	*src, char c);
char	*ft_strjoin(char c, char *str);
char	*get_line(void);
/*                      checker.c                       */
int		ft_strcmp(char *s1, const char *s2);
int		check(char *rule, t_list **a, t_list **b);
/*						utils.c							*/
int		is_sorted(t_list *head);
/*						push_swap.c						*/
void	error(t_list **a, t_list **b);
int		is_duplicated(t_list *head, int nbr);
void	ft_atoi(t_list **head, char *str);
/*						parent_rules.c					*/
void	swap(t_list **a, t_list **b);
void	push(t_list **to, t_list **from);
void	rotate(t_list **a, t_list **b);
void	reverse_rotate(t_list **a, t_list **b);
void	rrr(t_list **a, t_list **b);
/*						child_rules.c					*/
void	sa(t_list **a, t_list **b);
void	sb(t_list **b, t_list **a);
void	ss(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	pb(t_list **b, t_list **a);
/*						rules.c							*/
void	ra(t_list **a, t_list **b);
void	rb(t_list **b, t_list **a);
void	rr(t_list **a, t_list **b);
void	rrb(t_list **b, t_list **a);
void	rra(t_list **a, t_list **b);
/*						list.c							*/
int		ft_lstsize(t_list *head);
t_list	*ft_lstlast(t_list *head);
t_list	*ft_lstb4_last(t_list *head);
void	ft_lstclear(t_list **head);
void	ft_lstaddfront(t_list **head, int nbr, char signe);

#endif
