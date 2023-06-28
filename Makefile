# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/31 14:44:56 by jdagoy            #+#    #+#              #
#    Updated: 2023/06/28 09:49:51 by jdagoy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					:= fdf

OS_NAME					:= $(shell uname -s)

ifeq ($(OS_NAME), Linux)
	FSANITIZE			:= -fsanitize=address -fsanitize=leak
	FRAMEWORK			:=
	LINUX_LIBS			:= -lXext -lX11 -L$(MLX_DIRECTORY)
	LINUX_INCLUDES		:= -I/usr/include
	OS_FLAG				:= -D LINUX
else
	FSANITIZE			:= -fsanitize=address
	FRAMEWORK			:= -framework OpenGL -framework AppKit
	LINUX_LIBS			:=
	LINUX_INCLUDES		:=
	OS_FLAG				:= -D OSX
endif

CC                      := gcc
CFLAGS                  := -Wall -Wextra -Werror -fno-omit-frame-pointer  $(FSANITIZE) $(OS_FLAG)
RM                      := rm -rf

LIB_DIRECTORY           := ./libs/
LIBFT_DIRECTORY         := $(LIB_DIRECTORY)libft/
LIBFT_HEADER            := $(LIBFT_DIRECTORY)includes/
LIBFT                   := $(LIBFT_DIRECTORY)libft.a

PRINTF_DIRECTORY        := $(LIB_DIRECTORY)ft_printf/
PRINTF_HEADER           := $(PRINTF_DIRECTORY)
PRINTF                  := $(PRINTF_DIRECTORY)libftprintf.a

GNL_DIRECTORY           := $(LIB_DIRECTORY)get_next_line/
GNL_HEADER              := $(GNL_DIRECTORY)
GNL                     := $(GNL_DIRECTORY)libgnl.a

ifeq ($(OS_NAME), Linux)
	MLX_DIRECTORY		:= $(LIB_DIRECTORY)minilibx-linux
	MLX_NAME			:= libmlx.a
else
	MLX_DIRECTORY		:= $(LIB_DIRECTORY)minilibx_mms_20191025_beta\ 2
  	MLX_NAME			:= libmlx.dylib
endif

MLX						:= $(MLX_DIRECTORY)/$(MLX_NAME)
MLX_HEADER				:= $(MLX_DIRECTORY)


SOURCES_DIRECTORY       := ./srcs/
SOURCES_DIRECTORY_BONUS	:= ./srcs_bonus/
OBJECTS_DIRECTORY       := ./objects/
INCLUDE_DIRECTORY       := ./includes/


LIBRARIES               := -lmlx -lm -L. -L$(LIBFT_DIRECTORY) -lft -L$(PRINTF_DIRECTORY) -lftprintf \
							 -L$(GNL_DIRECTORY) -lgnl $(FRAMEWORK) $(LINUX_LIBS)
INCLUDES                := -I$(LIBFT_HEADER) -I$(PRINTF_HEADER) -I$(GNL_HEADER) \
							-I$(INCLUDE_DIRECTORY) -I$(MLX_HEADER) $(LINUX_INCLUDES)
BONUS_INCLUDES          :=

HEADER                  := fdf.h
HEADER_BONUS			:= fdf_bonus.h
HEADER_FILES            := $(addprefix $(INCLUDE_DIRECTORY), $(HEADER))
HEADER_FILES_BONUS		:= $(addprefix $(INCLUDE_DIRECTORY), $(HEADEHEADER_BONUS))

SRCS_LIST               := main.c\
							arg_handler.c\
							draw_line.c\
							draw_map_utils.c\
							draw_map.c\
							draw.c\
							init_map.c\
							init.c\
							keybinds.c\
							map_color.c\
							map_parser_utils.c\
							map_parser.c\
							matrix.c\
							projections.c\
							rotation_matrices.c\
							transformation_matrices.c\
							utils.c

OBJECTS_LIST            := $(patsubst %.c, %.o, $(SRCS_LIST))
OBJECTS                 := $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

SRCS_BONUS_LIST			:= main_bonus.c\
							arg_handler_bonus.c\
							draw_bonus.c\
							draw_dotpoint_bonus.c\
							draw_line_bonus.c\
							draw_map_bonus.c\
							draw_map_utils_bonus.c\
							draw_menu_2_bonus.c\
							draw_menu_bonus.c\
							draw_menubox_bonus.c\
							init_bonus.c\
							init_map_bonus.c\
							keybinds_bonus.c\
							keybinds_2_bonus.c\
							map_color_bonus.c\
							map_parser_bonus.c\
							map_parser_utils_bonus.c\
							matrix_bonus.c\
							projections_bonus.c\
							rotation_matrices_bonus.c\
							transformation_matrices_bonus.c\
							utils_bonus.c
							

OBJECTS_LIST_BONUS		:= $(patsubst %.c, %.o, $(SRCS_BONUS_LIST))
OBJECTS_BONUS			:= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST_BONUS))

all: $(NAME)

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)
	@echo "Creating $(NAME) objects directory"

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADER_FILES)
	@echo "$(NAME): Compiling $<"
	@$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@

$(LIBFT):
	@echo "$(NAME): Compiling $(LIBFT)"
	@$(MAKE) -sC $(LIBFT_DIRECTORY)

$(PRINTF):
	@echo "$(NAME): Compiling $(PRINTF)"
	@$(MAKE) -sC $(PRINTF_DIRECTORY)

$(GNL):
	@echo "$(NAME): Compiling $(GNL)"
	@$(MAKE) -sC $(GNL_DIRECTORY)

$(MLX):
	@echo "$(NAME): Compiling $(MLX)"
	@$(MAKE) -sC $(MLX_DIRECTORY)

$(NAME): $(LIBFT) $(PRINTF) $(GNL) $(MLX) $(OBJECTS_DIRECTORY) $(OBJECTS) $(HEADER_FILES)
	@$(CC) $(CFLAGS) $(OBJECTS) $(INCLUDES) $(LIBRARIES) -o $(NAME)


bonus: $(NAME)_bonus
$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY_BONUS)%.c $(HEADER_FILES_BONUS)
	@echo "$(NAME)_bonus: Compiling $<"
	@$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@

$(NAME)_bonus: $(LIBFT) $(PRINTF) $(GNL) $(MLX) $(OBJECTS_DIRECTORY) $(OBJECTS_BONUS) $(HEADER_FILES_BONUS)
	@$(CC) $(CFLAGS) $(OBJECTS_BONUS) $(INCLUDES) $(LIBRARIES) -o $(NAME)


clean:
	$(MAKE) -sC $(LIBFT_DIRECTORY) clean
	$(MAKE) -sC $(PRINTF_DIRECTORY) clean
	$(MAKE) -sC $(GNL_DIRECTORY) clean
	$(MAKE) -sC $(MLX_DIRECTORY) clean
	$(RM) $(OBJECTS_DIRECTORY)

fclean: clean
	$(MAKE) -sC $(LIBFT_DIRECTORY) fclean
	$(MAKE) -sC $(PRINTF_DIRECTORY) fclean
	$(MAKE) -sC $(GNL_DIRECTORY) fclean
	$(RM) $(MLX)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re norm
