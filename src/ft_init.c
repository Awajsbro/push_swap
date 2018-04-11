/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 17:30:54 by awajsbro          #+#    #+#             */
/*   Updated: 2018/04/11 19:03:03 by awajsbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
		else if (av[*i][1] == 'c' || av[*i][1] == 'C')
			ps->opt = (ps->opt | M_COLOR);
		else if (av[*i][1] == 'v' || av[*i][1] == 'V')
			ps->opt = (ps->opt | M_VISUAL);
		else if (av[*i][1] == 'e' || av[*i][1] == 'E')
			ps->opt = (ps->opt | M_ERROR);
		else if (av[*i][1] == 'i' || av[*i][1] == 'I')
			ps->opt = (ps->opt | M_INF);
		else
		{
			ft_error(av, 0, 0, ps);
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

void		ft_check_arg(long long ac, char **av, long long i, t_ps *ps)
{
	long long		j;
	long long	tmp;
	char		cnt;
	char		len;

	if (ac - i < 1)
		i = ac + 1;
	while (i < ac)
	{
		j = i;
		len = ft_strlen(av[j]);
		tmp = ft_atoi(av[j]);
		cnt = tmp < 0 ? ft_cntb(tmp, 10) + 1 : ft_cntb(tmp, 10);
		if (ft_strdigit(av[j]) == 0)
			i = ac + 2;
		else if ((tmp > 2147483647 || tmp < -2147483648)
			&& (ps->opt & M_INF) != M_INF)
			i = ac + 1;
		i++;
	}
	if (i > ac)
	{
		ft_error(av, i - ac, j, ps);
		ft_deltab(av, ac);
		exit(EXIT_FAILURE);
	}
}

static char	**ft_real_merge(long long *ac, char **av, long long cnt)
{
	char	**tab;
	char	**tmp;
	long long	i;
	long long	j;
	long long	w;

	tab = (char**)malloc(sizeof(tab) * cnt);
	cnt = 0;
	j = 0;
	while (j < *ac)
	{
		i = 0;
		w = -1;
		tmp = ft_strsplit(av[cnt], ' ');
		while (av[cnt][i] != 0)
		{
			if (av[cnt][i] != ' ')
			{
				while (av[cnt][i] != ' ' && av[cnt][i] != 0)
					i++;
				w++;
				tab[j] = ft_strdup(tmp[w]);
				j++;
			}
			while (av[cnt][i] == ' ')
				i++;
		}
		ft_deltab(tmp, w + 1);
		cnt++;
	}
	return (tab);
}

char	**ft_merge(long long *ac, char **av)
{
	long long	i;
	long long	j;
	long long	cnt;

	i = -1;
	cnt = 0;
	while (++i < *ac)
	{
		j = 0;
		while (av[i][j] != 0)
		{
			if (av[i][j] != ' ')
			{
				while (av[i][j] != ' ' && av[i][j] != 0)
					j++;
				cnt++;
			}
			while (av[i][j] == ' ')
				j++;
		}
	}
	*ac = cnt;
	return (ft_real_merge(ac, av, cnt));
}
