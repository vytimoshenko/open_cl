/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_cl_err_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 20:15:47 by mperseus          #+#    #+#             */
/*   Updated: 2020/01/24 15:54:55 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "open_cl.h"

char	*ft_cl_error_2(cl_int err_code)
{
	if (err_code == -10)
		return ("CL_IMAGE_FORMAT_NOT_SUPPORTED");
	else if (err_code == -11)
		return ("CL_BUILD_PROGRAM_FAILURE");
	else if (err_code == -12)
		return ("CL_MAP_FAILURE");
	else if (err_code == -13)
		return ("CL_MISALIGNED_SUB_BUFFER_OFFSET");
	else if (err_code == -14)
		return ("CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST");
	else if (err_code == -15)
		return ("CL_COMPILE_PROGRAM_FAILURE");
	else if (err_code == -16)
		return ("CL_LINKER_NOT_AVAILABLE");
	else if (err_code == -17)
		return ("CL_LINK_PROGRAM_FAILURE");
	else if (err_code == -18)
		return ("CL_DEVICE_PARTITION_FAILED");
	else if (err_code == -19)
		return ("CL_KERNEL_ARG_INFO_NOT_AVAILABLE");
	else
		return (0);
}

char	*ft_cl_error_3(cl_int err_code)
{
	if (err_code == -30)
		return ("CL_INVALID_VALUE");
	else if (err_code == -31)
		return ("CL_INVALID_DEVICE_TYPE");
	else if (err_code == -32)
		return ("CL_INVALID_PLATFORM");
	else if (err_code == -33)
		return ("CL_INVALID_DEVICE");
	else if (err_code == -34)
		return ("CL_INVALID_CONTEXT");
	else if (err_code == -35)
		return ("CL_INVALID_QUEUE_PROPERTIES");
	else if (err_code == -36)
		return ("CL_INVALID_COMMAND_QUEUE");
	else if (err_code == -37)
		return ("CL_INVALID_HOST_PTR");
	else if (err_code == -38)
		return ("CL_INVALID_MEM_OBJECT");
	else if (err_code == -39)
		return ("CL_INVALID_IMAGE_FORMAT_DESCRIPTOR");
	else
		return (0);
}

char	*ft_cl_error_4(cl_int err_code)
{
	if (err_code == -40)
		return ("CL_INVALID_IMAGE_SIZE");
	else if (err_code == -41)
		return ("CL_INVALID_SAMPLER");
	else if (err_code == -42)
		return ("CL_INVALID_BINARY");
	else if (err_code == -43)
		return ("CL_INVALID_BUILD_OPTIONS");
	else if (err_code == -44)
		return ("CL_INVALID_PROGRAM");
	else if (err_code == -45)
		return ("CL_INVALID_PROGRAM_EXECUTABLE");
	else if (err_code == -46)
		return ("CL_INVALID_KERNEL_NAME");
	else if (err_code == -47)
		return ("CL_INVALID_KERNEL_DEFINITION");
	else if (err_code == -48)
		return ("CL_INVALID_KERNEL");
	else if (err_code == -49)
		return ("CL_INVALID_ARG_INDEX");
	else
		return (0);
}

char	*ft_cl_error_5(cl_int err_code)
{
	if (err_code == -50)
		return ("CL_INVALID_ARG_VALUE");
	else if (err_code == -51)
		return ("CL_INVALID_ARG_SIZE");
	else if (err_code == -52)
		return ("CL_INVALID_KERNEL_ARGS");
	else if (err_code == -53)
		return ("CL_INVALID_WORK_DIMENSION");
	else if (err_code == -54)
		return ("CL_INVALID_WORK_GROUP_SIZE");
	else if (err_code == -55)
		return ("CL_INVALID_WORK_ITEM_SIZE");
	else if (err_code == -56)
		return ("CL_INVALID_GLOBAL_OFFSET");
	else if (err_code == -57)
		return ("CL_INVALID_EVENT_WAIT_LIST");
	else if (err_code == -58)
		return ("CL_INVALID_EVENT");
	else if (err_code == -59)
		return ("CL_INVALID_OPERATION");
	else
		return (0);
}

char	*ft_cl_error_6(cl_int err_code)
{
	if (err_code == -60)
		return ("CL_INVALID_GL_OBJECT");
	else if (err_code == -61)
		return ("CL_INVALID_BUFFER_SIZE");
	else if (err_code == -62)
		return ("CL_INVALID_MIP_LEVEL");
	else if (err_code == -63)
		return ("CL_INVALID_GLOBAL_WORK_SIZE");
	else if (err_code == -64)
		return ("CL_INVALID_PROPERTY");
	else if (err_code == -65)
		return ("CL_INVALID_IMAGE_DESCRIPTOR");
	else if (err_code == -66)
		return ("CL_INVALID_COMPILER_OPTIONS");
	else if (err_code == -67)
		return ("CL_INVALID_LINKER_OPTIONS");
	else if (err_code == -68)
		return ("CL_INVALID_DEVICE_PARTITION_COUNT");
	else
		return (0);
}
