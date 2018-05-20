/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rule.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 10:15:36 by awajsbro          #+#    #+#             */
/*   Updated: 2018/05/15 17:15:48 by awajsbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_push(t_ps *ps, char m)
{
	if (m == 'a')
	{
		if (LPB != NULL)
		{
			LPB = ft_lststart(LPB);
			ft_lstaddstart(&(LPA), ft_lstremove(&(LPB)));
			ps->cmd = ft_joinfree(ps->cmd, ft_memset(ft_strnew(1), M_PA, 1));
		}
	}
	else if (m == 'b')
	{
		if (LPA != NULL)
		{
			LPA = ft_lststart(LPA);
			ft_lstaddstart(&(LPB), ft_lstremove(&(LPA)));
			ps->cmd = ft_joinfree(ps->cmd, ft_memset(ft_strnew(1), M_PB, 1));
		}
	}
	LPA = ft_lststart(LPA);
	LPB = ft_lststart(LPB);
}

void	ft_swap(t_ps *ps, char m)
{
	if (m == 'a' || m == 's')
	{
		if (ft_lstlen(LPA) > 1)
		{
			LPA = ft_lststart(LPA);
			LPA = LPA->next;
			ft_lstaddstart(&(LPA), ft_lstremove(&(LPA)));
			ps->cmd = ft_joinfree(ps->cmd, ft_memset(ft_strnew(1), M_SA, 1));
		}
	}
	if (m == 'b' || m == 's')
	{
		if (ft_lstlen(LPB) > 1)
		{
			LPB = ft_lststart(LPB);
			LPB = LPB->next;
			ft_lstaddstart(&(LPB), ft_lstremove(&(LPB)));
			ps->cmd = ft_joinfree(ps->cmd, ft_memset(ft_strnew(1), M_SB, 1));
		}
	}
}

void	ft_roll(t_ps *ps, char m)
{
	if (m == 'a' || m == 'r')
	{
		if (ft_lstlen(LPA) > 1)
		{
			LPA = ft_lststart(LPA);
			ft_lstaddend(&(LPA), ft_lstremove(&(LPA)));
			ps->cmd = ft_joinfree(ps->cmd, ft_memset(ft_strnew(1), M_RA, 1));
		}
	}
	if (m == 'b' || m == 'r')
	{
		if (ft_lstlen(LPB) > 1)
		{
			LPB = ft_lststart(LPB);
			ft_lstaddend(&(LPB), ft_lstremove(&(LPB)));
			ps->cmd = ft_joinfree(ps->cmd, ft_memset(ft_strnew(1), M_RB, 1));
		}
	}
	LPA = ft_lststart(LPA);
	LPB = ft_lststart(LPB);
}

void	ft_revers_roll(t_ps *ps, char m)
{
	if (m == 'a' || m == 'r')
	{
		if (ft_lstlen(LPA) > 1)
		{
			LPA = ft_lstend(LPA);
			ft_lstaddstart(&(LPA), ft_lstremove(&(LPA)));
			ps->cmd = ft_joinfree(ps->cmd, ft_memset(ft_strnew(1), M_RRA, 1));
		}
	}
	if (m == 'b' || m == 'r')
	{
		if (ft_lstlen(LPB) > 1)
		{
			LPB = ft_lstend(LPB);
			ft_lstaddstart(&(LPB), ft_lstremove(&(LPB)));
			ps->cmd = ft_joinfree(ps->cmd, ft_memset(ft_strnew(1), M_RRB, 1));
		}
	}
	LPA = ft_lststart(LPA);
	LPB = ft_lststart(LPB);
}
