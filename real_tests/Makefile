# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/20 20:07:34 by jtoty             #+#    #+#              #
#    Updated: 2017/02/12 20:41:11 by jtoty            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	test_unit

LIB_PATH	=	./libft/

LIB			=	./libft/libft.a

FRAM_PATH	=	../framework/

LIBA		=	../framework/libunit.a

SRC_PATH1	=	00_strlen_launcher.c		\
				01_strlen_basic_test.c		\
				02_strlen_basic_test.c		\
				03_strlen_hard_test.c		\
				04_strlen_null_test.c

PATH_TEST1	=	./strlen/

SRC_PATH2	=	00_atoi_launcher.c			\
				01_atoi_basic_test.c		\
				02_atoi_basic_test.c		\
				03_atoi_hard_test.c			\
				04_atoi_hard_test.c

PATH_TEST2	=	./atoi/

SRC_PATH3	=	00_strdup_launcher.c		\
				01_strdup_basic_test.c		\
				02_strdup_null_test.c		\
				03_strdup_hard_test.c

PATH_TEST3	=	./strdup/

SRC_PATH4	=	00_strsplit_launcher.c			\
				01_strsplit_basic_test.c		\
				02_strsplit_basic_test.c		\
				03_strsplit_hard_test.c			\
				04_strsplit_null_test.c

PATH_TEST4	=	./strsplit/

SRC_PATH5	=	00_ft_bzero_launcher.c			\
				01_ft_bzero_all_test.c			\
				02_bzero_basic.c

PATH_TEST5	=	./ft_bzero/

SRC_PATH6	=	00_ft_isalnum_launcher.c		\
				01_ft_isalnum_all_test.c

PATH_TEST6	=	./ft_isalnum/

SRC_PATH7	=	00_ft_isalpha_launcher.c		\
				01_ft_isalpha_all_test.c

PATH_TEST7	=	./ft_isalpha/

SRC_PATH8	=	00_ft_isascii_launcher.c		\
				01_ft_isascii_all.c

PATH_TEST8	=	./ft_isascii/

SRC_PATH9	=	00_ft_isdigit_launcher.c		\
				01_ft_isdigit_all.c

PATH_TEST9	=	./ft_isdigit/

SRC_PATH10	=	00_ft_isprint_launcher.c		\
				01_ft_isprint_all.c

PATH_TEST10	=	./ft_isprint/

SRC_PATH11	=	00_ft_memalloc_launcher.c		\
				01_ft_memalloc_basic.c

PATH_TEST11	=	./ft_memalloc/

SRC_PATH12	=	00_ft_memccpy_launcher.c		\
				01_ft_memccpy_basic.c

PATH_TEST12	=	./ft_memccpy/

SRC_PATH13	=	00_itoa_launcher.c		\
				01_basic_test.c			\
				02_int_min_test.c		\
				03_zero_value_test.c		

PATH_TEST13	=	./itoa/

SRC			=	$(addprefix $(PATH_TEST1)/,$(SRC_PATH1))	\
				$(addprefix $(PATH_TEST2)/,$(SRC_PATH2))	\
				$(addprefix $(PATH_TEST3)/,$(SRC_PATH3))	\
				$(addprefix $(PATH_TEST4)/,$(SRC_PATH4))	\
				$(addprefix $(PATH_TEST5)/,$(SRC_PATH5))	\
				$(addprefix $(PATH_TEST6)/,$(SRC_PATH6))	\
				$(addprefix $(PATH_TEST7)/,$(SRC_PATH7))	\
				$(addprefix $(PATH_TEST8)/,$(SRC_PATH8))	\
				$(addprefix $(PATH_TEST9)/,$(SRC_PATH9))	\
				$(addprefix $(PATH_TEST10)/,$(SRC_PATH10))	\
				$(addprefix $(PATH_TEST11)/,$(SRC_PATH11))	\
				$(addprefix $(PATH_TEST12)/,$(SRC_PATH12))	\
				$(addprefix $(PATH_TEST13)/,$(SRC_PATH13))

SRC			+=	main.c

PATH_LIBFT	=	srcs/libft

PATH_LIBFT	=	$(addprefix $(FRAM_PATH)/,$(PATH_LIBFT))

PATH_FRAMEWORK	=	../framework/srcs/libunit

SRC_FRAMEWORK	=	lu_launch_tests.c

OBJ			=	$(SRC:.c=.o)

CPPFLAGS	=	-I../framework/includes -I./ -I./libft/includes

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

$(NAME) : $(OBJ)
		make -C ../framework
		make -C $(LIB_PATH)
		$(CC) $(CFLAGS) $(OBJ) $(CPPFLAGS) $(LIBA) $(LIB) -o $(NAME)

all : $(NAME)

test : all
	./$(NAME)

clean :
	make -C $(LIB_PATH) clean
	rm -f $(OBJ)

fclean : clean
	make -C $(LIB_PATH) fclean
	rm -f $(NAME)

re : fclean all

.PHONY : all re fclean clean
