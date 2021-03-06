/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 16:11:01 by awajsbro          #+#    #+#             */
/*   Updated: 2018/05/20 13:33:15 by awajsbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <mlx.h>

# define LPA			ps->lpa
# define LPB			ps->lpb
# define M_COLOR		0x01
# define M_VISUAL		0x02
# define M_ERROR		0x04
# define M_INF			0x08
# define M_COUNT		0x10
# define M_SA			1
# define M_SB			2
# define M_RA			3
# define M_RB			4
# define M_RRA			5
# define M_RRB			6
# define M_PA			7
# define M_PB			8
# define M_SS			10
# define M_RR			20
# define M_RRR			30
# define M_BA			40
# define M_BB			50
# define M_VID			90

typedef struct	s_visu
{
	void		*mlx;
	void		*win;
	void		*img_ptr;
	char		*img;
	int			bpp;
	int			s_l;
	int			endian;
	char		stop;
	char		end;
	int			delay;
	int			xsize;
	int			ysize;
}				t_visu;

typedef struct	s_ps
{
	t_list		*lpa;
	t_list		*lpb;
	int			len;
	char		opt;
	char		*cmd;
	int			fdr;
	int			fdw;
	t_visu		*visu;
}				t_ps;

void			ft_push(t_ps *ps, char m);
void			ft_swap(t_ps *ps, char m);
void			ft_roll(t_ps *ps, char m);
void			ft_revers_roll(t_ps *ps, char m);
char			push(t_ps *ps, char m, t_list **start, t_list **end);
char			swap(t_ps *ps, char m, t_list **start, t_list **end);
char			roll(t_ps *ps, char m, t_list **start, t_list **end);
char			revers_roll(t_ps *ps, char m, t_list **start, t_list **end);
char			**ft_merge(int *ac, char **av);
void			ft_get_setting(int ac, char **av, int *i, t_ps *ps);
void			ft_check_arg(int ac, char **av, int i, t_ps *ps);
char			ft_check_cmd(char *s, t_ps *ps);
void			ft_get_arg(int ac, char **av, int i, t_ps *ps);
void			ft_solve_select(t_ps *ps);
void			ft_reduce(t_ps *ps);
void			ft_under6(t_ps *ps);
void			ft_rm_comeback_b_first(char *s, int i, int j);
void			ft_rm_comeback_a_first(char *s, int i, int j);
void			ft_reduce_by_a(char *s, int i, int j);
void			ft_reduce_by_b(char *s, int i, int j);
char			ft_order_lst(t_list *lst);
char			ft_check_result(t_ps *ps);
char			ft_max(t_list *lst);
int				ft_find_min_roll(t_list *lst, int val);
void			ft_error(char **av, int i, int j, t_ps *ps);
void			ft_error_cm(char *cm, t_ps *ps);
void			ft_error_double(t_list *tmp, t_ps ps);
void			ft_deltab(char **av, int len);
void			ft_dellst(t_list *lsa, t_list *lsb);
void			ft_lstdebug(t_ps *ps);
int				ft_exec_key(int key, t_visu *visu);
void			visualiser(t_ps *ps);
void			ft_setup_visu(t_ps *ps);

#endif
