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

typedef struct		a_list 
{
	char			c;
	unsigned short	pos;
	struct a_list	*next;
}					f_list;	

f_list		*ft_flstnew(char c, unsigned short pos);
void	ft_flstaddend(f_list **alst, f_list *new);
//int		valid_input(int fd, f_list **head);
void	fillit(int fd);

#endif