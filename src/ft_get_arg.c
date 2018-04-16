/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 18:16:42 by awajsbro          #+#    #+#             */
/*   Updated: 2018/04/15 15:37:07 by awajsbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_order_str(t_ps *ps)
{
	long long	len;
	long long	pos;
	t_list		*tmp;
	t_list		*cp;

	ps->lpa = ft_lststart(ps->lpa);
	cp = ps->lpa;
	len = ft_lstlen(cp);
	while (cp != NULL)
	{
		pos = len;
		tmp = cp;
		ps->lpa = ft_lststart(ps->lpa);
		while (ps->lpa->next != NULL)
		{
			if (ft_istrcmp(tmp->content, ps->lpa->content) == -1)
				pos--;
			ps->lpa = ps->lpa->next;
		}
		if (ft_istrcmp(tmp->content, ps->lpa->content) == -1)
			pos--;
		tmp->size = pos;
		cp = cp->next;
	}
}

static char	ft_check_double(t_ps ps)
{
	t_list		*tmp;

	ps.lpa = ft_lststart(ps.lpa);
	while (ps.lpa->next != NULL)
	{
		tmp = ps.lpa->next;
		while (tmp != NULL)
		{
			if (ft_strequ(tmp->content, ps.lpa->content) == 1)
			{
				ft_error_double(tmp, ps);
				return (0);
			}
			tmp = tmp->next;
		}
		ps.lpa = ps.lpa->next;
	}
	return (1);
}

void		ft_get_arg(long long ac, char **av, long long i, t_ps *ps)
{
	ps->lpa = ft_lstnew(ft_strdup(av[i]), 0);
	while (++i < ac)
	{
		ft_lstaddend(&(ps->lpa), ft_lstnew(ft_strdup(av[i]), 0));
	}
	if (ft_check_double(*ps) == 0)
	{
		ft_lstdel(&(ps->lpa));
		exit(EXIT_FAILURE);
	}
	ft_order_str(ps);
	ps->lpb = NULL;
}
