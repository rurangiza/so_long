/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 10:13:21 by arurangi          #+#    #+#             */
/*   Updated: 2022/11/27 15:28:37 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// Check if node has neem visited, based on coordinates
int	not_visited(t_node *queue, int head)
{
	int		i;
	t_node	current;

	current = queue[head];
	i = 0;
	while (i < head)
	{
		if (queue[i].row == current.row && queue[i].col == current.col)
		{
			ft_printf("Visited [%d][%d]\n", current.row, current.col);
			return (0);
		}
		ft_printf("Not visited [%d][%d]\n", current.row, current.col);
		i++;
	}
	return (1);
}

// Add node to a matrix of nodes
t_node	add_node(int row, int col)
{
	t_node	node;

	node.row = row;
	node.col = col;
	return (node);
}

// Check if an exit was found
int	found_exit(t_game *game, t_node node)
{
	if (game->map[node.row][node.col] == 'E')
		return (1);
	return (0);
}

// Add all friends to the queue
void	add_neighbours(t_game *game, t_node *queue, int head, int *tail)
{
	t_node	current;
	int		pos;
	int		row;
	int		col;

	current = add_node(queue[head].row, queue[head].col);
	pos = head + 1;
	row = current.row - 1;
	while (row <= current.row + 1)
	{
		col = current.col - 1;
		while (col <= current.col + 1)
		{
			// Avoid walls
			if (game->map[row][col] == '1')
				col++;
			// Avoid center
			else if ((row == current.row) && (col == current.col))
				col++;
			// Add node
			else
			{
				queue[pos++] = add_node(row, col);
				*tail += 1;
				col++;
			}
		}
		row++;
	}
}