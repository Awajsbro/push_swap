/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 16:11:01 by awajsbro          #+#    #+#             */
/*   Updated: 2018/04/17 17:22:34 by awajsbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

# define M_COLOR		0x01
# define M_VISUAL		0x02
# define M_ERROR		0x04
# define M_INF			0x08
# define M_SA			1
# define M_SB			2
# define M_SS			3
# define M_PA			4
# define M_PB			5
# define M_RA			6
# define M_RB			7
# define M_RR			8
# define M_RRA			9
# define M_RRB			10
# define M_RRR			11

typedef struct	s_ps
{
	t_list		*lpa;
	t_list		*lpb;
	char		opt;
	char		*cmd;
	int			fdr;
	int			fdw;
}				t_ps;

char			**ft_merge(long long *ac, char **av);
void			ft_check_arg(long long ac, char **av, long long i, t_ps *ps);
void			ft_get_setting(long long ac, char **av, long long *i, t_ps *ps);
void			ft_get_arg(long long ac, char **av, long long i, t_ps *ps);
void			ft_get_cmd(t_ps *ps);
void			ft_push(t_ps *ps, char m);
void			ft_swap(t_ps *ps, char m);
void			ft_roll(t_ps *ps, char m);
void			ft_revers_roll(t_ps *ps, char m);
void			ft_solve(t_ps *ps);
void			ft_reduce(t_ps *ps);
char			ft_check_order(t_ps *ps);
void			ft_error(char **av, long long i, long long j, t_ps *ps);
void			ft_error_cm(char *cm,t_ps *ps);
void			ft_error_double(t_list *tmp, t_ps ps);
void			ft_deltab(char **av, long long len);
void			ft_dellst(t_ps *ps);

 /*
 **		##	debug ##
 */
void	ft_lstdebug(t_ps *ps);

#endif
