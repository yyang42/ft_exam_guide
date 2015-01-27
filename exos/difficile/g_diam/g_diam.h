/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_diam.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/18 10:38:03 by exam              #+#    #+#             */
/*   Updated: 2015/01/27 22:10:15 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef G_DIAM_H
# define G_DIAM_H

typedef struct 		s_node
{
	int				visited;
	int				value;
	struct 	s_node	**links;
}					t_node;

/*
typedef struct		s_count
{
	int				count;
	int				max;
}					t_count;
*/
#endif
