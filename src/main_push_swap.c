/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 19:57:57 by awajsbro          #+#    #+#             */
/*   Updated: 2018/05/20 11:56:29 by awajsbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int			main(int ac, char **av)
{
	int		j;
	int		i;
	t_ps	ps;
	char	**arg;

	if (ac < 2)
		return (0);
	ps.fdr = 0;
	ps.fdw = 1;
	ps.opt = 0;
	j = ac;
	i = 1;
	arg = ft_merge(&j, av);
	ft_get_setting(j, arg, &i, &ps);
	ft_check_arg(j, arg, i, &ps);
	ft_get_arg(j, arg, i, &ps);
	ft_deltab(arg, j);
	if (ft_check_result(&ps) == 1)
		return (0);
	ps.cmd = ft_strnew(1);
	(ps.cmd)[0] = M_VID;
	ft_solve_select(&ps);
	ft_reduce(&ps);
	ft_dellst(ps.lpa, ps.lpb);
	return (0);
}
