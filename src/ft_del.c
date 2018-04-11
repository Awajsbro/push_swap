/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 17:35:04 by awajsbro          #+#    #+#             */
/*   Updated: 2018/04/11 18:56:41 by awajsbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_deltab(char **tab, long long len)
{
	long long	i;

	i = -1;
	while (++i < len)
		ft_strdel(&tab[i]);
	free(tab);
}

void	ft_dellst(t_ps *ps)
{
	if (ps->lpa != NULL)
		ft_lstdel(&(ps->lpa));
	if (ps->lpb != NULL)
		ft_lstdel(&(ps->lpb));
}
