# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/14 12:56:12 by jmatute-          #+#    #+#              #
#    Updated: 2022/04/05 14:22:01 by jmatute-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	so_long.c ./get_next_line/get_next_line_bonus.c errors.c fill_map.c \
			utils.c moves_on_map.c
LIBFT_DIR	= libft/

OBJS	= ${SRCS:.c=.o}

NAME	= so_long

CC		= gcc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror #-fsanitize=address

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

.c.o: ${SRCS}
			${CC} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS} Makefile
			@make -sC ${LIBFT_DIR}
			@cp ./libft/libft.a .
			${CC} ${CFLAGS} ${MLXFLAGS} libft.a ${OBJS} -o ${NAME}

all:		${NAME}

clean:
			@make -sC ${LIBFT_DIR} clean
			${RM} ${OBJS} libft.a

fclean:		clean
			@make -sC ${LIBFT_DIR} fclean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re