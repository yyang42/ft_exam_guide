/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ord_alphnum.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 14:42:54 by juschaef          #+#    #+#             */
/*   Updated: 2014/12/05 14:55:27 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ORD_ALPHNUM_H
# define ORD_ALPHNUM_H

# include <unistd.h>
# include <stdlib.h>

char	**sort_alpha(char **grid);
char	**sort_by_length(char **grid);
int		size_array(char **array);
int		ft_strlen(char *str);
char	*ft_strdup(char *str);
int		ft_strcmp(char *s1, char *s2);
void	ft_putstr(char *str);
int		ft_isspace(char c);
char	**ft_split(char *str);
char	ft_tolower(char c);
void	ft_strswap(char **s1, char **s2);

#endif
