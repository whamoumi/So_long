# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: whamoumi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/15 17:43:46 by whamoumi          #+#    #+#              #
#    Updated: 2021/06/16 17:13:04 by whamoumi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		=	so_long
SRCS		=	draw_square.c get_next_line.c get_next_line_utils.c mouvement.c \
				parsing_map.c so_long.c so_long_utils.c so_long_utils2.c \
				so_long_utils3.c

OBJS		=	${SRCS:.c=.o}

CC			=	gcc

MLXFLAGS	=	-lmlx -framework OpenGL -framework AppKit
CFLAGS		=	-Werror -Wextra -Wall 

RM			=	rm -f

all:			${NAME}

$(NAME):		${OBJS}
				${CC} -o ${NAME} ${OBJS} ${CFLAGS} ${MLXFLAGS} 
clean:
				${RM} ${OBJS}

fclean:			clean
				${RM} ${NAME}

re:				fclean all

