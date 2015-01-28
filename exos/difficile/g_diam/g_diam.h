/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_diam.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/18 10:38:03 by exam              #+#    #+#             */
/*   Updated: 2015/01/28 18:39:34 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef G_DIAM_H
# define G_DIAM_H

typedef struct 		s_node
{
	int				visited;
	int				value;
	struct 	s_node	**links;
	int				cur_max;
	int				max;
}					t_node;

#endif
