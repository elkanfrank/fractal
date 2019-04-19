# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: efrank <efrank@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2019/02/18 12:15:56 by efrank         #+#    #+#                 #
#    Updated: 2019/04/19 17:03:21 by efrank        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SRC = src/*.c
INCLUDES = minilibx_macos
FLAGS = -Wall -Wextra -Werror
LIB = minilibx_macos
OBJECT = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@echo "compiling..."
	@make -C libft/
	@gcc -o $(NAME) $(SRC) libft/libft.a -I $(INCLUDES) -lmlx -L $(LIB) \
		-framework OpenGL -framework AppKit
	@echo "done!"

clean:
	@make clean -C libft/
	@echo "cleaning files"
	@rm -f $(OBJECT)

fclean: clean
	@make fclean -C libft/
	@echo "cleaning bins"
	@rm -f $(NAME)

re: fclean all clean
