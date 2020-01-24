/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_cl_run.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:12:19 by mperseus          #+#    #+#             */
/*   Updated: 2020/01/24 21:10:04 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "open_cl.h"

void	execute_cl_kernel(t_open_cl *open_cl)
{
	cl_int	err_code;

	if (!(open_cl->buf = clCreateBuffer(open_cl->context, CL_MEM_WRITE_ONLY,
	open_cl->global_work_size * sizeof(int), NULL, &err_code)))
		ft_put_cl_error("clCreateBuffer error", err_code);
	if ((err_code = clSetKernelArg(open_cl->kernel, 0, sizeof(cl_mem),
	(void *)&(open_cl->buf))))
		ft_put_cl_error("clSetKernelArg error", err_code);
	if ((err_code = clEnqueueNDRangeKernel(open_cl->command_queue,
	open_cl->kernel, 1, NULL, &(open_cl->global_work_size),
	&(open_cl->local_work_size), 0, NULL, NULL)))
		ft_put_cl_error("clEnqueueNDRangeKernel error", err_code);
}

void	get_cl_result(t_open_cl *open_cl)
{
	cl_int	err_code;

	int *res = (int *)malloc(sizeof(int) * open_cl->global_work_size);
	if ((err_code = clEnqueueReadBuffer(open_cl->command_queue, open_cl->buf,
	CL_TRUE, 0, open_cl->global_work_size * sizeof(int), res, 0, NULL, NULL)))
		ft_put_cl_error("clEnqueueReadBuffer error", err_code);
	int i = open_cl->global_work_size;
	while (i-- > 0)
		printf("%d\n", res[i]);
}

void	clean_cl(t_open_cl *open_cl)
{
	cl_int	err_code;

	if ((err_code = clFlush(open_cl->command_queue)))
		ft_put_cl_error("clFlush error", err_code);
	if ((err_code = clFinish(open_cl->command_queue)))
		ft_put_cl_error("clFinish error", err_code);
	if ((err_code = clReleaseKernel(open_cl->kernel)))
		ft_put_cl_error("clReleaseKernel error", err_code);
	if ((err_code = clReleaseProgram(open_cl->program)))
		ft_put_cl_error("clReleaseProgram error", err_code);
	if ((err_code = clReleaseMemObject(open_cl->buf)))
		ft_put_cl_error("clReleaseMemObject error", err_code);
	if ((err_code = clReleaseCommandQueue(open_cl->command_queue)))
		ft_put_cl_error("clReleaseCommandQueue error", err_code);
	if ((err_code = clReleaseContext(open_cl->context)))
		ft_put_cl_error("clReleaseContext error", err_code);
}

void	run_open_cl(void)
{
	t_open_cl	*open_cl;

	open_cl = init_struct_open_cl();
	init_open_cl(open_cl);
	get_cl_info(open_cl);
	read_cl_kernel(open_cl);
	load_cl_kernel(open_cl);
	printf("This program uses OpenCL %s driver\n", open_cl->driver_ver);
	printf("Platform: %s\n", open_cl->platform_name);
	printf("Device: %s\n", open_cl->device_name);
	printf("Compute units max: %u\n", open_cl->device_comp_units);
	printf("Clock frequency max: %u\n", open_cl->device_frequency);
	execute_cl_kernel(open_cl);
	get_cl_result(open_cl);
	clean_cl(open_cl);
}
