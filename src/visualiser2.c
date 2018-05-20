/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualiser2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 15:32:58 by awajsbro          #+#    #+#             */
/*   Updated: 2018/05/20 13:31:10 by awajsbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	line_creation(t_ps *ps, t_list *lst, int i)
{
	int		x;
	int		y;

	x = 40;
	y = ps->visu->ysize - 25;
	while (lst != NULL || x == 40)
	{
		i = lst == NULL ? 0 :
			((ps->visu->xsize - 120) / (2 * ps->len)) * lst->size;
		while (i--)
		{
			ps->visu->img[4 * (x + i) + (4 * ps->visu->xsize * y)] = 0xff;
			ps->visu->img[4 * (x + i) + (4 * ps->visu->xsize * y) + 1] = 0xff;
			ps->visu->img[4 * (x + i) + (4 * ps->visu->xsize * y) + 2] = 0xff;
		}
		if (lst == NULL && x == 40)
		{
			lst = ft_lstend(ps->lpb);
			x = 80 + ((ps->visu->xsize - 120) / (2 * ps->len)) * ps->len;
			y = ps->visu->ysize - 25;
		}
		else
			lst = lst->prev;
		y -= 2;
	}
}

void		ft_setup_visu(t_ps *ps)
{
	if (ps->visu->img_ptr != NULL)
		mlx_destroy_image(ps->visu->mlx, ps->visu->img_ptr);
	ps->visu->img_ptr = mlx_new_image(ps->visu->mlx, ps->visu->xsize,
		ps->visu->ysize);
	ps->visu->img = mlx_get_data_addr(ps->visu->img_ptr, &(ps->visu->bpp),
		&(ps->visu->s_l), &(ps->visu->endian));
	line_creation(ps, ft_lstend(ps->lpa), 0);
	mlx_put_image_to_window(ps->visu->mlx, ps->visu->win,
		ps->visu->img_ptr, 0, 0);
	usleep(ps->visu->delay);
}
