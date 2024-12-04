# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/18 01:59:48 by jdagoy            #+#    #+#              #
#    Updated: 2023/05/18 02:37:08 by jdagoy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 					= libgnl.a

CC 						= cc

CFLAGS 					= -Wall -Wextra -Werror

SOURCES_DIRECTORY		= ./
OBJECTS_DIRECTORY		= ./objects/

RM						= rm -rf
LIBC					= ar rcs

SRCS_LIST 				= get_next_line.c \
							get_next_line_utils.c

OBJECTS_LIST			:= $(patsubst %.c, %.o,$(SRCS_LIST))
OBJECTS					:= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

BONUS_SRCS_LIST 		= get_next_line_bonus.c \
							get_next_line_utils_bonus.c

BONUS_OBJECTS_LIST		:= $(patsubst %.c, %.o,$(BONUS_SRCS_LIST))
BONUS_OBJECTS					:= $(addprefix $(OBJECTS_DIRECTORY), $(BONUS_OBJECTS_LIST))



all: $(NAME)
$(OBJECTS_DIRECTORY):
	mkdir -p $(OBJECTS_DIRECTORY)

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c 
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS_DIRECTORY) $(OBJECTS)
		$(LIBC) $(NAME) $(OBJECTS)

bonus: $(NAME)_bonus
$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c 
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME)_bonus: $(OBJECTS_DIRECTORY) $(BONUS_OBJECTS)
		$(LIBC) $(NAME)_bonus $(BONUS_OBJECTS)

clean:
		$(RM) $(OBJECTS_DIRECTORY)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
