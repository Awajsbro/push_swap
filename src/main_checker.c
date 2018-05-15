/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 18:43:06 by awajsbro          #+#    #+#             */
/*   Updated: 2018/05/13 17:23:16 by awajsbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_exec_cmd(char *s, t_ps *ps)
{
	if (ft_strequ(s, "rra\n"))
		ft_revers_roll(ps, 'a');
	else if (ft_strequ(s, "rrb\n"))
		ft_revers_roll(ps, 'b');
	else if (ft_strequ(s, "rrr\n"))
		ft_revers_roll(ps, 'r');
	else if (ft_strequ(s, "sa\n"))
		ft_swap(ps, 'a');
	else if (ft_strequ(s, "sb\n"))
		ft_swap(ps, 'b');
	else if (ft_strequ(s, "ss\n"))
		ft_swap(ps, 's');
	else if (ft_strequ(s, "pa\n"))
		ft_push(ps, 'a');
	else if (ft_strequ(s, "pb\n"))
		ft_push(ps, 'b');
	else if (ft_strequ(s, "ra\n"))
		ft_roll(ps, 'a');
	else if (ft_strequ(s, "rb\n"))
		ft_roll(ps, 'b');
	else if (ft_strequ(s, "rr\n"))
		ft_roll(ps, 'r');
}

static char	ft_check_cmd(char *s, t_ps *ps)
{
	ft_exec_cmd(s, ps);
	if (ft_strequ(s, "rra\n") || ft_strequ(s, "rrb\n") || ft_strequ(s, "rrr\n")
		|| ft_strequ(s, "sa\n") || ft_strequ(s, "sb\n") || ft_strequ(s, "ss\n")
			|| ft_strequ(s, "pa\n") || ft_strequ(s, "pb\n")
				|| ft_strequ(s, "ra\n") || ft_strequ(s, "rb\n")
					|| ft_strequ(s, "rr\n") || *s == '\n')
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
	exit(EXIT_SUCCESS);
}

int			main(int ac, char **av)
{
	t_ps		ps;
	char		**arg;

	if (ac < 2)
		return (0);
	ps.fdr = 0;
	ps.fdw = 1;
	ps.cmd = (char*)malloc(1);
	ps.cmd[0] = 0;
	arg = ft_merge(&ac, av);
	ft_checker(ac, arg, &ps);
	return (0);
}
