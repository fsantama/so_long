# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsantama <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/19 11:02:42 by fsantama          #+#    #+#              #
#    Updated: 2023/07/19 18:50:05 by fsantama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# =============================================================================#
#                        	GENERAL CONFIG & FLAGS                             #
# =============================================================================#

# PROGRAM FOR COMPILING C PROGRAMS
CC 		=	gcc
# C COMPILER FLAGS
CFLAGS =	-Werror -Wall -Wextra
MLX42FLAGS = -framework Cocoa -framework OpenGL -framework IOKit

NAME 	=	so_long
LIBFT 	=	./inc/Libft/libft.a
PRINTF 	=	./inc/ft_printf/libftprintf.a
MLX42	=	./inc/MLX42/libmlx42.a

# =============================================================================#
#                              MANDATORY PART                                  #
# =============================================================================#

SRCS	=	src/so_long.c \

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
	@make -C inc/MLX42> /dev/null

$(NAME) : $(LIBFT) $(PRINTF) $(MLX42) $(OBJS)
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
	@$(CC) $(CFLAGS) $(MLX42FLAGS) $(LIBFT) $(PRINTF) $(MLX42) $(OBJS) -o $(NAME)

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
