/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 17:30:54 by awajsbro          #+#    #+#             */
/*   Updated: 2018/04/02 17:58:54 by awajsbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define M_COLOR		0x01
#define M_VISUAL	0x02
#define M_LONG		0x04
#define M_ERROR		0x08
#define M_INF		0x10

static void ft_more_error(char **av, int i, int j, t_ps *ps)
{
	if (i == 4 && M_COLOR == (M_COLOR & ps->opt))
		ft_printf("%[fd2]%{rou}\"%s\"\033[0m is more than 64bit value, can't store it "
			"with or without %{ble}%{state_gras}'-l'\033[0m option\n", av[j]);
	else if (i == 4)
		ft_printf("%[fd2]\"%s\" is more than 64bit value, can't store it "
			"with or without '-l' option\n", av[j]);
	else if (i == 0)
		ft_printf("%[fd2]usage: %s [-c | -v | -l | -e | -i | [-r <path>] | "
			"[-w <path>]] %{state_soul}Data ...\033[0m\n", &av[0][2]);
	else if (i == -1)
		ft_putendl_fd("a wild probleme appears", 2);
	else
		ft_putendl_fd("si tu vois ça c'est que je suis full planté", 2);
	exit(EXIT_FAILURE);
}

void		ft_error(char **av, int i, int j, t_ps *ps)
{
	if	(M_ERROR != (M_ERROR & ps->opt))
	{
		if (M_COLOR == (M_COLOR & ps->opt))
			ft_putstr_fd("\033[1;31mError\033[0m\n", 2);
		else
			write(2, "Error\n", 6);
	}
	else if (i == 1 && M_COLOR == (M_COLOR & ps->opt))
		ft_printf("%[fd2]usage: %s [-c | -v | -l | -e | [-r <path>] | [-w <path>]] "
			"%{state_soul}%{rou}Data ...%{reset_stat}\n"
				"Data is missing\033[0m\n", &av[0][2]);
	else if (i == 1)
		ft_printf("%[fd2]usage: \"%s\" [-c | -v | -l | -e | [-r <path>] | [-w <path>]] "
			"%{state_soul}Data ...%{reset_stat}\nData is missing\n", &av[0][2]);
	else if (i == 2 && M_COLOR == (M_COLOR & ps->opt))
		ft_printf("%[fd2]%{rou}\"%s\"\033[0m isn't an int value, please try "
			"%{ble}%{state_gras}'-l'\033[0m option\n", av[j]);
	else if (i == 2)
		ft_printf("%[fd2]\"%s\" isn't an int value, please try '-l' option\n", av[j]);
	else if (i == 3 && M_COLOR == (M_COLOR & ps->opt))
		ft_printf("%[fd2]%{rou}\"%s\"\033[0m isn't a valid number\n", av[j]);
	else if (i == 3)
		ft_printf("%[fd2]\"%s\" isn't a valid number\n", av[j]);
	else
		ft_more_error(av, i, j, ps);
	exit(EXIT_FAILURE);
}

static void	ft_end_of_setting(char **av, t_ps *ps)
{
	if (ft_strcmp(av[ps->fdr], av[ps->fdr]) == 1 && ps->fdr != 1)
	{
		ps->fdr = open(av[ps->fdr], O_RDWR | O_APPEND);
		ps->fdw = ps->fdr;
	}
	else
	{
		if (ps->fdr != 1)
			ps->fdr = open(av[ps->fdr], O_RDONLY);
		if (ps->fdw != 1)
			ps->fdw = open(av[ps->fdw], O_WRONLY | O_CREAT | O_TRUNC);
	}
	if (ps->fdr == -1 || ps->fdw == -1)
		ft_error(av, -1, -1, ps);
}

void		ft_get_setting(int ac, char **av, int *i, t_ps *ps)
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
		else if (av[*i][1] == 'l' || av[*i][1] == 'L')
			ps->opt = (ps->opt | M_LONG);
		else if (av[*i][1] == 'e' || av[*i][1] == 'E')
			ps->opt = (ps->opt | M_ERROR);
		else if (av[*i][1] == 'i' || av[*i][1] == 'I')
			ps->opt = (ps->opt | M_INF);
		else
			ft_error(av, 0, 0, ps);
		(*i)++;
		if (*i == ac)
			break;
	}
	ft_end_of_setting(av, ps);
}

void		ft_check(int ac, char **av, int i, t_ps *ps)
{
	int			j;
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
		if ((tmp > 2147483647 || tmp < -2147483648) && (ps->opt & M_LONG) != M_LONG)
			i = ac + 1;
		if (ft_isdigit(av[j][0]) == 0 || len != cnt)
			i = ac + 2;
		else if ((ft_strcmp(av[j], "-9223372036854775808") > 0
			&& av[j][0] == '-' && len > 19) || (av[j][0] != '-' && len > 18
				&& ft_strcmp(av[j], "9223372036854775807") > 0))
			i = ac + 3;
		i++;
	}
	if (i > ac)
		ft_error(av, i - ac, j, ps);
}
