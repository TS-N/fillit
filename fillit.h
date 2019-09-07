/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaura-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 20:52:43 by tsaura-n          #+#    #+#             */
/*   Updated: 2019/08/21 21:41:52 by tsaura-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/includes/libft.h"



int		valid_input(int fd, t_list **head);
void	fillit(int fd);



typedef struct f_list {
	unsigned long long  id;
	unsigned short      x0;
	unsigned short      y0;
	unsigned short      x1;
	unsigned short      y1;
	unsigned short      x2;
	unsigned short      y2;
	unsigned short      x3;
	unsigned short      y3;
	struct f_list       *next;
}               f_list;


#endif