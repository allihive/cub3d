/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_closed.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:00:29 by mito              #+#    #+#             */
/*   Updated: 2024/09/20 16:11:33 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// static int	only_char(char *str, char c)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i] != '\0')
// 	{
// 		if (str[i] != c && str[i] != ' ' && str[i] != '\t')
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

// static	int	check_wall_rows(char **map) // tate
// {
// 	int	last_row;

// 	last_row = count_2darray_size(map);
// 	if (!(only_char(map[0], '1')))
// 		return (0);
// 	if (!(only_char(map[last_row - 1], '1')))
// 		return (0);
// 	return (1);
// }

// static int	check_wall_columns(char **map) // yoko
// {
// 	int	i;
// 	int	last_idx;

// 	i = 0;
// 	last_idx = 0;
// 	while (map[i] != NULL)
// 	{
// 		last_idx = ft_strlen(map[i]) - 1;
// 		if ((map[i][0] != '1' && map[i][0] != ' ' && map[i][0] != '\t')
// 			|| (map[i][last_idx] != '1' && map[i][last_idx] != ' ' && map[i][last_idx] != '\t'))
// 			{
// 				return (0);
// 			}
// 		i++;
// 	}
// 	return (1);
// }

// int	is_map_closed(char **map)
// {
// 	if (!(check_wall_columns(map) && check_wall_rows(map)))
// 		return (0);
// 	return (1);
// }

static int is_map_closed_recursive(char **map, int player_y, int player_x)
{
	if (player_y < 0 || player_x < 0 || !map[player_y] || !map[player_y][player_x])
        return (0);
    if (map[player_y][player_x] == '1')
        return (1);

    map[player_y][player_x] = '1';

	if (!is_map_closed_recursive(map, player_y + 1, player_x))
		return (0);
    if (!is_map_closed_recursive(map, player_y - 1, player_x))
		return (0);
    if (!is_map_closed_recursive(map, player_y, player_x + 1))
		return (0);
    if (!is_map_closed_recursive(map, player_y, player_x - 1))
		return (0);
	return (1);
}

int is_map_closed(t_game *game, char **map, int player_y, int player_x)
{
	char **temp;
	int	result;

	result = 0;
	temp = copy_2darray(map);
	if (!temp)
	{
		free_grid(temp);
		clean_up_exit(game, ": failed copy_2darray() in is map closed()");
	}
	result = is_map_closed_recursive(temp, player_y, player_x);
	free_grid(temp);
    return (result);
}
