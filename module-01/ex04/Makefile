# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marykman <marykman@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/08 17:19:07 by marykman          #+#    #+#              #
#    Updated: 2025/11/04 05:17:22 by marykman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -----------------------------------Colors------------------------------------

RED				:=	\033[38;5;9m
GREEN			:=	\033[38;5;10m
BLUE			:= 	\033[38;5;14m
YELLOW			:=	\033[38;5;226m
LIGHT_BLUE		:=	\033[38;5;14m
RESET			:=	\033[38;5;7m
PREFIX			=	[${LIGHT_BLUE}${NAME}${RESET}]	

# ---------------------------------Compilation---------------------------------

CXX			:=	@c++
CXXFLAGS	:=	-Wall -Wextra -Werror -std=c++98

RM			:=	@rm -f

# --------------------------------Source files---------------------------------

NAME		:=	phonebook

INCLUDES	:=	-I./includes

FILES		:=	main.cpp \
				PhoneBook.cpp \
				Contact.cpp \
				utils.cpp

SRCS		:=	$(addprefix srcs/, ${FILES})
OBJS		:=	$(patsubst srcs%.cpp, objs%.o, ${SRCS})

# -----------------------------------Rules-------------------------------------

objs/%.o:	srcs/%.cpp
	${CXX} ${CXXFLAGS} ${INCLUDES} -c $< -o $@
	@echo "${PREFIX}Compilation of $<..."

$(NAME):	${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o $@
	@echo "${PREFIX}${NAME} compiled!"

all:	${NAME}

clean:
	${RM} ${OBJS}
	@echo "${PREFIX}Cleaning objects files..."

fclean:
	${RM} ${OBJS} ${NAME}
	@echo "${PREFIX}Cleaning files..."

re:		fclean all

# -----------------------------------.PHONY------------------------------------

.PHONY:	all clean fclean re
