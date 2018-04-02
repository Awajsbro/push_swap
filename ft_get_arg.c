/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 18:16:42 by awajsbro          #+#    #+#             */
/*   Updated: 2018/04/02 17:41:59 by awajsbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define M_COLOR		0x01
#define M_VISUAL	0x02
#define M_LONG		0x04
#define M_ERROR		0x08
#define M_INF		0x10

static void	ft_order_str(t_ps *ps)
{
	int		len;
	int		pos;
	t_list	*tmp;
	t_list	*cp;


	ft_lststart(ps->lpa);
	cp = ps->lpa;
	len = ft_lstlen(cp);
	while (ps->lpa != NULL)
	{
		pos = len;
		tmp = ps->lpa;
		ft_lststart(cp);
		while (cp != NULL)
		{
			if (ft_istrcmp(tmp->content, cp->content) == -1)
				pos--;
			cp = cp->next;
		}
		tmp->size = pos;
		ps->lpa = ps->lpa->next;
	}
}

static char	ft_check_double(t_ps ps)
{
	t_list	*tmp;
	int		len;

	len = ft_lstlen(ps.lpa);
	ft_lststart(ps.lpa);
	while (ps.lpa->next != NULL)
	{
		ft_lststart(ps.lpa);
		tmp = ft_lstremove(&(ps.lpa));
		if (ft_lstfindcont(ps.lpa, tmp->content)
			&& ft_lstfindsize(ps.lpa, tmp->size))
		{
			if (M_ERROR != (M_ERROR & ps.opt))
				write(2, "Error\n", 6);
			else if (M_COLOR == (M_COLOR & ps.opt))
				ft_printf("%[fd2]the \033[31m%\"lld\"\033[0m] value "
					"is gived twice time or more", tmp->size);
			else
				ft_printf("%[fd2]the \"%lld\" value is gived"
					" twice time or more", tmp->size);
			return (0);
		}
	}
	return (1);
}

void		ft_get_arg(int ac, char **av, int i, t_ps *ps)
{
	if (M_INF == (M_INF & ps->opt))
		ps->lpa = ft_lstnew(ft_strdup(av[i]), 0);
	else
		ps->lpa = ft_lstnew(NULL, ft_atoi(av[i]));
	while (++i < ac)
	{
		if (M_INF != (M_INF & ps->opt))
			ft_lstaddend(&(ps->lpa), ft_lstnew(NULL, ft_atoi(av[i])));
		else
			ft_lstaddend(&(ps->lpa), ft_lstnew(NULL, ft_atoi(av[i])));
	}
	if (ft_check_double(*ps) == 0)
	{
		if (ft_strequ(av[0], "checker") == 1)
			free(ps->cmd);
		ft_lstdel(&(ps->lpa));
		exit(EXIT_FAILURE);
	}
	if (M_INF == (M_INF & ps->opt))
		ft_order_str(ps);
}
