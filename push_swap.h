/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 16:11:01 by awajsbro          #+#    #+#             */
/*   Updated: 2018/04/06 17:57:10 by awajsbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct	s_ps
{
	t_list		*lpa;
	t_list		*lpb;
	char		opt;
	int			fdr;
	int			fdw;
}				t_ps;

char			**ft_merge(long *ac, char **av);
void			ft_check_arg(long ac, char **av, long i, t_ps *ps);
void			ft_get_setting(long ac, char **av, long *i, t_ps *ps);
void			ft_get_arg(long ac, char **av, long i, t_ps *ps);
void			ft_push(t_ps *ps, char m);
void			ft_swap(t_ps *ps, char m);
void			ft_roll(t_ps *ps, char m);
void			ft_revers_roll(t_ps *ps, char m);
void			ft_error(char **av, long i, long j, t_ps *ps);
void			ft_deltab(char **av, long len);

#endif
