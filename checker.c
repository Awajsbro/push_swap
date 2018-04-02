/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 15:06:20 by awajsbro          #+#    #+#             */
/*   Updated: 2018/04/02 18:58:56 by awajsbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

#define M_COLOR		0x01
#define M_VISUAL	0x02
#define M_LONG		0x04
#define M_ERROR		0x08
#define M_INF		0x10

static char	ft_check_cmd(char **s)
{
	while (*s[0] != 0)
	{
		if (ft_strnequ(*s, "rra\n", 4) || ft_strnequ(*s, "rrb\n", 4)
			|| ft_strnequ(*s, "rrr\n", 4))
			*s = *s + 4;
		else if (ft_strnequ(*s, "sa\n", 3) || ft_strnequ(*s, "sb\n", 3)
			|| ft_strnequ(*s, "ss\n", 3) || ft_strnequ(*s, "pa\n", 3)
				|| ft_strnequ(*s, "pb\n", 3) || ft_strnequ(*s, "ra\n", 3)
					|| ft_strnequ(*s, "rb\n", 3)
						|| ft_strnequ(*s, "rr\n", 3))
			*s = *s + 3;
		else if (*s[0] == '\n')
			*s = *s + 1;
		else
		{
			ft_strncpy(*s, *s, ft_strclen(*s, '\n'));
			return (0);
		}
	}
	return (1);
}

static void	ft_get_cmd(t_ps *ps)
{
	char	*tmp;
	char	*cm;

	cm = ft_strnew(0);
	tmp = ft_strnew(31);
	while (read(0, tmp, 31) > 0)
	{
		cm = ft_joinfree(cm, tmp);
		tmp = ft_strnew(31);
	}
	free(tmp);
	tmp = cm;
	if (ft_check_cmd(&cm) == 0)
	{
		if (M_ERROR != (M_ERROR & ps->opt))
			write(2, "Error\n", 6);
		else if (M_COLOR == (M_COLOR & ps->opt))
			ft_printf("%[fd2]%{rou}\"%s\"\033[0m isn't a valid command\n", cm);
		else
			ft_printf("%[fd2]\"%s\" isn't a valid command\n", cm);
		free(tmp);
		exit(EXIT_FAILURE);
	}
	ps->cmd = cm;
}


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
	ft_get_cmd(&ps);
	ft_get_arg(ac, av, i, &ps);
	return (0);
}
