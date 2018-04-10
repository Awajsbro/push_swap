/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 15:06:20 by awajsbro          #+#    #+#             */
/*   Updated: 2018/04/10 18:15:45 by awajsbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

#define M_COLOR		0x01
#define M_VISUAL	0x02
#define M_LONG		0x04
#define M_ERROR		0x08
#define M_INF		0x10

static char ft_check_cmd(char *s, t_ps *ps)
{
	long long	i;

	i = 0;
	while (s[i] != 0)
	{
ft_putnbr(i); ft_putendl("");
		if (ft_strnequ(&s[i], "rra\n", 4) || ft_strnequ(&s[i], "rrb\n", 4)
			|| ft_strnequ(&s[i], "rrr\n", 4))
		{
			if (ft_strnequ(&s[i], "rra\n", 4))
				ft_revers_roll(ps, 'a');
			else if (ft_strnequ(&s[i], "rrb\n", 4))
				ft_revers_roll(ps, 'b');
			else if (ft_strnequ(&s[i], "rrr\n", 4))
				ft_revers_roll(ps, 'r');
			i = i + 4;
		}
		else if (ft_strnequ(&s[i], "sa\n", 3) || ft_strnequ(&s[i], "sb\n", 3)
			|| ft_strnequ(&s[i], "ss\n", 3) || ft_strnequ(&s[i], "pa\n", 3)
				|| ft_strnequ(&s[i], "pb\n", 3) || ft_strnequ(&s[i], "ra\n", 3)
					|| ft_strnequ(&s[i], "rb\n", 3)
						|| ft_strnequ(&s[i], "rr\n", 3))
		{
			if (ft_strnequ(&s[i], "sa\n", 3))
				ft_swap(ps, 'a');
			else if (ft_strnequ(&s[i], "sb\n", 3))
				ft_swap(ps, 'b');
			else if (ft_strnequ(&s[i], "ss\n", 3))
				ft_swap(ps, 's');
			else if (ft_strnequ(&s[i], "pa\n", 3))
				ft_push(ps, 'a');
			else if (ft_strnequ(&s[i], "pb\n", 3))
				ft_push(ps, 'b');
			else if (ft_strnequ(&s[i], "ra\n", 3))
				ft_roll(ps, 'a');
			else if (ft_strnequ(&s[i], "rb\n", 3))
				ft_roll(ps, 'b');
			else if (ft_strnequ(&s[i], "rr\n", 3))
				ft_roll(ps, 'r');
			i = i + 3;
		}
		else if (s[i] == '\n')
			i = i + 1;
		else
		{
			ft_strncpy(s, &s[i], ft_strclen(&s[i], '\n'));
			return (0);
		}
	}
ft_putendl("sortie");
	return (1);
}

static char	ft_get_cmd(t_ps *ps)
{
	char	*tmp;
	char	*cm;

	cm = ft_strnew(0);
	tmp = ft_strnew(31);
	while (read(ps->fdr, tmp, 30) > 0)
	{
		cm = ft_joinfree(cm, tmp);
		tmp = ft_strnew(31);
	}
	free(tmp);
	tmp = cm;
	if (ft_check_cmd(cm, ps) == 0)
	{
		if (M_ERROR != (M_ERROR & ps->opt))
			write(2, "Error\n", 6);
		else if (M_COLOR == (M_COLOR & ps->opt))
			ft_printf("%[fd2]%{rou}\"%s\"\033[0m isn't a valid command\n", cm);
		else
			ft_printf("%[fd2]\"%s\" isn't a valid command\n", cm);
		free(tmp);
		ft_lstdel(&ps->lpa);
		ft_lstdel(&ps->lpb);
		exit(EXIT_FAILURE);
	}
	return (0);
}

int			main(int ac, char **av)
{
	long	i;
	long	j;
	t_ps	ps;
	char	**arg;

	if (ac < 2)
		return (0);
	i = 1;
	ps.fdr = 0;
	ps.fdw = 1;
	j = ac;
	ft_get_setting(j, av, &i, &ps);
	arg = ft_merge(&j, av);
	ft_check_arg(j, arg, i, &ps);
	ft_get_arg(j, arg, i, &ps);
	if (ft_get_cmd(&ps) == 1)
	{
	ft_putendl("coucou fin")	;
	}
	return (0);
}
