/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_cl.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:05:42 by mperseus          #+#    #+#             */
/*   Updated: 2020/01/24 21:07:31 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPEN_CL_H

# define OPEN_CL_H

# include "./libft/libft.h"
# include <OpenCL/opencl.h>

# define PROGRAM_NAME		"open_cl_test"

# define SOURCE_NAME		"open_cl_test.cl"
# define KERNEL_NAME		"open_cl_test"
# define MAX_SOURCE_SIZE	8192

# define IMG_SIZE_X			8
# define IMG_SIZE_Y			8

# define DEVICE				CL_DEVICE_TYPE_GPU
# define LOCAL_WORK_SIZE	4

typedef struct			s_open_cl
{
	cl_platform_id		platform_id;
	cl_device_id		device_id;
	cl_context			context;
	cl_command_queue	command_queue;
	cl_program			program;
	cl_kernel			kernel;

	char				*platform_name;
	char				*device_name;
	char				*driver_ver;
	cl_uint				device_comp_units;
	cl_uint				device_frequency;

	size_t				source_size;
	char				*source_str;

	size_t				global_work_size;
	size_t				local_work_size;

	cl_mem				buf;
}						t_open_cl;

int						main(void);

t_open_cl				*init_struct_open_cl(void);
void					init_open_cl(t_open_cl *open_cl);
void					read_cl_kernel(t_open_cl *open_cl);
void					load_cl_kernel(t_open_cl *open_cl);

void					get_device_info_1(t_open_cl *open_cl);
void					get_device_info_2(t_open_cl *open_cl);
void					get_platform_info(t_open_cl *open_cl);
void					get_cl_info(t_open_cl *open_cl);

void					execute_cl_kernel(t_open_cl *open_cl);
void					get_cl_result(t_open_cl *open_cl);
void					clean_cl(t_open_cl *open_cl);
void					run_open_cl(void);

void					ft_put_error_pn(char *str);
void					ft_put_cl_error(char *str, cl_int err_code);
char					*ft_cl_error_interpret(cl_int err_code);
char					*ft_cl_error_1(cl_int err_code);

char					*ft_cl_error_2(cl_int err_code);
char					*ft_cl_error_3(cl_int err_code);
char					*ft_cl_error_4(cl_int err_code);
char					*ft_cl_error_5(cl_int err_code);
char					*ft_cl_error_6(cl_int err_code);

#endif
