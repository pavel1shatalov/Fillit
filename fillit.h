/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 14:45:34 by ggerhold          #+#    #+#             */
/*   Updated: 2019/02/14 16:44:53 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "get_next_line.h"
# include "libft/libft.h"
# include <fcntl.h>

int		ft_fchecker(char *file);
int		ft_mchecker(char *file);
int		ft_nbtetr(char *file);
int		get_next_line(const int fd, char **line);
int		*ft_coder(char *file);
char	*ft_map(size_t size);
int		ft_fill(int *code, char *map, int n);
int		ft_recur(int *code, char *map, int n);
int		ft_backtrack(int *code, char *map, int n);
int		ft_nblock(int *code, int n);
void	ft_cupdate(int *code);
char	*ft_mupdate(int *code, char *map);
int		ft_search(char *map, int nb);
void 	ft_delete(char *map, int nb);

#endif
