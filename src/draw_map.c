/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:16:17 by arurangi          #+#    #+#             */
/*   Updated: 2022/11/23 12:11:59 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	draw_map(t_game *game)
{
	if (map_is_valid(game))
	{
		ft_printf("\nHourra! The map is valid!\n");
		//load_assets(game);
	}
	else
		ft_printf("\nMap is not valid!\n");
}
