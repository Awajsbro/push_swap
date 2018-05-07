/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 18:43:06 by awajsbro          #+#    #+#             */
/*   Updated: 2018/05/07 19:02:31 by awajsbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_checker(int ac, char **av, t_ps *ps)
{
	int i;

	i = 1;
	ft_get_setting(ac, av, &i, ps);
	ft_check_arg(ac, av, i, ps);
	ft_get_arg(ac, av, i, ps);
	ft_get_cmd(ps);
	exit(EXIT_FAILURE);
	if (ft_check_result(ps) == 1)
	{
		if ((ps->opt & M_COLOR) == M_COLOR)
			write(1, "\033[32mOK\n\033[0m", 12);
		else
			write(1, "OK\n", 3);
	}
	else
	{
		if ((ps->opt & M_COLOR) == M_COLOR)
			write(1, "\033[32mKO\n\033[0m", 12);
		else
			write(1, "KO\n", 3);
	}
	ft_deltab(av, ac);
	exit(EXIT_SUCCESS);
}

int			main(int ac, char **av)
{
	int	j;
	t_ps		ps;
	char		**arg;

	if (ac < 2)
		return (0);
	ps.fdr = 0;
	ps.fdw = 1;
	j = ac;
	arg = ft_merge(&j, av);
	ft_checker(j, arg, &ps);
	return (0);
}
