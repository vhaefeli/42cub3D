/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <vhaefeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:26:15 by jleroux           #+#    #+#             */
/*   Updated: 2022/12/23 20:35:00 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "keys.h"

static int	move_forward(t_data *data)
{
	double	x;
	double	y;

	x = data->player.pos.x + (0.2 * data->player.dir.x);
	y = data->player.pos.y + (0.2 * data->player.dir.y);
	if (data->map[(int)y][(int)x] == '0' || data->map[(int)y][(int)x] == '-')
	{
		data->player.pos.x = data->player.pos.x + 0.1 * data->player.dir.x;
		data->player.pos.y = data->player.pos.y + 0.1 * data->player.dir.y;
	}
	else if (data->map[(int)data->player.pos.y][(int)x] == '0')
		data->player.pos.x = data->player.pos.x + 0.1 * data->player.dir.x;
	else if (data->map[(int)y][(int)data->player.pos.x] == '0')
		data->player.pos.y = data->player.pos.y + 0.1 * data->player.dir.y;
	else if (data->map[(int)data->player.pos.y][(int)x] == '-')
		data->player.pos.x = data->player.pos.x + 0.1 * data->player.dir.x;
	else if (data->map[(int)y][(int)data->player.pos.x] == '-')
		data->player.pos.y = data->player.pos.y + 0.1 * data->player.dir.y;
	return (1);
}

static int	move_backward(t_data *data)
{
	double	x;
	double	y;

	x = data->player.pos.x - 0.2 * data->player.dir.x;
	y = data->player.pos.y - 0.2 * data->player.dir.y;
	if (data->map[(int)y][(int)x] == '0' || data->map[(int)y][(int)x] == '-')
	{
		data->player.pos.x = data->player.pos.x - 0.1 * data->player.dir.x;
		data->player.pos.y = data->player.pos.y - 0.1 * data->player.dir.y;
	}
	else if (data->map[(int)data->player.pos.y][(int)x] == '0')
		data->player.pos.x = data->player.pos.x - 0.1 * data->player.dir.x;
	else if (data->map[(int)y][(int)data->player.pos.x] == '0')
		data->player.pos.y = data->player.pos.y - 0.1 * data->player.dir.y;
	else if (data->map[(int)data->player.pos.y][(int)x] == '-')
		data->player.pos.x = data->player.pos.x - 0.1 * data->player.dir.x;
	else if (data->map[(int)y][(int)data->player.pos.x] == '-')
		data->player.pos.y = data->player.pos.y - 0.1 * data->player.dir.y;
	return (1);
}

static int	move_left(t_data *data)
{
	double	x;
	double	y;

	x = data->player.pos.x + 0.2 * data->player.dir.y;
	y = data->player.pos.y - 0.2 * data->player.dir.x;
	if (data->map[(int)y][(int)x] == '0' || data->map[(int)y][(int)x] == '-')
	{
		data->player.pos.x = data->player.pos.x + 0.1 * data->player.dir.y;
		data->player.pos.y = data->player.pos.y - 0.1 * data->player.dir.x;
	}
	else if (data->map[(int)data->player.pos.y][(int)x] == '0')
		data->player.pos.x = data->player.pos.x + 0.1 * data->player.dir.y;
	else if (data->map[(int)y][(int)data->player.pos.x] == '0')
		data->player.pos.y = data->player.pos.y - 0.1 * data->player.dir.x;
	else if (data->map[(int)data->player.pos.y][(int)x] == '-')
		data->player.pos.x = data->player.pos.x + 0.1 * data->player.dir.y;
	else if (data->map[(int)y][(int)data->player.pos.x] == '-')
		data->player.pos.y = data->player.pos.y - 0.1 * data->player.dir.x;
	return (1);
}

static int	move_right(t_data *data)
{
	double	x;
	double	y;

	x = data->player.pos.x - 0.2 * data->player.dir.y;
	y = data->player.pos.y + 0.2 * data->player.dir.x;
	if (data->map[(int)y][(int)x] == '0' || data->map[(int)y][(int)x] == '-')
	{
		data->player.pos.x = data->player.pos.x - 0.1 * data->player.dir.y;
		data->player.pos.y = data->player.pos.y + 0.1 * data->player.dir.x;
	}
	else if (data->map[(int)data->player.pos.y][(int)x] == '0')
		data->player.pos.x = data->player.pos.x - 0.1 * data->player.dir.y;
	else if (data->map[(int)y][(int)data->player.pos.x] == '0')
		data->player.pos.y = data->player.pos.y + 0.1 * data->player.dir.x;
	else if (data->map[(int)data->player.pos.y][(int)x] == '-')
		data->player.pos.x = data->player.pos.x - 0.1 * data->player.dir.y;
	else if (data->map[(int)y][(int)data->player.pos.x] == '-')
		data->player.pos.y = data->player.pos.y + 0.1 * data->player.dir.x;
	return (1);
}

int	move(int key, t_data *data)
{
	if (key == KEY_W || key == KEY_UP)
		return (move_forward(data));
	else if (key == KEY_A)
		return (move_left(data));
	else if (key == KEY_S || key == KEY_DOWN)
		return (move_backward(data));
	else if (key == KEY_D)
		return (move_right(data));
	else if (key == KEY_Q || key == KEY_LEFT)
		return (turn_left(data));
	else if (key == KEY_E || key == KEY_RIGHT)
		return (turn_right(data));
	return (0);
}
