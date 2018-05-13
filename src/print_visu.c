/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_visu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 14:06:19 by awajsbro          #+#    #+#             */
/*   Updated: 2018/05/13 14:45:13 by awajsbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_content_color(t_list *tmp1, t_list *tmp2, int *len, t_ps *ps)
{
	ft_printf("%[fd*]\n/\033[36;1m%*s\033[0m%*s\033[36;1m%*s\033[0m%*c\n",
		ps->fdw, ((len[0] + len[1] + 5) / 2) + 3, "lpa",
			(len[0] + len[1] + 14) / 2, "\\   /", (len[0] + len[1] + 11) / 2,
				"lpb", ((len[0] + len[1]) / 2) + 3, '\\');
	while (tmp1 != NULL || tmp2 != NULL)
	{
		if (tmp1 != NULL)
		{
			ft_printf("%[fd*]| %*s ->> %-*lld |",
				ps->fdw, len[0], tmp1->content,
				len[1], tmp1->size);
			tmp1 = tmp1->next;
		}
		else
			ft_printf("%[fd*]| %*|", ps->fdw, len[0] + len[1] + 7);
		if (tmp2 != NULL)
		{
			ft_printf("%[fd*]   | %*s ->> %-*lld |\n",
				ps->fdw, len[0], tmp2->content,
				len[1], tmp2->size);
			tmp2 = tmp2->next;
		}
		else
			ft_printf("%[fd*]   | %*|\n", ps->fdw, len[0] + len[1] + 7);
	}
}

static void	ft_content(t_list *tmp1, t_list *tmp2, int *len, t_ps *ps)
{
	ft_printf("%[fd*]\n/%*s%*s%*s%*c\n", ps->fdw,
		((len[0] + len[1] + 5) / 2) + 3, "lpa", 	(len[0] + len[1] + 14) / 2,
			"\\   /", (len[0] + len[1] + 11) / 2, "lpb",
				((len[0] + len[1]) / 2) + 3, '\\');
	while (tmp1 != NULL || tmp2 != NULL)
	{
		if (tmp1 != NULL)
		{
			ft_printf("%[fd*]| %*s ->> %-*lld |",
				ps->fdw, len[0], tmp1->content,
				len[1], tmp1->size);
			tmp1 = tmp1->next;
		}
		else
			ft_printf("%[fd*]| %*|", ps->fdw, len[0] + len[1] + 7);
		if (tmp2 != NULL)
		{
			ft_printf("%[fd*]   | %*s ->> %-*lld |\n",
				ps->fdw, len[0], tmp2->content,
				len[1], tmp2->size);
			tmp2 = tmp2->next;
		}
		else
			ft_printf("%[fd*]   | %*|\n", ps->fdw, len[0] + len[1] + 7);
	}
}

static void	ft_print_debug(t_ps *ps, int *len, t_list *tmp1, t_list *tmp2)
{
	int			i;

	tmp1 = LPA;
	tmp2 = LPB;
	i = len[0] + len[1] + 7;
	ft_putchar_fd(' ', ps->fdw);
	while (i--)
		ft_putchar_fd('_', ps->fdw);
	ft_putstr_fd("     ", ps->fdw);
	i = len[0] + len[1] + 7;
	while (i--)
		ft_putchar_fd('_', ps->fdw);
	if ((ps->opt & M_COLOR) == M_COLOR)
		ft_content_color(tmp1, tmp2, len, ps);
	else
		ft_content(tmp1, tmp2, len, ps);
	i = len[0] + len[1] + 7;
	ft_putchar_fd('\\', ps->fdw);
	while (i--)
		ft_putchar_fd('_', ps->fdw);
	ft_putstr_fd("/   \\", ps->fdw);
	i = len[0] + len[1] + 7;
	while (i--)
		ft_putchar_fd('_', ps->fdw);
	ft_putstr_fd("/\n", ps->fdw);
}

void		ft_lstdebug(t_ps *ps)
{
	int			len[2];
	t_list		*tmp;

	LPA = ft_lststart(LPA);
	LPB = ft_lststart(LPB);
	len[0] = LPA != NULL ? ft_strlen(LPA->content) : 0;
	tmp = LPA != NULL ? LPA->next : NULL;
	while (tmp != NULL)
	{
		len[1] = ft_strlen(tmp->content);
		len[0] = len[0] >= len[1] ? len[0] : len[1];
		tmp = tmp->next;
	}
	tmp = LPB;
	while (tmp != NULL)
	{
		len[1] = ft_strlen(tmp->content);
		len[0] = len[0] >= len[1] ? len[0] : len[1];
		tmp = tmp->next;
	}
	len[1] = ft_cntb(ft_lstlen(LPA) + ft_lstlen(LPB), 10);
	ft_print_debug(ps, len, NULL, NULL);
}
