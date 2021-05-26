/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_rotation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 15:22:25 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/03/31 15:22:26 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libcub.h"

void	mouse_rot(t_window *window)
{
	int left_quarter;
	int right_quarter;

	left_quarter = window->game_v->res_w_nu / 4;
	right_quarter = window->game_v->res_w_nu - left_quarter;
	if (window->mouse_pos->pos_x > right_quarter)
		decrement_degree(&window->player->inclination, ONE_D / 4,
						window->player->plane);
	if (window->mouse_pos->pos_x < left_quarter)
		increment_degree(&window->player->inclination, ONE_D / 4,
						window->player->plane);
}
