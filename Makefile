# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mablatie <mablatie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/03 14:28:02 by vanitas           #+#    #+#              #
#    Updated: 2024/01/29 13:15:10 by mablatie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		=	cub3D

NAME_B		=	cub3D_bonus
 
CC			=	cc

FLAGS		=	-Wall -Wextra -Werror -g

LIBFT_PATH	=	./libft/

LIBFT_FILE	=	libft.a

MLX_FILE	=	libmlx_Linux.a

LIBFT_LIB	=	$(addprefix $(LIBFT_PATH), $(LIBFT_FILE))

MLX_FLAG	=	-lX11 -lXext

MLX_PATH	=	./mlx_linux/

MLX_LIB		=	$(addprefix $(MLX_PATH), $(MLX_FILE))

MLX_EX		=	$(MLX_LIB) $(MLX_FLAG)

SRC_DIR		=	./src/

SRC_DIR_B	=	./src_bonus/

H_FILES		=	./lib/cub3d.h ./lib/test.h

H_FILES_B	=	./lib/cub3d_bonus.h ./lib/test.h

C_FILE		=	main.c						\
				end.c						\
				end_norm.c					\
				init/init.c					\
				init/init_mlx.c				\
				init/init_textures.c		\
				init/init_2.c				\
				parsing/get_info.c			\
				parsing/get_info_norm.c		\
				parsing/malloc_protect.c	\
				parsing/parse_map.c			\
				parsing/island.c			\
				parsing/parse_info.c		\
				parsing/check_textures.c	\
				render/render.c				\
				render/texture.c			\
				render/raycasting.c			\
				render/image_utils.c		\
				movement/player_move.c		\
				movement/player_pos.c		\
				movement/player_rotate.c	\
				movement/player_dir.c		\
				movement/input_handler.c	\
				utils/utils.c				\
				utils/utils_2.c				\

C_FILE_B	=	main.c								\
				end.c								\
				end_norm.c							\
				character_stats/character_utils.c	\
				character_stats/character_utils_2.c	\
				init/init.c							\
				init/init_2.c						\
				init/init_mlx.c						\
				init/init_textures.c				\
				init/init_textures_2.c				\
				init/init_textures_3.c				\
				init/init_textures_4.c				\
				init/init_img.c						\
				init/init_img_2.c					\
				init/loading.c						\
				movement/player_move.c				\
				movement/player_pos.c				\
				movement/player_rotate.c			\
				movement/player_dir.c				\
				movement/enemies_pos.c				\
				movement/input_handler_bonus.c		\
				movement/input_handler_bonus2.c		\
				parsing/get_info.c					\
				parsing/get_info_2.c				\
				parsing/malloc_protect.c			\
				parsing/parse_map.c					\
				parsing/island.c					\
				parsing/parse_info.c				\
				parsing/check_textures.c			\
				render/texture.c					\
				render/texture_norm.c				\
				render/raycasting.c					\
				render/raycasting_norm.c			\
				render/render_bonus.c				\
				render/render_bonus_2.c				\
				render/render_bonus_3.c				\
				render/HUD.c						\
				render/HUD_2.c						\
				render/HUD_3.c						\
				render/HUD_4.c						\
				render/load_screen.c				\
				render/load_screen_2.c				\
				render/enemies.c					\
				render/enemies_2.c					\
				render/enemies_3.c					\
				render/enemies_4.c					\
				render/enemies_norm.c				\
				utils/utils.c						\
				utils/image_utils.c					\
				utils/image_utils_2.c				\
				utils/image_utils_3.c				\
				utils/utils_2.c						\
				utils/end_norm.c					\


SRC			=	$(addprefix $(SRC_DIR), $(C_FILE))

SRC_B		=	$(addprefix $(SRC_DIR_B), $(C_FILE_B))

OBJ_DIR		=	./Objects/

OBJ_DIR_B	=	./Objects_bonus/

OBJ			=	$(addprefix $(OBJ_DIR), $(C_FILE:.c=.o))

OBJ_B		=	$(addprefix $(OBJ_DIR_B), $(C_FILE_B:.c=.o))

DEP			=	$(OBJ:.o=.d)
# Colors
GREEN		=	\e[92;1;118m
YELLOW		=	\e[93;1;226m
GRAY		=	\e[33;2;37m	
RESET		=	\e[0m
CURSIVE		=	\e[33;3m


	
all: $(NAME)

$(NAME): $(MLX_LIB) $(LIBFT_LIB) $(OBJ) $(H_FILES) Makefile
	@$(CC) $(OBJ) $(LIBFT_LIB) $(MLX_EX) -lm -o $(NAME)
	@printf "$(GREEN)- Mandatory executable ready.\n$(RESET)"


$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(FLAGS) -c $< -o $@
	@$(CC) $(FLAGS) -MM $< -MF $(OBJ_DIR)$*.d -MT $(OBJ_DIR)$*.o

bonus : $(NAME_B)

$(NAME_B): $(MLX_LIB) $(LIBFT_LIB) $(OBJ_B) $(H_FILES_B) Makefile
	@$(CC) $(OBJ_B) $(LIBFT_LIB) $(MLX_EX) -lm -o $(NAME_B)
	@printf "$(GREEN)- Bonus executable ready.\n$(RESET)"

$(OBJ_DIR_B)%.o: $(SRC_DIR_B)%.c
	@mkdir -p $(@D)
	@$(CC) $(FLAGS) -c $< -o $@
	@$(CC) $(FLAGS) -MM $< -MF $(OBJ_DIR_B)$*.d -MT $(OBJ_DIR_B)$*.o

$(LIBFT_LIB):
	@make -C $(LIBFT_PATH)

$(MLX_LIB):
	@git clone https://github.com/42Paris/minilibx-linux.git mlx_linux
	@make -sC $(MLX_PATH)


push: fclean
	git add *
	git commit -m auto
	git push

clean:
	@make clean -sC $(LIBFT_PATH)
	@rm -rf $(OBJ_DIR)
	@rm -rf $(OBJ_DIR_B)
	@printf "$(YELLOW)- Object files removed.$(RESET)\n"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_B)
	@rm -rf $(MLX_PATH)
	@make fclean -C $(LIBFT_PATH)
	@printf "$(YELLOW)- Executable removed.$(RESET)\n"

re: fclean all

-include $(DEP)

.PHONY: all clean fclean re
