# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/26 14:01:39 by jdagoy            #+#    #+#              #
#    Updated: 2023/05/18 02:05:19 by jdagoy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 					= libftprintf.a

CC 						= cc

CFLAGS 					= -Wall -Wextra -Werror

SOURCES_DIRECTORY		= ./
OBJECTS_DIRECTORY		= ./objects/

RM						= rm -rf
LIBC					= ar rcs

SRCS_LIST 				= ft_printf.c \
							ft_forconversion.c \
							ft_putadd.c \
							ft_putchar_base.c \
							ft_putchar.c \
							ft_putnbr_base.c \
							ft_putstr.c \
							ft_speccheck.c \
							ft_strlen.c


OBJECTS_LIST			:= $(patsubst %.c, %.o,$(SRCS_LIST))
OBJECTS					:= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

all: $(NAME)
$(OBJECTS_DIRECTORY):
	mkdir -p $(OBJECTS_DIRECTORY)

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c 
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS_DIRECTORY) $(OBJECTS)
		$(LIBC) $(NAME) $(OBJECTS)

clean:
		$(RM) $(OBJECTS_DIRECTORY)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
