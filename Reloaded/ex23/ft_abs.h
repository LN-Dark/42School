/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 10:23:57 by pbranco-          #+#    #+#             */
/*   Updated: 2024/09/25 10:23:58 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ABS_H
# define FT_ABS_H

static inline int	abs(int x)
{
	if (x < 0)
	{
		return (-x);
	}
	else
	{
		return (x);
	}
}

# define ABS(x) abs(x)
#endif
