/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rule.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 10:15:36 by awajsbro          #+#    #+#             */
/*   Updated: 2018/04/11 17:51:27 by awajsbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_push(t_ps *ps, char m)
{
	if (m == 'a')
	{
		if (ps->lpb == NULL)
			return ;
		ps->lpb = ft_lststart(ps->lpb);
		ft_lstaddstart(&(ps->lpa), ft_lstremove(&(ps->lpb)));
	}
	else if (m == 'b')
	{
		if (ps->lpa == NULL)
			return ;
		ps->lpa = ft_lststart(ps->lpa);
		ft_lstaddstart(&(ps->lpb), ft_lstremove(&(ps->lpa)));
	}
}

void	ft_swap(t_ps *ps, char m)
{
	if (m == 'a' || m == 's')
	{
		if (ft_lstlen(ps->lpa) < 2)
			return ;
		ps->lpa = ft_lststart(ps->lpa);
		ps->lpa = ps->lpa->next;
		ft_lstaddstart(&(ps->lpa), ft_lstremove(&(ps->lpa)));
	}
	if (m == 'b' || m == 's')
	{
		if (ft_lstlen(ps->lpb) < 2)
			return ;
		ps->lpb = ft_lststart(ps->lpb);
		ps->lpb = ps->lpb->next;
		ft_lstaddstart(&(ps->lpb), ft_lstremove(&(ps->lpb)));
	}
}

void	ft_roll(t_ps *ps, char m)
{
	if (m == 'a' || m == 'r')
	{
		if (ft_lstlen(ps->lpa) < 2)
			return ;
		ps->lpa = ft_lststart(ps->lpa);
		ft_lstaddend(&(ps->lpa), ft_lstremove(&(ps->lpa)));
	}
	if (m == 'b' || m == 'r')
	{
		if (ft_lstlen(ps->lpb) < 2)
			return ;
		ps->lpb = ft_lststart(ps->lpb);
		ft_lstaddend(&(ps->lpb), ft_lstremove(&(ps->lpb)));
	}
}

void	ft_revers_roll(t_ps *ps, char m)
{
	if (m == 'a' || m == 'r')
	{
		if (ft_lstlen(ps->lpa) < 2)
			return ;
		ps->lpa = ft_lstend(ps->lpa);
		ft_lstaddstart(&(ps->lpa), ft_lstremove(&(ps->lpa)));
	}
	if (m == 'b' || m == 'r')
	{
		if (ft_lstlen(ps->lpb) < 2)
			return ;
		ps->lpb = ft_lstend(ps->lpb);
		ft_lstaddstart(&(ps->lpb), ft_lstremove(&(ps->lpb)));
	}
}
