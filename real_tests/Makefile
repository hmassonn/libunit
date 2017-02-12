# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/20 20:07:34 by jtoty             #+#    #+#              #
#    Updated: 2017/02/12 18:24:44 by jtoty            ###   ########.fr        #
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

#SRC_PATH5	=	00_putchar_launcher.c			\
				01_putchar_basic_test.c

PATH_TEST5	=	./putchar/

SRC			=	$(addprefix $(PATH_TEST1)/,$(SRC_PATH1))	\
				$(addprefix $(PATH_TEST2)/,$(SRC_PATH2))	\
				$(addprefix $(PATH_TEST3)/,$(SRC_PATH3))	\
				$(addprefix $(PATH_TEST4)/,$(SRC_PATH4))	\
#				$(addprefix $(PATH_TEST5)/,$(SRC_PATH5))

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
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all re fclean clean
