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

typedef struct				f_list {
	unsigned long long		id;
	unsigned short			x0;
	unsigned short			y0;
	unsigned short			x1;
	unsigned short			y1;
	unsigned short			x2;
	unsigned short			y2;
	unsigned short			x3;
	unsigned short			y3;
	struct f_list			*next;
}							f_list;

typedef struct			tet_list {
	unsigned short		tet[4];
	struct f_list		*name;
	char				c;
	unsigned short		xi;
	unsigned short		yi;
	struct tet_list		*next;

}						tet_list;


void				ft_flstaddend(tet_list **alst, tet_list *new);
tet_list			*ft_flstnew(char c, unsigned short *tetro);
void				ft_flstdel(tet_list **alst);
void				ft_flstreset(tet_list *tetro);

unsigned int		mingridsize(unsigned int ret, tet_list **head);
int					inbound(tet_list *node, unsigned int s);
int					overlap(unsigned short *grid, tet_list *node);
void				impress(unsigned short *grid, tet_list *node);
tet_list			*shift(tet_list *node, unsigned int rbound);

void spitresult(tet_list **head, unsigned int s);

unsigned int		valid_input(int fd, tet_list **head);

void				fillit(int fd);

#endif
