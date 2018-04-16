/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 17:30:54 by awajsbro          #+#    #+#             */
/*   Updated: 2018/04/15 17:25:32 by awajsbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void		ft_check_arg(long long ac, char **av, long long i, t_ps *ps)
{
	long long	j;
	long long	tmp;
	char		m;

	if (ac - i < 1)
		i = ac + 1;
	while (i < ac)
	{
		j = i;
		tmp = ft_atoi(av[j]);
		m = tmp < 0 ? ft_cntb(tmp, 10) + 1 : ft_cntb(tmp, 10);
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

static char	ft_word(char *s, long long *i)
{
	char		w;

	w = 0;
	if (s[*i] != ' ' && s[*i] != 0)
	{
		w = 1;
		while (s[*i] != ' ' && s[*i] != 0)
			(*i)++;
	}
	while (s[*i] == ' ')
		(*i)++;
	return (w);
}

static char	**ft_real_merge(long long *ac, char **av, char **tab, long long m)
{
	char		**tmp;
	long long	i;
	long long	j;
	long long	w;

	j = 0;
	while (j < *ac)
	{
		i = 0;
		w = -1;
		tmp = ft_strsplit(av[m], ' ');
		while (av[m][i] != 0)
		{
			if (ft_word(av[m], &i) == 1)
			{
				w++;
				tab[j] = ft_strdup(tmp[w]);
				j++;
			}
		}
		ft_deltab(tmp, w + 1);
		m++;
	}
	return (tab);
}

char		**ft_merge(long long *ac, char **av)
{
	long long	i;
	long long	j;
	long long	cnt;
	char		**tab;

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
	tab = (char**)malloc(sizeof(tab) * cnt);
	return (ft_real_merge(ac, av, tab, 0));
}
