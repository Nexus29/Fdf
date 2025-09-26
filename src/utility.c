/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <glancell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 02:02:07 by glancell          #+#    #+#             */
/*   Updated: 2025/09/25 20:49:13 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static float	calculate_cos_term(float x_squared, int i, float *term)
{
	float	denominator;

	denominator = (2 * i - 1) * (2 * i);
	*term *= x_squared / denominator;
	return (*term);
}

float	ft_cosf(float x)
{
	float	result;
	float	term;
	float	x_squared;
	int		i;

	result = 1.0f;
	term = 1.0f;
	i = 1;
	while (x > 2 * M_PI)
		x -= 2 * M_PI;
	while (x < 0)
		x += 2 * M_PI;
	x_squared = x * x;
	while (i <= 10)
	{
		term = calculate_cos_term(x_squared, i, &term);
		if (i % 2 == 1)
			result -= term;
		else
			result += term;
		if (fabsf(term) < 0.0000001f)
			break ;
		i++;
	}
	return (result);
}

static float	calculate_sin_term(float x_squared, int i, float *term)
{
	float	denominator;

	denominator = (2 * i) * (2 * i + 1);
	*term *= x_squared / denominator;
	return (*term);
}

float	ft_sinf(float x)
{
	float	result;
	float	term;
	float	x_squared;
	int		i;

	result = x;
	term = x;
	i = 1;
	while (x > 2 * M_PI)
		x -= 2 * M_PI;
	while (x < 0)
		x += 2 * M_PI;
	x_squared = x * x;
	while (i <= 10)
	{
		term = calculate_sin_term(x_squared, i, &term);
		if (i % 2 == 1)
			result -= term;
		else
			result += term;
		if (fabsf(term) < 0.0000001f)
			break ;
		i++;
	}
	return (result);
}
