/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 17:30:54 by awajsbro          #+#    #+#             */
/*   Updated: 2018/05/20 19:27:03 by awajsbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

#define MAXINT_S "2147483647"
#define MININT_S "-2147483648"

void		ft_check_arg(int ac, char **av, int i, t_ps *ps)
{
	int		j;
	long	tmp;

	if (ac - i < 1)
		i = ac + 1;
	while (i < ac)
	{
		j = i;
		tmp = ft_atoi(av[j]);
		if (ft_strdigit(av[j]) == 0)
			i = ac + 2;
		else if ((ps->opt & M_INF) != M_INF && (ft_istrcmp(av[j], MAXINT_S) == 1
			|| ft_istrcmp(av[j], MININT_S) == -1))
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

static char	ft_word(char *s, int *i)
{
	char	w;

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

static char	**ft_real_merge(int *ac, char **av, char **tab, int m)
{
	char	**tmp;
	int		i;
	int		j;
	int		w;

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

char		**ft_merge(int *ac, char **av)
{
	static int	i = -1;
	int			j;
	int			cnt;
	char		**tab;

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
	if (*ac == 1 || !(tab = (char**)malloc(sizeof(tab) * cnt)))
		exit(EXIT_FAILURE);
	return (ft_real_merge(ac, av, tab, 0));
}
