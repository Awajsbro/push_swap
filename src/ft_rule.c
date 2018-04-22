/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rule.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 10:15:36 by awajsbro          #+#    #+#             */
/*   Updated: 2018/04/22 13:24:59 by awajsbro         ###   ########.fr       */
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
			ps->cmd = ft_joinfree(ps->cmd, ft_memset(ft_strnew(1), M_PA, 1));
		}
	}
	else if (m == 'b')
	{
		if (ps->lpa != NULL)
		{
			ps->lpa = ft_lststart(ps->lpa);
			ft_lstaddstart(&(ps->lpb), ft_lstremove(&(ps->lpa)));
			ps->cmd = ft_joinfree(ps->cmd, ft_memset(ft_strnew(1), M_PB, 1));
		}
	}
	if ((ps->opt & M_VISUAL) == M_VISUAL)
		{
			ft_printf("%[fd2]\n    p%c\n", m);
			ft_lstdebug(ps);
		}
	ps->lpa = ft_lststart(ps->lpa);
	ps->lpb = ft_lststart(ps->lpb);
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
			ps->cmd = ft_joinfree(ps->cmd, ft_memset(ft_strnew(1), M_SA, 1));
		}
	}
	if (m == 'b' || m == 's')
	{
		if (ft_lstlen(ps->lpb) > 1)
		{
			ps->lpb = ft_lststart(ps->lpb);
			ps->lpb = ps->lpb->next;
			ft_lstaddstart(&(ps->lpb), ft_lstremove(&(ps->lpb)));
			ps->cmd = ft_joinfree(ps->cmd, ft_memset(ft_strnew(1), M_SB, 1));
		}
	}
	if ((ps->opt & M_VISUAL) == M_VISUAL)
		{
			ft_printf("%[fd2]\n    s%c\n", m);
			ft_lstdebug(ps);
		}
	ps->lpa = ft_lststart(ps->lpa);
	ps->lpb = ft_lststart(ps->lpb);
}

void	ft_roll(t_ps *ps, char m)
{
	if (m == 'a' || m == 'r')
	{
		if (ft_lstlen(ps->lpa) > 1)
		{
			ps->lpa = ft_lststart(ps->lpa);
			ft_lstaddend(&(ps->lpa), ft_lstremove(&(ps->lpa)));
			ps->cmd = ft_joinfree(ps->cmd, ft_memset(ft_strnew(1), M_RA, 1));
		}
	}
	if (m == 'b' || m == 'r')
	{
		if (ft_lstlen(ps->lpb) > 1)
		{
			ps->lpb = ft_lststart(ps->lpb);
			ft_lstaddend(&(ps->lpb), ft_lstremove(&(ps->lpb)));
			ps->cmd = ft_joinfree(ps->cmd, ft_memset(ft_strnew(1), M_RB, 1));
		}
	}
	if ((ps->opt & M_VISUAL) == M_VISUAL)
		{
			ft_printf("%[fd2]\n    r%c\n", m);
			ft_lstdebug(ps);
		}
	ps->lpa = ft_lststart(ps->lpa);
	ps->lpb = ft_lststart(ps->lpb);
}

void	ft_revers_roll(t_ps *ps, char m)
{
	if (m == 'a' || m == 'r')
	{
		if (ft_lstlen(ps->lpa) > 1)
		{
			ps->lpa = ft_lstend(ps->lpa);
			ft_lstaddstart(&(ps->lpa), ft_lstremove(&(ps->lpa)));
			ps->cmd = ft_joinfree(ps->cmd, ft_memset(ft_strnew(1), M_RRA, 1));
		}
	}
	if (m == 'b' || m == 'r')
	{
		if (ft_lstlen(ps->lpb) > 1)
		{
			ps->lpb = ft_lstend(ps->lpb);
			ft_lstaddstart(&(ps->lpb), ft_lstremove(&(ps->lpb)));
			ps->cmd = ft_joinfree(ps->cmd, ft_memset(ft_strnew(1), M_RRB, 1));
		}
	}
	if ((ps->opt & M_VISUAL) == M_VISUAL)
		{
			ft_printf("%[fd2]\n    rr%c\n", m);
			ft_lstdebug(ps);
		}
	ps->lpa = ft_lststart(ps->lpa);
	ps->lpb = ft_lststart(ps->lpb);
}

char	ft_check_result(t_ps *ps)
{
	int	i;

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
