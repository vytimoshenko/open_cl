/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_cl_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:10:54 by mperseus          #+#    #+#             */
/*   Updated: 2020/01/24 16:14:43 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "open_cl.h"

t_open_cl	*init_struct_open_cl(void)
{
	t_open_cl	*open_cl;

	if (!(open_cl = (t_open_cl *)ft_memalloc(sizeof(t_open_cl))))
		ft_put_errno(PROGRAM_NAME);
	open_cl->global_work_size = IMG_SIZE_X * IMG_SIZE_Y;
	open_cl->local_work_size = LOCAL_WORK_SIZE;
	return (open_cl);
}

void		init_open_cl(t_open_cl *open_cl)
{
	cl_int	err_code;

	err_code = 1;
	if ((err_code = clGetPlatformIDs(1, &(open_cl->platform_id), NULL)))
		ft_put_cl_error("clGetPlatformIDs error", err_code);
	if ((err_code = clGetDeviceIDs(open_cl->platform_id, CL_DEVICE_TYPE_GPU, 1,
	&(open_cl->device_id), NULL)))
		ft_put_cl_error("clGetDeviceIDs error", err_code);
	if (!(open_cl->context = clCreateContext(NULL, 1, &(open_cl->device_id),
	NULL, NULL, &err_code)))
		ft_put_cl_error("clCreateContext error", err_code);
	if (!(open_cl->command_queue = clCreateCommandQueue(open_cl->context,
	open_cl->device_id, 0, &err_code)))
		ft_put_cl_error("clCreateCommandQueue error", err_code);
}

void		read_cl_kernel(t_open_cl *open_cl)
{
	int		fd;

	if ((fd = open(SOURCE_NAME, O_RDONLY)) < 0)
		ft_put_errno(PROGRAM_NAME);
	if ((read(fd, NULL, 0)) == -1)
		ft_put_errno(PROGRAM_NAME);
	if (!(open_cl->source_str = (char *)ft_memalloc(sizeof(char)
	* (MAX_SOURCE_SIZE + 1))))
		ft_put_errno(PROGRAM_NAME);
	if ((open_cl->source_size = read(fd, open_cl->source_str,
	MAX_SOURCE_SIZE)) <= 0)
		ft_put_error_pn("OpenCL source file reading error");
	if (read(fd, open_cl->source_str, MAX_SOURCE_SIZE))
		ft_put_error_pn("max OpenCL source file size exceed");
	close(fd);
}

void		load_cl_kernel(t_open_cl *open_cl)
{
	cl_int	err_code;

	err_code = 1;
	if (!(open_cl->program = clCreateProgramWithSource(open_cl->context, 1,
	(const char **)&(open_cl->source_str),
	(const size_t *)&(open_cl->source_size), &err_code)))
		ft_put_cl_error("clCreateProgramWithSource error", err_code);
	free(open_cl->source_str);
	if ((err_code = clBuildProgram(open_cl->program, 1, &(open_cl->device_id),
	NULL, NULL, NULL)))
		ft_put_cl_error("clBuildProgram error", err_code);
	if (!(open_cl->kernel = clCreateKernel(open_cl->program, KERNEL_NAME,
	&err_code)))
		ft_put_cl_error("clCreateKernel error", err_code);
}
