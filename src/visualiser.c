/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualiser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 14:35:52 by awajsbro          #+#    #+#             */
/*   Updated: 2018/05/20 13:32:09 by awajsbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#define ESC 53
#define SPACE 49
#define UARROW 126
#define DARROW 125
#define LARROW 123
#define RARROW 124

int				ft_exec_key(int key, t_visu *visu)
{
	if (key == ESC)
	{
		mlx_destroy_window(visu->mlx, visu->win);
		exit(EXIT_SUCCESS);
	}
	else if (key == DARROW || key == LARROW)
		visu->delay = visu->delay == 0 ? 2 : visu->delay * 2;
	else if (key == RARROW || key == UARROW)
		visu->delay = visu->delay / 2;
	else if (key == SPACE)
		visu->stop = visu->stop == 1 ? 0 : 1;
	return (0);
}

static void		check_solve(t_ps *ps)
{
	if (ft_check_result(ps) == 1)
	{
		if ((ps->opt & M_COLOR) == M_COLOR)
			write(ps->fdw, "\033[32mOK\n\033[0m", 12);
		else
			write(ps->fdw, "OK\n", 3);
		mlx_string_put(ps->visu->mlx, ps->visu->win, (ps->visu->xsize / 2) - 30,
			ps->visu->ysize / 2, 0x0000ff00, "SORTED");
	}
	else
	{
		mlx_string_put(ps->visu->mlx, ps->visu->win, (ps->visu->xsize / 2) - 45,
			ps->visu->ysize / 2, 0x00ff0000, "UNSORTED");
		if ((ps->opt & M_COLOR) == M_COLOR)
			write(ps->fdw, "\033[31mKO\n\033[0m", 12);
		else
			write(ps->fdw, "KO\n", 3);
	}
	ft_dellst(LPB, LPA);
	ps->visu->end = 1;
}

static void		ft_print_message(t_ps *ps)
{
	static int	c = 0;
	char		*s;
	char		out[32];

	s = ft_strjoin("Delay : ", ft_itoab(ps->visu->delay, 10, out));
	mlx_string_put(ps->visu->mlx, ps->visu->win,
		(ps->visu->xsize / 4) - 50, 10, 0x005050ff, s);
	free(s);
	s = ft_strjoin("move : ", ft_itoab(c, 10, out));
	mlx_string_put(ps->visu->mlx, ps->visu->win,
		(3 * (ps->visu->xsize / 4)) - 50, 10, 0x005050ff, s);
	free(s);
	if (ps->visu->stop == 1)
		mlx_string_put(ps->visu->mlx, ps->visu->win,
			(ps->visu->xsize / 2) - 30, 50, 0x00FFF624, "PAUSE");
	else
		c++;
}

static int		ft_visu(t_ps *ps)
{
	char		*s;
	int			gnl;

	if (ps->visu->end == 0)
	{
		mlx_clear_window(ps->visu->mlx, ps->visu->win);
		ft_setup_visu(ps);
		ft_print_message(ps);
		if (ps->visu->stop == 0)
		{
			if ((gnl = get_next_line(ps->fdr, &s) == 1)
				&& ft_check_cmd(s, ps) == 0)
			{
				ft_error_cm(s, ps);
				ft_dellst(LPA, LPB);
				ps->visu->end = 1;
			}
			else if (gnl == 0)
				check_solve(ps);
		}
	}
	return (0);
}

void			visualiser(t_ps *ps)
{
	t_visu		visu;

	ps->visu = &visu;
	ps->visu->stop = 0;
	ps->visu->end = 0;
	ps->visu->delay = 100000;
	ps->visu->xsize = ps->len < 200 ? 520 : (ps->len * 2) + 120;
	ps->visu->ysize = (ps->len * 2) + 100;
	ps->visu->mlx = mlx_init();
	ps->visu->win = mlx_new_window(ps->visu->mlx,
		ps->visu->xsize, ps->visu->ysize, "visualiser");
	mlx_key_hook(ps->visu->win, ft_exec_key, ps->visu);
	mlx_loop_hook(ps->visu->mlx, ft_visu, ps);
	mlx_loop(ps->visu->mlx);
}
