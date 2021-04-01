/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 12:31:43 by tbillon           #+#    #+#             */
/*   Updated: 2021/04/01 14:31:46 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	triangle_intersection(t_thread *th)
{
	t_resolve	res;
	t_vectors	v1;
	t_vectors	v2;
	t_vectors	tvec;
	t_vectors	pvec;

	v1 = vec_minus(th->rt.element.sec_coord, th->rt.element.first_coord);
	v2 = vec_minus(th->rt.element.third_coord, th->rt.element.first_coord);
	pvec = vec_cross_prod(th->ray.dir, v2);
	res.delta = dot(v1, pvec);
	if (ft_abs(res.delta) < 0.00001)
		return (0);
	res.deamon = 1 / res.delta;
	tvec = vec_minus(th->ray.orig, th->rt.element.first_coord);
	res.a = dot(tvec, pvec) * res.deamon;
	if (res.a < 0 || res. a > 1)
		return (0);
	tvec = vec_cross_prod(tvec, v1);
	res.b = dot(th->ray.dir, tvec) * res.deamon;
	if (res.b < 0 || res.a + res.b > 1)
		return (0);
	th->rt.t = dot(v2, tvec) * res.deamon;
	th->P.x = vec_plus(th->ray.orig, vec_x(th->rt.t, th->ray.norm_dir)).x;
	th->P.y = -vec_plus(th->ray.orig, vec_x(th->rt.t, th->ray.norm_dir)).y;
	th->P.z = vec_plus(th->ray.orig, vec_x(th->rt.t, th->ray.norm_dir)).z;
	th->N.x = unit_vector(vec_minus(th->P, th->rt.element.orig)).x;
	th->N.y = unit_vector(vec_minus(th->P, th->rt.element.orig)).y;
	th->N.z = unit_vector(vec_minus(th->P, th->rt.element.orig)).z;
	return (1);
}

void	put_triangle(t_thread *th, int index)
{
	if (triangle_intersection(th))
	{
		t_vectors	pxl_intensity;
		
		pxl_intensity.x = ((th->rt.element.color.b + th->rt.light.color.b) / 2) * (1 - dot(unit_vector(vec_plus(th->rt.light.orig, th->P)), th->N));
		pxl_intensity.y = ((th->rt.element.color.g + th->rt.light.color.g) / 2) * (1 - dot(unit_vector(vec_plus(th->rt.light.orig, th->P)), th->N));
		pxl_intensity.z = ((th->rt.element.color.r + th->rt.light.color.r) / 2) * (1 - dot(unit_vector(vec_plus(th->rt.light.orig, th->P)), th->N));
		pxl_intensity = check_intensity(pxl_intensity);
		th->rt.img->data[index - 2] = (unsigned char)pxl_intensity.x * th->rt.light.ratio;
		th->rt.img->data[index - 1] = (unsigned char)pxl_intensity.y * th->rt.light.ratio;
		th->rt.img->data[index] = (unsigned char)pxl_intensity.z * th->rt.light.ratio;
	}
}