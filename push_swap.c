/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 19:57:57 by awajsbro          #+#    #+#             */
/*   Updated: 2018/04/02 15:20:54 by awajsbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

#define M_COLOR		0x01
#define M_VISUAL	0x02
#define M_LONG		0x04
#define M_ERROR		0x08
#define M_INF		0x10

int			main(int ac, char **av)
{
	int		i;
	t_ps	ps;

	if (ac < 2)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	i = 1;
	ps.fdr = 1;
	ps.fdw = 1;
	ft_get_setting(ac, av, &i, &ps);
	ft_check(ac, av, i, &ps);
	ft_get_arg(ac, av, i, &ps);
	return (0);
}
