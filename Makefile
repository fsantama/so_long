# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsantama <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/19 11:02:42 by fsantama          #+#    #+#              #
#    Updated: 2023/08/04 16:50:50 by fsantama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# =============================================================================#
#                        	GENERAL CONFIG & FLAGS                             #
# =============================================================================#

# PROGRAM FOR COMPILING C PROGRAMS
CC 		=	gcc
# C COMPILER FLAGS
CFLAGS =	-Werror -Wall -Wextra -g
# MLX42FLAGS = -framework Cocoa -framework OpenGL -framework IOKit

NAME 	=	so_long
LIBFT 	=	./inc/Libft/libft.a
PRINTF 	=	./inc/ft_printf/libftprintf.a
MLX42	=	./inc/MLX42/libmlx42.a -ldl -pthread -lm -Iinclude -lglfw \
			-L "/Users/$$USER/.brew/opt/glfw/lib/"
# GLFW	=	-lglfw -L "/Users/$$USER/.brew/opt/glfw/lib/"

# =============================================================================#
#                              MANDATORY PART                                  #
# =============================================================================#

SRCS	=	inc/get_next_line/get_next_line.c \
			inc/get_next_line/get_next_line_utils.c \
			src/so_long.c \
			src/ft_check_map.c \
			src/ft_error.c \
			src/ft_read_map.c \
			src/ft_check_solution.c \
			src/ft_load_player_textures.c \
			src/ft_load_walls_textures.c \
			src/ft_draw_player.c \
			src/ft_draw_walls.c \
			src/ft_end_game.c \
			src/ft_play.c \

OBJS	=	$(SRCS:.c=.o)

# =============================================================================#
#                                  RULES                                       #  
# =============================================================================#


all : $(NAME) $(LIBFT) $(PRINTF) $(MLX42)

$(LIBFT) : 
	@make  -C inc/Libft > /dev/null

$(PRINTF) : 
	@make  -C inc/ft_printf > /dev/null

$(MLX42) :
	@make  -C  inc/MLX42> /dev/null

$(NAME) : $(LIBFT) $(PRINTF) $(MLX42) $(GLFW) $(OBJS)
	@echo "$(CYAN) ======================================================="
	@echo "|	               _                   		|"
	@echo "|	  ___  ___    | | ___  _ __   __ _ 		|"
	@echo "|	 / __|/ _ \   | |/ _ \|  _ \ / _  | 		|"
	@echo "|	 \__ \ (_) |  | | (_) | | | | (_| | 		|"
	@echo "|	 |___/\___/___|_|\___/|_| |_|\__, |		|"
	@echo "|			 |_____|     |___/		|"
	@echo " ======================================================="
	@echo " ================ Develop by fsantama =================="
	@echo " ======================================================="
	@echo "																	"
	@echo "      (((/               /(((((,              .((((				"
	@echo "     ((,,,*((((((((((((((,,*,,,*(((((((((((((/   *(/				"
	@echo "     ((,,,,,,,,,,,,,,,,,,,,,,,,,,,,,(((..       .(((				"
	@echo "    ((/,,,,,,,,,,,,(##(####/,,,,*(((   *%, # ,(((%((				"
	@echo "    #(/,,,,,,,,,,*%##########(((/  #  ,*, *((#  %#((				"
	@echo "    /((,,,,/(#(###%##%%#,,,*,,,#,   // /((,,%%  %#((				"
	@echo "     (((###(##((#####%,,,/,*##,*#*  (((#%% ,%%  %(((				"
	@echo "     (((%##%%%%%%%#(((,,(/,((*#*,,((#. #%% ,%%  %((,				"
	@echo "      ((#%%%####(((* .,,,%/*,*/*,* %%. #%% ,%%  (((				"
	@echo "      ,((#%%%(((, *%, %((,,,/,,/#  %%. #%% ,%% (((				"
	@echo "       *(((((   ## (   *(((%( ,%%  %%. #%% ,%%(((				"
	@echo "        .((*  /*((  /(((%%%%( ,%%  %%. #%% ,%(((					"
	@echo "          (((    (((#%%%%%%%( ,%%  %%. #%% ,(((					"
	@echo "           ((((((#%%%%%%%%%%( ,%%  %%. #%%/((,					"
	@echo "             (((#%%%%%%%%%%%( ,%%  %%. ##(((						"
	@echo "              .(((%%%%%%%%%%( ,%%  %%. (((						"
	@echo "                ,(((%%%%%%%%( ,%%  %#(((							"
	@echo "                  .(((%%%%%%( ,%% .(((							"
	@echo "                     (((#%%%( ,%((((								"
	@echo "                       *(((%( (((.								"
	@echo "                          ((((*									"
	@echo "	                                                      			"
	@echo " =======================================================			"
	@echo "                                                       $(DEFAULT)"
	@echo "$(GREEN) $(NAME) make done ✅ $(DEFAULT)"
	@echo "$(GREEN) $(LIBFT) make done ✅ $(DEFAULT)"
	@echo "$(GREEN) $(PRINTF) make done ✅ $(DEFAULT)"
	@echo "$(GREEN) $(MLX42) make done ✅ $(DEFAULT)"
	@$(CC) $(CFLAGS) $(LIBFT) $(PRINTF) $(MLX42) $(OBJS) -o $(NAME)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -f $(OBJS)
	@make -C inc/Libft clean > /dev/null
	@make -C inc/ft_printf clean > /dev/null
	@make -C inc/MLX42/ clean > /dev/null
	@echo "$(RED) $(NAME) objects clean done 🧹 $(DEFAULT)"
	@echo "$(RED) $(LIBFT) objects clean done 🧹 $(DEFAULT)"
	@echo "$(RED) $(PRINTF) objects clean done 🧹 $(DEFAULT)"
	@echo "$(RED) $(MLX42) objects clean done 🧹 $(DEFAULT)"

fclean : clean
	@rm -f $(NAME)
	@make -C inc/Libft fclean > /dev/null
	@make -C inc/ft_printf fclean > /dev/null
	@make -C inc/MLX42/ fclean > /dev/null
	@echo "$(RED) $(NAME) clean done 🧹 $(DEFAULT)"
	@echo "$(RED) $(LIBFT) clean done 🧹 $(DEFAULT)"
	@echo "$(RED) $(PRINTF) clean done 🧹 $(DEFAULT)"
	@echo "$(RED) $(MLX42) fclean > /dev/null 🧹 $(DEFAULT)"
re: fclean all

#bonus : $(NAME_BONUS)

# =============================================================================#
#                                 COLORS                                       #
# =============================================================================#

BOLD	:=	\033[1m
BLACK	:=	\033[30;1m
RED		:=	\033[31;1m
GREEN	:=	\033[32;1m
YELLOW	:=	\033[33;1m
BLUE	:=	\033[34;1m
MAGENTA	:=	\033[35;1m
CYAN	:=	\033[36;1m
WHITE	:=	\033[37;1m
DEFAULT	:=	\033[0m

.PHONY: all clean fclean re
