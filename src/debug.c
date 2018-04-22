/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 14:06:19 by awajsbro          #+#    #+#             */
/*   Updated: 2018/04/22 12:18:31 by awajsbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_content(t_list *tmp1, t_list *tmp2, int *len)
{
	ft_printf("%[fd2]\n/\033[36;1m%*s\033[0m%*s\033[36;1m%*s\033[0m%*c\n",
		((len[0] + len[1] + 5) / 2) + 3, "lpa", ((len[0] + len[1]) / 2) + 7,
			"\\   /", ((len[0] + len[1] + 5) / 2) + 3, "lpb",
				((len[0] + len[1]) / 2) + 3, '\\');
	while (tmp1 != NULL || tmp2 != NULL)
	{
		if (tmp1 != NULL)
		{
			ft_printf("%[fd2]| %*s ->> %-*lld |", len[0], tmp1->content,
				len[1], tmp1->size);
			tmp1 = tmp1->next;
		}
		else
			ft_printf("%[fd2]| %*|", len[0] + len[1] + 7);
		if (tmp2 != NULL)
		{
			ft_printf("%[fd2]   | %*s ->> %-*lld |\n", len[0], tmp2->content,
				len[1], tmp2->size);
			tmp2 = tmp2->next;
		}
		else
			ft_printf("%[fd2]   | %*|\n", len[0] + len[1] + 7);
	}
}

static void	ft_print_debug(t_ps *ps, int *len)
{
	t_list		*tmp1;
	t_list		*tmp2;
	int	i;

	tmp1 = ps->lpa;
	tmp2 = ps->lpb;
	i = len[0] + len[1] + 7;
	ft_putchar_fd(' ', 2);
	while (i--)
		ft_putchar_fd('_', 2);
	ft_putstr_fd("     ", 2);
	i = len[0] + len[1] + 7;
	while (i--)
		ft_putchar_fd('_', 2);
	ft_content(tmp1, tmp2, len);
	i = len[0] + len[1] + 7;
	ft_putchar_fd('\\', 2);
	while (i--)
		ft_putchar_fd('_', 2);
	ft_putstr_fd("/   \\", 2);
	i = len[0] + len[1] + 7;
	while (i--)
		ft_putchar_fd('_', 2);
	ft_putstr_fd("/\n", 2);
}

void	ft_lstdebug(t_ps *ps)
{
	int	len[2];
	t_list		*tmp;

	ps->lpa = ft_lststart(ps->lpa);
	ps->lpb = ft_lststart(ps->lpb);
	len[0] = ft_strlen(ps->lpa->content);
	tmp = ps->lpa->next;
	while (tmp != NULL)
	{
		len[1] = ft_strlen(tmp->content);
		len[0] = len[0] >= len[1] ? len[0] : len[1];
		tmp = tmp->next;
	}
	tmp = ps->lpb;
	while (tmp != NULL)
	{
		len[1] = ft_strlen(tmp->content);
		len[0] = len[0] >= len[1] ? len[0] : len[1];
		tmp = tmp->next;
	}
	len[1] = ft_cntb(ft_lstlen(ps->lpa) + ft_lstlen(ps->lpb), 10);
	ft_print_debug(ps, len);
}

void	ft_valcmd(t_ps *ps)
{
	char *tmp;

	tmp = ps->cmd + 1;
	while (*tmp)
	{
		ft_putnbr_fd(*tmp, 2);
		ft_putchar_fd('.', 2);
		tmp++;
	}
	ft_putendl_fd("", 2);
}
