# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kojwatan < kojwatan@student.42tokyo.jp>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 15:59:39 by kojwatan          #+#    #+#              #
#    Updated: 2023/12/13 13:11:22 by kojwatan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wextra -Wall -Werror -g  -fsanitize=address

SRCS = ./src/terminate.c ./src/display_map.c ./src/get_map.c ./src/get_player_info.c ./src/main.c ./src/map_validate.c ./src/control_player.c
OBJS = $(SRCS:.c=.o)
NAME = so_long

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	$(MAKE) -C ./minilibx
	$(CC) $(CFLAGS) $(OBJS) -L./libft -lft -L./minilibx -lmlx -framework OpenGL -framework AppKit -L/usr/X11/lib -lXext -lX11 -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C ./libft clean
	$(MAKE) -C ./minilibx clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C ./libft fclean
	$(MAKE) -C ./minilibx clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
