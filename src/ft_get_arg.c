/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 18:16:42 by awajsbro          #+#    #+#             */
/*   Updated: 2018/05/12 12:26:17 by awajsbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_order_str(t_ps *ps)
{
	int			len;
	int			pos;
	t_list		*tmp;
	t_list		*cp;

	LPA = ft_lststart(LPA);
	cp = LPA;
	len = ft_lstlen(cp);
	while (cp != NULL)
	{
		pos = len;
		tmp = cp;
		LPA = ft_lststart(LPA);
		while (LPA->next != NULL)
		{
			if (ft_istrcmp(tmp->content, LPA->content) == -1)
				pos--;
			LPA = LPA->next;
		}
		if (ft_istrcmp(tmp->content, LPA->content) == -1)
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

void		ft_get_arg(int ac, char **av, int i, t_ps *ps)
{
	LPA = ft_lstnew(ft_strdup(av[i]), 0);
	while (++i < ac)
	{
		ft_lstaddend(&(LPA), ft_lstnew(ft_strdup(av[i]), 0));
	}
	if (ft_check_double(*ps) == 0)
	{
		ft_lstdel(&(LPA));
		exit(EXIT_FAILURE);
	}
	ft_order_str(ps);
	ps->len = ft_lstlen(LPA);
	LPB = NULL;
}
