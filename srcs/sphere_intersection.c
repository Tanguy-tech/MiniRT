/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 10:32:24 by tbillon           #+#    #+#             */
/*   Updated: 2021/03/29 08:32:22 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

/* return 1 if there is an intersection between a ray and an object, otherwise return 0 */
int	sphere_intersection(t_thread *th)
{
	t_resolve	*res;

	res = initialize_resolve();
	res->sub = vec_minus(th->ray->orig, th->rt.element->orig);
	res->a = dot(th->ray->norm_dir, th->ray->norm_dir);
	res->b = 2 * dot(res->sub, th->ray->norm_dir);
	res->c = dot(res->sub, res->sub) - (th->rt.element->ray * th->rt.element->ray);
	res->delta = res->b * res->b - (4 * (res->a * res->c));
	if (res->delta < 0)
		return (0); /* if delta is less than 0 -> no intersection return 0 */
	res->t1 = (-res->b - sqrt(res->delta)) / (2 * res->a);
	res->t2 = (-res->b + sqrt(res->delta)) / (2 * res->a);
	if (res->t2 < 0)
		return (0);
	if (res->t1 > 0)
		res->t_res = res->t1;
	else
		res->t_res = res->t2;
	th->P->x = vec_plus(th->ray->orig, vec_x(res->t_res, th->ray->norm_dir))->x;
	th->P->y = -vec_plus(th->ray->orig, vec_x(res->t_res, th->ray->norm_dir))->y;
	th->P->z = vec_plus(th->ray->orig, vec_x(res->t_res, th->ray->norm_dir))->z;
	th->N->x = unit_vector(vec_minus(th->P, th->rt.element->orig))->x;
	th->N->y = unit_vector(vec_minus(th->P, th->rt.element->orig))->y;
	th->N->z = unit_vector(vec_minus(th->P, th->rt.element->orig))->z;
	return (1);
}

void	put_sphere(t_thread *th, int index)
{
	if (sphere_intersection(th))
	{
		t_vectors	*pxl_intensity;
		
		pxl_intensity = initialize_vector();
		pxl_intensity->x = th->rt.element->color->b * 100000 * dot(unit_vector(vec_minus(th->rt.light->orig, th->P)), th->N) / get_norme2(vec_minus(th->rt.light->orig, th->P));
		pxl_intensity->y = th->rt.element->color->g * 100000 * dot(unit_vector(vec_minus(th->rt.light->orig, th->P)), th->N) / get_norme2(vec_minus(th->rt.light->orig, th->P));
		pxl_intensity->z = th->rt.element->color->r * 100000 * dot(unit_vector(vec_minus(th->rt.light->orig, th->P)), th->N) / get_norme2(vec_minus(th->rt.light->orig, th->P));
		pxl_intensity = check_intensity(pxl_intensity);
		th->rt.img->data[index - 2] = (unsigned char)pxl_intensity->x * th->rt.light->ratio;
		th->rt.img->data[index - 1] = (unsigned char)pxl_intensity->y * th->rt.light->ratio;
		th->rt.img->data[index] = (unsigned char)pxl_intensity->z * th->rt.light->ratio;
	}
}
