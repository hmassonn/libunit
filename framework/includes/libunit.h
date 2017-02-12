/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 14:19:07 by jtoty             #+#    #+#             */
/*   Updated: 2017/02/11 16:45:24 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_H
# define LIBUNIT_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include "lu_libft.h"

typedef struct			s_lu_test
{
	char		*name;
	int			(*unit_test)(void);
}						t_lu_test;

int						lu_launch_tests(t_lu_test loaded_func[]);
char					*lu_exec_test(int (*unit_test)(void), int *tests_ok);

#endif
