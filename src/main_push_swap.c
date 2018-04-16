/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 19:57:57 by awajsbro          #+#    #+#             */
/*   Updated: 2018/04/15 16:10:42 by awajsbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int			main(int ac, char **av)
{
	long long	j;
	long long	i;
	t_ps		ps;
	char		**arg;

	if (ac < 2)
		return (0);
	ps.pro = 1;
	ps.fdr = 0;
	ps.fdw = 1;
	j = ac;
	i = 1;
	arg = ft_merge(&j, av);
	ft_get_setting(j, arg, &i, &ps);
	ft_check_arg(j, arg, i, &ps);
	ft_get_arg(j, arg, i, &ps);
	if (ft_check_order(&ps) == 0)
		ft_solve(&ps);
	ft_deltab(arg, j);
	ft_dellst(&ps);
	exit(EXIT_SUCCESS);
	return (0);
}
