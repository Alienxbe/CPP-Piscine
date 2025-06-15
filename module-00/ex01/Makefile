# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marykman <marykman@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/08 17:19:07 by marykman          #+#    #+#              #
#    Updated: 2025/06/08 19:50:03 by marykman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -----------------------------------Colors------------------------------------

RED				:=	\033[38;5;9m
GREEN			:=	\033[38;5;10m
BLUE			:= 	\033[38;5;14m
YELLOW			:=	\033[38;5;226m
LIGHT_BLUE		:=	\033[38;5;14m
RESET			:=	\033[38;5;7m
PREFIX			=	[${LIGHT_BLUE}${NAME}${RESET}]\t

# ---------------------------------Compilation---------------------------------

CXX			:=	@c++
CXXFLAGS	:=	-Wall -Wextra -Werror -std=c++98

RM			:=	@rm -f

# --------------------------------Source files---------------------------------

NAME		:=	megaphone

SRCS		:=	megaphone.cpp

OBJS		:=	${SRCS:.cpp=.o}

# -----------------------------------Rules-------------------------------------

%.o:	%.cpp
	${CXX} ${CXXFLAGS} ${INCLUDES} -c $< -o $@

$(NAME):	${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o $@

all:	${NAME}

clean:
	${RM} ${OBJS}

fclean:
	${RM} ${OBJS} ${NAME}

re:		fclean all

# -----------------------------------.PHONY------------------------------------

.PHONY:	all clean fclean re
