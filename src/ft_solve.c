/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 13:45:08 by awajsbro          #+#    #+#             */
/*   Updated: 2018/04/15 19:04:22 by awajsbro         ###   ########.fr       */
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

static char	ft_order_a(t_ps *ps)
{
	long long	i;
	t_list		*tmp;

	tmp = ps->lpa;
	i = ps->lpa->size;
	while (tmp != NULL)
	{
		if (tmp->size != i)
			return (0);
		i++;
		tmp = tmp->next;
	}
	return (1);
}

void	ft_solve(t_ps *ps)
{
	t_list		*tmp;
	long long	i;

	ps->lpa = ft_lststart(ps->lpa);
	if (ft_lstlen(ps->lpa) < 4)
		ft_spe_3(ps);
	i = 1;
	while (i > 0 && ps->lpa->next != NULL)
	{
		tmp = ft_lstend(ps->lpa);
		if (ps->lpa->next->size == i)
			ft_swap(ps, 'a');
		else if (tmp->size == i)
			ft_revers_roll(ps, 'a');
		if (ps->lpa->size == i && ft_order_a(ps) == 0)
		{
			ft_push(ps, 'b');
			i++;
		}
		else
			i = 0;
	}
	if (ps->lpa->next == NULL || ft_order_a(ps) == 1)
	{
		while (ps->lpb != NULL)
			ft_push(ps, 'a');
	}
ft_lstdebug(ps->lpa, "lpa");
	// while (ft_check_order(&ps) == 0)
	// {
	// 	ft_split(ps);
	// }
}
