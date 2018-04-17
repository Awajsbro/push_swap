/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 13:45:08 by awajsbro          #+#    #+#             */
/*   Updated: 2018/04/17 18:47:45 by awajsbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// void	ft_split(t_ps *ps)
// {
// 	long long	len;

// 	len = ft_lstlen(ps->lpa);
// 	while (len--)
// 		ft_push(ps, 'b')
// }

static char	ft_order_lst(t_list *lst)
{
	t_list		*tmp;

	tmp = ft_lststart(lst);
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		if (tmp->size < tmp->prev->size)
			return (0);
	}
	return (1);
}

// static char	ft_reverse_order_lst(t_list *lst)
// {
// 	t_list	*tmp;

// 	tmp = ft_lststart(lst);
// 	while (tmp->next != NULL)
// 	{
// 		tmp = tmp->next;
// 		if (tmp->size > tmp->prev->size)
// 			return (0);
// 	}
// 	return (1);
// }

static char	ft_max(t_list *lst)
{
	t_list *tmp;

	tmp = ft_lststart(lst);
	while (tmp != NULL)
	{
		if (tmp->size >= lst->size)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static void	ft_spe_5(t_ps *ps, long len)
{
	t_list	*tmp;
	char 	i;

	while (ft_lstlen(ps->lpa) > 3 && (long)ft_lstlen(ps->lpa) > len / 2 && ft_order_lst(ps->lpa) == 0)
	{
		if (ps->lpa->size == len)
			ft_roll(ps, 'a');
		else
			ft_push(ps, 'b');
	}
	while (ft_order_lst(ps->lpa) == 0)
	{
		tmp = ft_lstend(ps->lpa);
		if (ps->lpa->size > ps->lpa->next->size && ft_max(ps->lpa->next) == 0
			&& !(ps->lpa->size == len && ps->lpa->next->size == 1))
			ft_swap(ps, 'a');
		else if (tmp->size < ps->lpa->size && ps->lpa->size != len)
			ft_revers_roll(ps, 'a');
		else if (ps->lpa->size > tmp->size)
			ft_roll(ps, 'a');
	ft_lstdebug(ps);
	}
	while (ps->lpb != NULL)
	{
		if (ft_lstfindsize(ps->lpb, ps->lpa->size - 1) == 1)
		{
			tmp = ft_lstend(ps->lpb);
			if (tmp->size == ps->lpa->size - 1)
				ft_revers_roll(ps, 'b');
			else if (ps->lpb->next->size == ps->lpa->size - 1)
				ft_roll(ps, 'b');
			ft_push(ps, 'a');
		}
		else if (ft_lstfindsize(ps->lpb, ps->lpb->size + 1) == 0)
		{
			i = 1;
			ps->lpa = ps->lpa->next;
			tmp = ft_lstend(ps->lpa);
			while (ps->lpa->size != ps->lpb->size + 1 && tmp->size != ps->lpb->size + 1)
			{
				i++;
				ps->lpa = ps->lpa->next;
				tmp = tmp->prev;
			}
			if (tmp->size == ps->lpb->size + 1)
			{
				while (i--)
					ft_revers_roll(ps, 'a');
			}
			else
			{
				while (i--)
					ft_roll(ps, 'a');
			}
		}
		else
			ft_roll(ps, 'b');
	}
	if (ps->lpa->size != 1)
	{
		i = 1;
		ps->lpa = ps->lpa->next;
		tmp = ft_lstend(ps->lpa);
		while (ps->lpa->size != 1 && tmp->size != 1)
		{
			i++;
			ps->lpa = ps->lpa->next;
			tmp = tmp->prev;
		}
		if (tmp->size == 1)
		{
			while (i--)
				ft_revers_roll(ps, 'a');
		}
		else
		{
			while (i--)
				ft_roll(ps, 'a');
		}
	}
}

void	ft_solve(t_ps *ps)
{
	t_list		*tmp;
	long long	i;
	long long	len;

	ps->lpa = ft_lststart(ps->lpa);
	i = 1;
	if ((len = ft_lstlen(ps->lpa)) < 600)
		ft_spe_5(ps, len);
	else
	{
		while (i > 0 && ps->lpa->next != NULL)
		{
			tmp = ft_lstend(ps->lpa);
			if (ps->lpa->next->size == i)
				ft_swap(ps, 'a');
			else if (tmp->size == i)
				ft_revers_roll(ps, 'a');
			if (ps->lpa->size == i && ft_order_lst(ps->lpa) == 0)
			{
				ft_push(ps, 'b');
				i++;
			}
			else
				i = 0;
		}
	}
	if (ps->lpa->next == NULL || ft_order_lst(ps->lpa) == 1)
	{
		while (ps->lpb != NULL)
			ft_push(ps, 'a');
	}
	// while (ft_check_order(&ps) == 0)
	// {
	// 	ft_split(ps);
	// }
}
