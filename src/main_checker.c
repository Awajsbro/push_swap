/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 18:43:06 by awajsbro          #+#    #+#             */
/*   Updated: 2018/05/16 16:54:58 by awajsbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_exec_cmd(char *s, t_ps *ps)
{
	if (ft_strequ(s, "rra"))
		ft_revers_roll(ps, 'a');
	else if (ft_strequ(s, "rrb"))
		ft_revers_roll(ps, 'b');
	else if (ft_strequ(s, "rrr"))
		ft_revers_roll(ps, 'r');
	else if (ft_strequ(s, "sa"))
		ft_swap(ps, 'a');
	else if (ft_strequ(s, "sb"))
		ft_swap(ps, 'b');
	else if (ft_strequ(s, "ss"))
		ft_swap(ps, 's');
	else if (ft_strequ(s, "pa"))
		ft_push(ps, 'a');
	else if (ft_strequ(s, "pb"))
		ft_push(ps, 'b');
	else if (ft_strequ(s, "ra"))
		ft_roll(ps, 'a');
	else if (ft_strequ(s, "rb"))
		ft_roll(ps, 'b');
	else if (ft_strequ(s, "rr"))
		ft_roll(ps, 'r');
}

char		ft_check_cmd(char *s, t_ps *ps)
{
	ft_exec_cmd(s, ps);
	if (ft_strequ(s, "rra") || ft_strequ(s, "rrb") || ft_strequ(s, "rrr")
		|| ft_strequ(s, "sa") || ft_strequ(s, "sb") || ft_strequ(s, "ss")
			|| ft_strequ(s, "pa") || ft_strequ(s, "pb")
				|| ft_strequ(s, "ra") || ft_strequ(s, "rb")
					|| ft_strequ(s, "rr") || *s == 0)
		return (1);
	return (0);
}

static void	ft_get_cmd(t_ps *ps)
{
	char	*s;

	while (get_next_line(ps->fdr, &s) == 1)
	{
		if (ft_check_cmd(s, ps) == 0)
		{
			ft_error_cm(s, ps);
			free(s);
			ft_dellst(LPA, LPB);
			exit(EXIT_FAILURE);
		}
		free(s);
	}
}

static void	ft_checker(int ac, char **av, t_ps *ps)
{
	int		i;

	i = 1;
	ft_get_setting(ac, av, &i, ps);
	ft_check_arg(ac, av, i, ps);
	ft_get_arg(ac, av, i, ps);
	ft_deltab(av, ac);
	ps->len = ft_lstlen(LPA);
	if ((ps->opt & M_VISUAL) == M_VISUAL)
		visualiser(ps);
	ft_get_cmd(ps);
	if (ft_check_result(ps) == 1)
	{
		if ((ps->opt & M_COLOR) == M_COLOR)
			write(ps->fdw, "\033[32mOK\n\033[0m", 12);
		else
			write(ps->fdw, "OK\n", 3);
	}
	else
	{
		if ((ps->opt & M_COLOR) == M_COLOR)
			write(ps->fdw, "\033[31mKO\n\033[0m", 12);
		else
			write(ps->fdw, "KO\n", 3);
	}
}

int			main(int ac, char **av)
{
	t_ps		ps;
	char		**arg;

	if (ac < 2)
		return (0);
	ps.fdr = 0;
	ps.fdw = 1;
	ps.opt = 0;
	ps.cmd = (char*)malloc(1);
	ps.cmd[0] = 0;
	arg = ft_merge(&ac, av);
	ft_checker(ac, arg, &ps);
	exit(EXIT_SUCCESS);
	return (0);
}
