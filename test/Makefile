# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/20 20:07:34 by jtoty             #+#    #+#              #
#    Updated: 2017/02/12 15:30:24 by jtoty            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	test_unit

SRC_PATH1	=	00_launcher.c				\
				01_strlen_ok_test.c			\
				02_strlen_ko_test.c			\
				03_strlen_segv_test.c		\
				04_strlen_buse_test.c		\
				05_strlen_timeout_test.c				

PATH_TEST1	=	./strlen/

SRC			=	$(addprefix $(PATH_TEST1)/,$(SRC_PATH1))

SRC			+=	main.c

PATH_LIBFT	=	../framework/srcs/libft

SRC_LIBFT	=	lu_atoi.c					\
				lu_bzero.c					\
				lu_intmaxtoa_base.c			\
				lu_isalnum.c				\
				lu_isalpha.c				\
				lu_isascii.c				\
				lu_isblank.c				\
				lu_iscntrl.c				\
				lu_isdigit.c				\
				lu_isgraph.c				\
				lu_islower.c				\
				lu_isprint.c				\
				lu_isspace.c				\
				lu_isupper.c				\
				lu_isxdigit.c				\
				lu_itoa.c					\
				lu_itoa_base.c				\
				lu_lstadd.c					\
				lu_lstdel.c					\
				lu_lstdelone.c				\
				lu_lstiter.c				\
				lu_lstmap.c					\
				lu_lstnew.c					\
				lu_memalloc.c				\
				lu_memccpy.c				\
				lu_memchr.c					\
				lu_memcmp.c					\
				lu_memcpy.c					\
				lu_memdel.c					\
				lu_memmove.c				\
				lu_memset.c					\
				lu_nb_words.c				\
				lu_putchar.c				\
				lu_putchar_fd.c				\
				lu_putendl.c				\
				lu_putendl_fd.c				\
				lu_putnbr.c					\
				lu_putnbr_fd.c				\
				lu_putstr.c					\
				lu_putstr_fd.c				\
				lu_str_is_alpha.c			\
				lu_str_is_lowercase.c		\
				lu_str_is_numeric.c			\
				lu_str_is_printable.c		\
				lu_str_is_uppercase.c		\
				lu_strcapitalize.c			\
				lu_strcasecmp.c				\
				lu_strcat.c					\
				lu_strchr.c					\
				lu_strclr.c					\
				lu_strcmp.c					\
				lu_strcpy.c					\
				lu_strdel.c					\
				lu_strdup.c					\
				lu_strequ.c					\
				lu_striter.c				\
				lu_striteri.c				\
				lu_strjoin.c				\
				lu_strlcat.c				\
				lu_strlen.c					\
				lu_strlowcase.c				\
				lu_strmap.c					\
				lu_strmapi.c				\
				lu_strncat.c				\
				lu_strncmp.c				\
				lu_strncpy.c				\
				lu_strndup.c				\
				lu_strnequ.c				\
				lu_strnew.c					\
				lu_strnstr.c				\
				lu_strrchr.c				\
				lu_strsplit.c				\
				lu_strstr.c					\
				lu_strsub.c					\
				lu_strtrim.c				\
				lu_strupcase.c				\
				lu_tolower.c				\
				lu_toupper.c				\
				lu_uintmaxtoa_base.c

PATH_GNL	=	../framework/srcs/get_next_line

SRC_GNL		=	get_next_line.c

PATH_PRINTF =	../framework/srcs/lu_printf

SRC_PRINTF	=	lu_printf.c					\
				manage_arg.c				\
				init_struct.c				\
				get_options.c				\
				get_width.c					\
				get_precision.c				\
				get_modifier.c				\
				get_conv.c					\
				conv_percent.c				\
				conv_i.c					\
				conv_p.c					\
				conv_b.c					\
				conv_n.c					\
				conv_low_c.c				\
				conv_low_d.c				\
				conv_low_o.c				\
				conv_low_s.c				\
				conv_low_u.c				\
				conv_low_x.c				\
				conv_low_f.c				\
				conv_low_f_snd_part.c		\
				conv_low_e.c				\
				conv_low_e_snd_part.c		\
				conv_low_e_thd_part.c		\
				conv_low_a.c				\
				conv_low_a_snd_part.c		\
				conv_low_a_thd_part.c		\
				conv_low_g.c				\
				conv_up_c.c					\
				conv_up_d.c					\
				conv_up_o.c					\
				conv_up_s.c					\
				conv_up_u.c					\
				conv_up_x.c					\
				conv_up_f.c					\
				conv_up_e.c					\
				conv_up_g.c					\
				conv_up_a.c					\
				set_modifier.c				\
				fill_buffer.c				\
				fill_buffer_double.c		\
				manage_buffer.c				\
				spacing_number.c			\
				set_colors.c				\
				set_column.c				\
				get_arg_conv.c				\
				utils.c

PATH_FRAMEWORK	=	../framework/srcs/libunit

SRC_FRAMEWORK	=	lu_launch_tests.c

OBJ			=	$(SRC:.c=.o)

CPPFLAGS	=	-I../framework/includes -I./

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

$(NAME) : $(OBJ)
		make -C ../framework
		$(CC) $(CFLAGS) $(OBJ) $(CPPFLAGS) ../framework/libunit.a -o $(NAME)

all : $(NAME)

test : all
	./$(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all re fclean clean
