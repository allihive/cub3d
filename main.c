/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:53:20 by mito              #+#    #+#             */
/*   Updated: 2024/09/20 10:23:49 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int main(int argc, char **argv)
{
	t_game *game;

	if (argc != 2)
		print_error_exit(":  "); // think about better err msg
	game = (t_game *)ft_calloc(1, sizeof(t_game));
	if (!game)
		print_error_exit("Malloc failed for game struct");
	init_game(game, argv[1]);
	//for (int j = 0; game->map[j] != NULL; j++) // for testing
	//	printf("Map line %d: %s\n", j, game->map[j]); // for testing
	set_floor_colors(game, game->floor_rgb);
	set_ceiling_colors(game, game->ceiling_rgb);
	if (run_game(game) == 1)
	{
		//do error handlings;
		print_error_exit(": mlx function fail");
	}
	game->raycast = malloc(sizeof(t_raycast));
	find_angle(game);
	// mlx_key_hook(game->mlx, move_hook, game); // this will be for esc
	mlx_loop_hook(game->mlx, math_to_display, game);
	mlx_loop_hook(game->mlx, move_hook, game);
	mlx_loop(game->mlx);
	clean_up(game);
	return (0);
}
