/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaura-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 20:52:43 by tsaura-n          #+#    #+#             */
/*   Updated: 2019/09/12 03:48:03 by tsaura-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/includes/libft.h"

typedef struct				s_f {
	unsigned long long		id;
	unsigned short			x0;
	unsigned short			y0;
	unsigned short			x1;
	unsigned short			y1;
	unsigned short			x2;
	unsigned short			y2;
	unsigned short			x3;
	unsigned short			y3;
	struct s_f				*next;
}							t_f;

typedef struct				s_tet {
	unsigned short			tet[4];
	t_f						*name;
	char					c;
	unsigned short			xi;
	unsigned short			yi;
	struct s_tet			*next;

}							t_tet;

void						ft_flstaddend(t_tet **alst, t_tet *new);
t_tet						*ft_flstnew(char c, unsigned short *tetro);
void						ft_flstdel(t_tet *alst);
void						ft_flstreset(t_tet *tetro);

void						tynorm(unsigned short grid[16], \
									unsigned short *grd, int s, int i);
int							mingridsize(int ret, t_tet **head);
int							inbound(t_tet *node, unsigned int s);
int							overlap(unsigned short *grid, t_tet *node);
void						impress(unsigned short *grid, t_tet *node);
t_tet						*shift(t_tet *node, int s);

void						spitresult(t_tet **head, unsigned int s);

int							valid_input(int fd, t_tet **head);

void						fillit(int fd);

#endif
