/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan_intersection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 13:21:13 by tbillon           #+#    #+#             */
/*   Updated: 2021/03/29 13:17:07 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int plan_intersection(t_thread *th)
{
	t_resolve res;

	res.deamon = dot(th->rt.element.dir, th->ray.dir);
	if (res.deamon > 1e-6)
	{
		res.sub = vec_minus(th->rt.element.orig, th->ray.orig);
		res.t_res = dot(res.sub, th->rt.element.dir) / res.deamon;
		th->rt.t = res.t_res;
		return (res.t_res >= 0);
	}
	return (0);
}

void	put_plan(t_thread *th, int index)
{
	if (plan_intersection(th))
	{
		t_vectors	pxl_intensity;
		
		pxl_intensity.x = th->rt.element.color.b / (th->rt.t / 100);
		pxl_intensity.y = th->rt.element.color.g / (th->rt.t / 100);
		pxl_intensity.z = th->rt.element.color.r / (th->rt.t / 100);
		pxl_intensity = check_intensity(pxl_intensity);
		th->rt.img->data[index - 2] = (unsigned char)pxl_intensity.x * th->rt.light.ratio;
		th->rt.img->data[index - 1] = (unsigned char)pxl_intensity.y * th->rt.light.ratio;
		th->rt.img->data[index] = (unsigned char)pxl_intensity.z * th->rt.light.ratio;
	}
}