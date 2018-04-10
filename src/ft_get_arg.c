/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 18:16:42 by awajsbro          #+#    #+#             */
/*   Updated: 2018/04/10 18:09:02 by awajsbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

#define M_COLOR		0x01
#define M_VISUAL	0x02
#define M_LONG		0x04
#define M_ERROR		0x08
#define M_INF		0x10

static void	ft_order_str(t_ps *ps)
{
	long		len;
	long		pos;
	t_list	*tmp;
	t_list	*cp;

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
	t_list	*tmp;

	ps.lpa = ft_lststart(ps.lpa);
	while (ps.lpa->next != NULL)
	{
		tmp = ps.lpa->next;
		while (tmp != NULL)
		{
		 	if (ft_strequ(tmp->content, ps.lpa->content) == 1)
			{
				if (M_ERROR != (M_ERROR & ps.opt))
					write(2, "Error\n", 6);
				else if (M_COLOR == (M_COLOR & ps.opt))
					ft_printf("%[fd2]the \033[31m\"%s\"\033[0m] value "
						"is gived twice time or more\n", tmp->content);
				else
					ft_printf("%[fd2]the \"%s\" value is gived"
						" twice time or more\n", tmp->content);
				return (0);
			}
			tmp = tmp->next;
		}
		ps.lpa = ps.lpa->next;
	}
	return (1);
}

void	ft_lstprint(t_list *lst)
{
	if (lst == NULL)
		return ;
	lst = ft_lststart(lst);
	while (lst->next != NULL)
	{
		ft_printf("%-4s ->> %2d\n", lst->content, lst->size);
		lst = lst->next;
	}
	ft_printf("%-4s ->> %2d\n", lst->content, lst->size);
}

void		ft_get_arg(long ac, char **av, long i, t_ps *ps)
{
	ps->lpa = ft_lstnew(ft_strdup(av[i]), 0);
	while (++i < ac)
	{
		ft_lstaddend(&(ps->lpa), ft_lstnew(av[i], 0));
	}
	if (ft_check_double(*ps) == 0)
	{
		ft_lstdel(&(ps->lpa));
		exit(EXIT_FAILURE);
	}
	ft_order_str(ps);
ft_lstprint(ps->lpa);
	ps->lpb = NULL;
}
