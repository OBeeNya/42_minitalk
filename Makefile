# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baubigna <baubigna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/17 13:42:48 by baubigna          #+#    #+#              #
#    Updated: 2022/01/18 17:11:12 by baubigna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CL			= client

NAME_SV			= server

GCC				= gcc

RM				= rm -rf

SRCS_CL			= client.c \
				ft_printf.c \
				ft_printf_utils.c \
				ft_atoi.c \
				convert_binary.c \
				ft_strlen.c \
				reverse_tab.c

SRCS_SV			= server.c \
				ft_printf.c \
				ft_printf_utils.c

${NAME_CL}:
	${GCC} ${GFLAGS} ${SRCS_CL} -o ${NAME_CL} ; ${GCC} ${GFLAGS} ${SRCS_SV} -o ${NAME_SV}
	
GFLAGS			= -Wall -Werror -Wextra

all:			$(NAME_CL)

clean:
	@printf "Nothing to clean.\n"

fclean:			clean
	${RM} ${NAME_CL}
	${RM} ${NAME_SV}

re:				fclean all

.PHONY:			all clean fclean re