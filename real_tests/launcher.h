/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 14:32:11 by jtoty             #+#    #+#             */
/*   Updated: 2017/02/12 20:45:39 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LAUNCHER_H
# define LAUNCHER_H

# include "lu_printf.h"
# include "lu_libft.h"
# include "libft.h"
# include "libunit.h"
# include <strings.h>

int				test_launch(void);
int				atoi_launcher(void);
int				atoi_basic_test_01(void);
int				atoi_basic_test_02(void);
int				atoi_hard_test_03(void);
int				atoi_hard_test_04(void);
int				strdup_launcher(void);
int				strdup_basic_test_01(void);
int				strdup_null_test_02(void);
int				strdup_hard_test_03(void);
int				strlen_launcher(void);
int				strlen_basic_test_01(void);
int				strlen_basic_test_02(void);
int				strlen_hard_test_03(void);
int				strlen_null_test_04(void);
int				strsplit_launcher(void);
int				strsplit_basic_test_01(void);
int				strsplit_basic_test_02(void);
int				strsplit_hard_test_03(void);
int				strsplit_null_test_04(void);
int				putchar_launcher(void);
int				putchar_basic_test_01(void);
int				ft_bzero_launcher(void);
int				ft_bzero_all_test(void);
int				bzero_basic(void);
int				ft_isalnum_launcher(void);
int				ft_isalnum_all_test(void);
int				ft_isalpha_launcher(void);
int				ft_isalpha_all_test(void);
int				ft_isascii_launcher(void);
int				ft_isascii_all(void);
int				ft_isdigit_launcher(void);
int				ft_isdigit_all(void);
int				ft_isprint_launcher(void);
int				ft_isprint_all(void);
int				ft_memalloc_launcher(void);
int				ft_memalloc_basic(void);
int				ft_memccpy_launcher(void);
int				ft_memccpy_basic(void);
int				itoa_launcher(void);
int				itoa_basic_test(void);
int				itoa_int_min_test(void);
int				itoa_zero_value_test(void);

#endif
