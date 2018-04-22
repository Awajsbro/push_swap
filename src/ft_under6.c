/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_under6.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 11:24:26 by awajsbro          #+#    #+#             */
/*   Updated: 2018/04/22 13:09:12 by awajsbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_re_order_a(t_ps *ps)
{
	int		i;

	if (ps->lpa->size != 1)
	{
		i = ft_find_min_roll(ps->lpa, 1);
		if (i > 0)
			while (i--)
				ft_roll(ps, 'a');
		else
			while (i++)
				ft_revers_roll(ps, 'a');
	}
}

static void	ft_drain_bpool(t_ps *ps, int i, t_list *tmp)
{
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
			i = ft_find_min_roll(ps->lpa, ps->lpb->size + 1);
			if (i > 0)
				while (i--)
					ft_roll(ps, 'a');
			else
				while (i++)
					ft_revers_roll(ps, 'a');
		}
		else
			ft_roll(ps, 'b');
	}
}

void		ft_under6(t_ps *ps)
{
	t_list	*tmp;

	while (ft_lstlen(ps->lpa) > 3 && ft_order_lst(ps->lpa) == 0)
	{
		if (ps->lpa->size == ps->len)
			ft_roll(ps, 'a');
		else
			ft_push(ps, 'b');
	}
	while (ft_order_lst(ps->lpa) == 0)
	{
		tmp = ft_lstend(ps->lpa);
		if (ps->lpa->size > ps->lpa->next->size && ft_max(ps->lpa->next) == 0
			&& !(ps->lpa->size == ps->len && ps->lpa->next->size == 1))
			ft_swap(ps, 'a');
		else if ((tmp->size < ps->lpa->size && ps->lpa->size != ps->len)
			|| ft_max(ps->lpa->next) == 1)
			ft_revers_roll(ps, 'a');
		else if (ps->lpa->size > tmp->size)
			ft_roll(ps, 'a');
	}
	ft_drain_bpool(ps, 0, NULL);
	ft_re_order_a(ps);
}
