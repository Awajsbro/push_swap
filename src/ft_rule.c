/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rule.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 10:15:36 by awajsbro          #+#    #+#             */
/*   Updated: 2018/04/15 15:18:54 by awajsbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_push(t_ps *ps, char m)
{
	if (m == 'a')
	{
		if (ps->lpb != NULL)
		{
			ps->lpb = ft_lststart(ps->lpb);
			ft_lstaddstart(&(ps->lpa), ft_lstremove(&(ps->lpb)));
		}
	}
	else if (m == 'b')
	{
		if (ps->lpa != NULL)
		{
			ps->lpa = ft_lststart(ps->lpa);
			ft_lstaddstart(&(ps->lpb), ft_lstremove(&(ps->lpa)));
		}
	}
	if (ps->pro == 1)
		ft_printf("%[fd*]p%c\n", ps->fdw, m);
}

void	ft_swap(t_ps *ps, char m)
{
	if (m == 'a' || m == 's')
	{
		if (ft_lstlen(ps->lpa) > 1)
		{
			ps->lpa = ft_lststart(ps->lpa);
			ps->lpa = ps->lpa->next;
			ft_lstaddstart(&(ps->lpa), ft_lstremove(&(ps->lpa)));
		}
	}
	if (m == 'b' || m == 's')
	{
		if (ft_lstlen(ps->lpb) > 1)
		{
			ps->lpb = ft_lststart(ps->lpb);
			ps->lpb = ps->lpb->next;
			ft_lstaddstart(&(ps->lpb), ft_lstremove(&(ps->lpb)));
		}
	}
	if (ps->pro == 1)
		ft_printf("%[fd*]s%c\n", ps->fdw, m);
}

void	ft_roll(t_ps *ps, char m)
{
	if (m == 'a' || m == 'r')
	{
		if (ft_lstlen(ps->lpa) > 1)
		{
			ps->lpa = ft_lststart(ps->lpa);
			ft_lstaddend(&(ps->lpa), ft_lstremove(&(ps->lpa)));
		}
	}
	if (m == 'b' || m == 'r')
	{
		if (ft_lstlen(ps->lpb) > 1)
		{
			ps->lpb = ft_lststart(ps->lpb);
			ft_lstaddend(&(ps->lpb), ft_lstremove(&(ps->lpb)));
		}
	}
	if (ps->pro == 1)
		ft_printf("%[fd*]r%c\n", ps->fdw, m);
}

void	ft_revers_roll(t_ps *ps, char m)
{
	if (m == 'a' || m == 'r')
	{
		if (ft_lstlen(ps->lpa) > 1)
		{
			ps->lpa = ft_lstend(ps->lpa);
			ft_lstaddstart(&(ps->lpa), ft_lstremove(&(ps->lpa)));
		}
	}
	if (m == 'b' || m == 'r')
	{
		if (ft_lstlen(ps->lpb) > 1)
		{
			ps->lpb = ft_lstend(ps->lpb);
			ft_lstaddstart(&(ps->lpb), ft_lstremove(&(ps->lpb)));
		}
	}
	if (ps->pro == 1)
		ft_printf("%[fd*]rr%c\n", ps->fdw, m);
}

char	ft_check_order(t_ps *ps)
{
	long long	i;

	i = 0;
	if (ps->lpb != NULL)
		return (0);
	ps->lpa = ft_lststart(ps->lpa);
	while (ps->lpa != NULL)
	{
		i++;
		if (i != ps->lpa->size)
			return (0);
		ps->lpa = ps->lpa->next;
	}
	return (1);
}
