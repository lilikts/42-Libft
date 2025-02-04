/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_target.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:55:54 by lkloters          #+#    #+#             */
/*   Updated: 2025/02/04 15:10:11 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	flood_fill_target(char **map, int x, int y, char target)
{
	if (x < 0 || y < 0 || !map[y] || map[y][x] == '\0' || map[y][x] == target || map[y][x] == 'F')
		return ;
	map[y][x] = 'F';
	flood_fill(map, x + 1, y, target);
	flood_fill(map, x - 1, y, target);
	flood_fill(map, x, y + 1, target);
	flood_fill(map, x, y - 1, target);
}
