/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:22:41 by glancell          #+#    #+#             */
/*   Updated: 2025/03/05 14:24:10 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	find_and_execute_action(
	t_vars *vars,
	int keycode,
	const t_keymap *mappings)
{
	while (mappings->func != NULL)
	{
		if (mappings->key_code == keycode)
		{
			mappings->func(vars);
			return (1);
		}
		mappings++;
	}
	return (0);
}

int	key_press(int keycode, void *param)
{
	t_vars			*vars;
	const t_keymap	key_actions[] = {
	{KEY_ESC, close_window},
	{KEY_PLUS, zoom_in},
	{KEY_MINUS, zoom_out},
	{KEY_W, rotate_x_plus},
	{KEY_S, rotate_x_minus},
	{KEY_A, rotate_y_minus},
	{KEY_D, rotate_y_plus},
	{KEY_UP, translate_up},
	{KEY_DOWN, translate_down},
	{KEY_LEFT, translate_left},
	{KEY_RIGHT, translate_right},
	{KEY_T, toggle_projection},
	{KEY_M, toggle_menu},
	{0, NULL}
	};

	vars = (t_vars *)param;
	find_and_execute_action(vars, keycode, key_actions);
	return (0);
}
