/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 12:37:03 by awajsbro          #+#    #+#             */
/*   Updated: 2018/04/06 18:25:58 by awajsbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

#define M_COLOR		0x01
#define M_VISUAL	0x02
#define M_LONG		0x04
#define M_ERROR		0x08
#define M_INF		0x10

static void	ft_more_error(char **av, long i, long j, t_ps *ps)
{
	if (i == 2)
		ft_printf("%[fd2]\"%s\" isn't an int value, please try '-l' "
			"option\n", av[j]);
	else if (i == 3 && M_COLOR == (M_COLOR & ps->opt))
		ft_printf("%[fd2]%{rou}\"%s\"\033[0m isn't a valid number\n", av[j]);
	else if (i == 3)
		ft_printf("%[fd2]\"%s\" isn't a valid number\n", av[j]);
	else if (i == 4 && M_COLOR == (M_COLOR & ps->opt))
		ft_printf("%[fd2]%{rou}\"%s\"\033[0m is more than 64bit value, can't "
			"store it with or without "
				"%{ble}%{state_gras}'-l'\033[0m option\n", av[j]);
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
}

void		ft_error(char **av, long i, long j, t_ps *ps)
{
	if (M_ERROR != (M_ERROR & ps->opt))
	{
		if (M_COLOR == (M_COLOR & ps->opt))
			ft_putstr_fd("\033[1;31mError\033[0m\n", 2);
		else
			write(2, "Error\n", 6);
	}
	else if (i == 1 && M_COLOR == (M_COLOR & ps->opt))
		ft_printf("%[fd2]usage: %s [-c | -v | -l | -e | [-r <path>] | "
			"[-w <path>]] %{state_soul}%{rou}Data ...%{reset_stat}\n"
				"Data is missing\033[0m\n", &av[0][2]);
	else if (i == 1)
		ft_printf("%[fd2]usage: \"%s\" [-c | -v | -l | -e | [-r <path>] | "
		"[-w <path>]] %{state_soul}Data ...%{reset_stat}\nData is "
			"missing\n", &av[0][2]);
	else if (i == 2 && M_COLOR == (M_COLOR & ps->opt))
		ft_printf("%[fd2]%{rou}\"%s\"\033[0m isn't an int value, please try "
			"%{ble}%{state_gras}'-l'\033[0m option\n", av[j]);
	else
		ft_more_error(av, i, j, ps);
}
