/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 13:06:44 by awajsbro          #+#    #+#             */
/*   Updated: 2018/04/12 17:40:31 by awajsbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_more_space(long long ac, char **av, long long *i, t_ps *ps)
{
	long long	j;

	j = 0;
	while (av[*i][++j] != 0)
	{
		if (av[*i][j] == 'c' || av[*i][j] == 'C')
			ps->opt = (ps->opt | M_COLOR);
		else if (av[*i][j] == 'v' || av[*i][j] == 'V')
			ps->opt = (ps->opt | M_VISUAL);
		else if (av[*i][j] == 'e' || av[*i][j] == 'E')
			ps->opt = (ps->opt | M_ERROR);
		else if (av[*i][j] == 'i' || av[*i][j] == 'I')
			ps->opt = (ps->opt | M_INF);
		else
		{
			ft_error(av, 0, 0, ps);
			ft_deltab(av, ac);
			exit(EXIT_FAILURE);
		}
	}
}

void		ft_get_setting(long long ac, char **av, long long *i, t_ps *ps)
{
	while (av[*i][0] == '-' && ft_isdigit(av[*i][1]) == 0)
	{
		if (av[*i][1] == 'r' || av[*i][1] == 'R')
		{
			(*i)++;
			ps->fdr = *i;
		}
		else if (av[*i][1] == 'w' || av[*i][1] == 'W')
		{
			(*i)++;
			ps->fdw = *i;
		}
		else if (av[*i][1] == 'c' || av[*i][1] == 'C' || av[*i][1] == 'v'
			|| av[*i][1] == 'V' || av[*i][1] == 'e' || av[*i][1] == 'E'
				|| av[*i][1] == 'i' || av[*i][1] == 'I')
			ft_more_space(ac, av, i, ps);
		else
		{
			ft_error(av, 0, 0, ps);
			ft_deltab(av, ac);
			exit(EXIT_FAILURE);
		}
		(*i)++;
		if (*i == ac)
			break ;
	}
	if (ft_strcmp(av[ps->fdr], av[ps->fdw]) == 0 && ps->fdr != 0)
	{
		ps->fdr = open(av[ps->fdr], O_RDWR | O_APPEND);
		ps->fdw = ps->fdr;
	}
	else
	{
		if (ps->fdr != 0)
			ps->fdr = open(av[ps->fdr], O_RDONLY);
		if (ps->fdw != 1)
			ps->fdw = open(av[ps->fdw], O_WRONLY | O_CREAT | O_TRUNC);
	}
	if (ps->fdr == -1 || ps->fdw == -1)
	{
		ft_error(av, -1, -1, ps);
		exit(EXIT_FAILURE);
	}
}
