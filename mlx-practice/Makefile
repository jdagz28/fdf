
NAME 					= practice

CC 						= cc

CFLAGS 					= -Wall -Wextra -Werror -g

SOURCES_DIRECTORY		= ./
OBJECTS_DIRECTORY		= ./objects/

RM						= rm -rf

SRCS_LIST 				= main.c


OBJECTS_LIST			:= $(patsubst %.c, %.o,$(SRCS_LIST))
OBJECTS					:= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

all: $(NAME)
$(OBJECTS_DIRECTORY):
	mkdir -p $(OBJECTS_DIRECTORY)

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c 
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJECTS_DIRECTORY) $(OBJECTS)
		$(CC) $(OBJECTS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
		

# linux: $(NAME)_linux
# $(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c 
# 	$(CC) $(CFLAGS) -I/usr/include -Imlx-linux -O3 -c $< -o $@

# $(NAME)_linux: $(OBJECTS_DIRECTORY) $(OBJECTS)
# 		$(CC) $(OBJECTS) -Lmlx-linux -lmlx_Linux -L/usr/lib -Imlx-linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
		$(RM) $(OBJECTS_DIRECTORY)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re linux
