/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:57:20 by joao-alm          #+#    #+#             */
/*   Updated: 2025/01/15 16:33:41 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"
#include "game.h"
#include "graphic_bonus.h"
#include <X11/X.h>
#include <mlx.h>

void	ft_window(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->map.width * TILE_SIZE,
			game->map.height * TILE_SIZE + HEADER_SIZE, "so_long");
	ft_render_map(game);
	game->n_moves = 0;
	mlx_hook(game->win, KeyPress, KeyPressMask, ft_handle_keys, game);
	mlx_hook(game->win, ClientMessage, LeaveWindowMask, ft_press_x, game);
	ft_render_counter(game);
	game->player.glasses = 0;
	mlx_loop_hook(game->mlx, ft_update_player_sprite, game);
	mlx_loop(game->mlx);
}
