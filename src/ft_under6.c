/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_under6.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 11:24:26 by awajsbro          #+#    #+#             */
/*   Updated: 2018/04/29 15:18:10 by awajsbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_re_order_a(t_ps *ps)
{
	int		i;

	if (LPA->size != 1)
	{
		i = ft_find_min_roll(LPA, 1);
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
	while (LPB != NULL)
	{
		if (ft_lstfindsize(LPB, LPA->size - 1) == 1)
		{
			tmp = ft_lstend(LPB);
			if (tmp->size == LPA->size - 1)
				ft_revers_roll(ps, 'b');
			else if (LPB->next->size == LPA->size - 1)
				ft_roll(ps, 'b');
			ft_push(ps, 'a');
		}
		else if (ft_lstfindsize(LPB, LPB->size + 1) == 0)
		{
			i = ft_find_min_roll(LPA, LPB->size + 1);
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

	while (ft_lstlen(LPA) > 3 && ft_order_lst(LPA) == 0)
	{
		if (LPA->size == ps->len)
			ft_roll(ps, 'a');
		else
			ft_push(ps, 'b');
	}
	while (ft_order_lst(LPA) == 0)
	{
		tmp = ft_lstend(LPA);
		if (LPA->size > LPA->next->size && ft_max(LPA->next) == 0
			&& !(LPA->size == ps->len && LPA->next->size == 1))
			ft_swap(ps, 'a');
		else if ((tmp->size < LPA->size && LPA->size != ps->len)
			|| ft_max(LPA->next) == 1)
			ft_revers_roll(ps, 'a');
		else if (LPA->size > tmp->size)
			ft_roll(ps, 'a');
	}
	ft_drain_bpool(ps, 0, NULL);
	ft_re_order_a(ps);
}
