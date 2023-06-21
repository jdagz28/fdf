# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/13 02:06:33 by jdagoy            #+#    #+#              #
#    Updated: 2023/05/08 15:14:59 by jdagoy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 					= libft.a

CC 						= cc
CFLAGS 					= -Wall -Wextra -Werror
RM						= rm -rf
LIBC					= ar rcs

SOURCES_DIRECTORY 		= ./srcs/
OBJECTS_DIRECTORY		= ./objects/
INCLUDE_DIRECTORY		= ./includes/

INCLUDES				= -I $(INCLUDE_DIRECTORY)
HEADER					= $(INCLUDE_DIRECTORY)/libft.h

MANDATORY_DIR 			= $(SOURCES_DIRECTORY)mandatory/
SRCS_MANDATORY_LIST 	= ft_atoi.c \
							ft_bzero.c \
							ft_calloc.c \
							ft_isalnum.c \
							ft_isalpha.c \
							ft_isascii.c \
							ft_isdigit.c \
							ft_isprint.c \
							ft_itoa.c \
							ft_memchr.c \
							ft_memcmp.c \
							ft_memcpy.c \
							ft_memmove.c \
							ft_memset.c \
							ft_putchar_fd.c \
							ft_putendl_fd.c \
							ft_putnbr_fd.c \
							ft_putstr_fd.c \
							ft_split.c \
							ft_itoa.c \
							ft_strchr.c \
							ft_strdup.c \
							ft_striteri.c \
							ft_strjoin.c \
							ft_strlcat.c \
							ft_strlcpy.c \
							ft_strlen.c \
							ft_strmapi.c \
							ft_strncmp.c \
							ft_strnstr.c \
							ft_strrchr.c \
							ft_strtrim.c \
							ft_substr.c \
							ft_tolower.c \
							ft_toupper.c 
							

BONUS_DIR 				= $(SOURCES_DIRECTORY)bonus/
SRCS_BONUS_LIST 		= ft_lstadd_back_bonus.c \
							ft_lstadd_front_bonus.c \
							ft_lstclear_bonus.c \
							ft_lstdelone_bonus.c \
							ft_lstiter_bonus.c \
							ft_lstlast_bonus.c \
							ft_lstmap_bonus.c \
							ft_lstnew_bonus.c \
							ft_lstsize_bonus.c

ADDITIONAL_DIR			= $(SOURCES_DIRECTORY)additional/
SRCS_ADDITIONAL_LIST	= ft_isspace_pipex.c \
							ft_strjoin_pipex.c


OBJS_MANDATORY_LIST		= $(patsubst %.c, %.o, $(SRCS_MANDATORY_LIST))
MANDATORY_OBJS 			= (addprefix $(OBJECTS_DIRECTORY), $(OBJS_MANDATORY_LIST))

OBJS_BONUS_LIST			= $(patsubst %.c, %.o, $(SRCS_BONUS_LIST))
BONUS_OBJS 				= $(addprefix $(OBJECTS_DIRECTORY), $(OBJS_BONUS_LIST))

OBJS_ADDITIONAL_LIST	= $(patsubst %.c, %.o, $(SRCS_ADDITIONAL_LIST))
ADDITIONAL_OBJS 		= $(addprefix $(OBJECTS_DIRECTORy), $(OBJS_ADDITIONAL_LIST))

ALL_SRCS_LIST			= $(SRCS_MANDATORY_LIST) $(SRCS_BONUS_LIST) $(SRCS_ADDITIONAL_LIST)
OBJECTS_LIST			= $(patsubst %.c, %.o, $(ALL_SRCS_LIST))
OBJECTS					= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

all: $(NAME)
$(OBJECTS_DIRECTORY):
	mkdir -p $(OBJECTS_DIRECTORY)

$(OBJECTS_DIRECTORY)%.o : $(MANDATORY_DIR)%.c $(HEADER)
	$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@

$(OBJECTS_DIRECTORY)%.o : $(BONUS_DIR)%.c $(HEADER)
	$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@

$(OBJECTS_DIRECTORY)%.o : $(ADDITIONAL_DIR)%.c $(HEADER)
	$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@

$(NAME): $(OBJECTS_DIRECTORY) $(OBJECTS) $(HEADER)
	$(LIBC) $(NAME) $(OBJECTS)

clean:
		$(RM) $(OBJECTS_DIRECTORY)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

