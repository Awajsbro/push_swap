/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 13:45:08 by awajsbro          #+#    #+#             */
/*   Updated: 2018/04/22 15:08:00 by awajsbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_solve(t_ps *ps)
{
	t_list		*tmp;
	int	up;
	int	down;

	ps->lpa = ft_lststart(ps->lpa);
	if (ft_lstlen(ps->lpa) < 6)
		ft_under6(ps);
	else
	{
		while (ft_order_resut(ps) == 0)
		{
			up = ft_longestup(ft_lstcpy(ps->lpa));
			down = ft_longestdown(ft_lstcpy(ps->lpa));

		}
	}
}
