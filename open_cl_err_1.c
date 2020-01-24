/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_cl_err_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:07:24 by mperseus          #+#    #+#             */
/*   Updated: 2020/01/24 16:07:52 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "open_cl.h"

void	ft_put_error_pn(char *str)
{
	ft_putstr(PROGRAM_NAME);
	ft_putstr(": ");
	ft_putendl(str);
	exit(1);
}

void	ft_put_cl_error(char *str, cl_int err_code)
{
	ft_putstr(PROGRAM_NAME);
	ft_putstr(": ");
	ft_putstr(str);
	ft_putstr(": ");
	ft_putendl(ft_cl_error_interpret(err_code));
	exit(1);
}

char	*ft_cl_error_interpret(cl_int err_code)
{
	if (err_code <= 0 && err_code >= -9)
		return (ft_cl_error_1(err_code));
	if (err_code <= -10 && err_code >= -19)
		return (ft_cl_error_2(err_code));
	if (err_code <= -30 && err_code >= -39)
		return (ft_cl_error_3(err_code));
	if (err_code <= -40 && err_code >= -49)
		return (ft_cl_error_4(err_code));
	if (err_code <= -50 && err_code >= -59)
		return (ft_cl_error_5(err_code));
	if (err_code <= -60 && err_code >= -68)
		return (ft_cl_error_6(err_code));
	else
		return ("CL_UNKNOWN_ERROR");
	return (0);
}

char	*ft_cl_error_1(cl_int err_code)
{
	if (err_code == 0)
		return ("CL_SUCCESS");
	else if (err_code == -1)
		return ("CL_DEVICE_NOT_FOUND");
	else if (err_code == -2)
		return ("CL_DEVICE_NOT_AVAILABLE");
	else if (err_code == -3)
		return ("CL_COMPILER_NOT_AVAILABLE");
	else if (err_code == -4)
		return ("CL_MEM_OBJECT_ALLOCATION_FAILURE");
	else if (err_code == -5)
		return ("CL_OUT_OF_RESOURCES");
	else if (err_code == -6)
		return ("CL_OUT_OF_HOST_MEMORY");
	else if (err_code == -7)
		return ("CL_PROFILING_INFO_NOT_AVAILABLE");
	else if (err_code == -8)
		return ("CL_MEM_COPY_OVERLAP");
	else if (err_code == -9)
		return ("CL_IMAGE_FORMAT_MISMATCH");
	else
		return (0);
}
