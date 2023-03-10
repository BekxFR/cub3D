# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chillion <chillion@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/01 12:07:22 by chillion          #+#    #+#              #
#    Updated: 2023/02/02 15:47:37 by chillion         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all test norm clean fclean re

NAME := cub3d.a
SOFT_NAME := cub3D
NAME_BONUS := cub3d_bonus.a
SOFT_BONUS := cub3D_bonus

CC := gcc
FLAGS := -g3 -Wall -Wextra -Werror -I includes/ -I.. -MMD -MP
SRC_DIR := sources/
OBJ_DIR := objects/
AR := ar rc
RM := rm
VAL := valgrind --leak-check=full --track-origins=yes
MLXFLAGS := -L libs/minilibx-linux/ -lmlx -lXext -lX11 -lz -lm

BLACK = \033[1;30m
REDBG = \033[30;41m
RED = \033[0;31m
GREEN = \033[0;32m
ORANGE = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
NC = \033[0m

SRCS =	color.c	cub3d.c	cub3d_utils.c	ft_check_arg2.c	ft_check_arg.c	ft_check_display_map.c	\
		ft_clean.c	ft_control.c	ft_display_3d.c	ft_draw_line_map.c	ft_error.c	ft_init2.c	\
		ft_init.c	ft_init_map_value.c	ft_init_sprites.c	ft_raycast2.c	ft_raycast.c	map_attack2.c	\
		map_attack.c	map_checker2.c	map_checker.c	map_init.c	moove2.c	moove.c	\

BONUS =	color.c	cub3d_bonus.c	cub3d_utils.c	ft_check_arg2.c	ft_check_arg.c	ft_check_display_map.c	\
		ft_clean.c	ft_control.c	ft_display_3d.c	ft_draw_line_map_bonus.c	ft_error.c	ft_init2.c	\
		ft_init_bonus.c	ft_init_map_value.c	ft_init_sprites.c	ft_raycast2.c	ft_raycast_bonus.c	map_attack2.c	\
		map_attack.c	map_checker2.c	map_checker.c	map_init.c	moove2_bonus.c	moove_bonus.c	\

LIBFT := libs/libft/libft.a
MLX := libs/minilibx-linux/libmlx_Linux.a
FCLIB := ${MAKE} fclean -C libs/libft
CMLX := ${MAKE} clean -C libs/minilibx-linux

OBJS = $(SRCS:%.c=%.o)
BOBJS = $(BONUS:%.c=%.o)
NORM = $(wildcard *.c) $(wildcard *.h)

OBJ = $(addprefix $(OBJ_DIR),$(OBJS))
DEPS = $(OBJ:%.o=%.d)
BOBJ = $(addprefix $(OBJ_DIR),$(BOBJS))
DEPSB = $(BOBJ:%.o=%.d)

OBJF := ${OBJ_DIR}.cache_exists

all : ${SOFT_NAME}

$(OBJF) :
	@mkdir -p ${OBJ_DIR}
	@touch ${OBJF}

${LIBFT} :
	${MAKE} all -C libs/libft
	${MAKE} all -C libs/minilibx-linux
	@cp ${LIBFT} ${NAME}

${NAME} : ${OBJ}
	@echo "${BLUE}###${NC}Update de l'archive ${NAME}${BLUE}###${MAGENTA}"
	${AR} ${NAME} ${MLX} ${OBJ}
	@echo "${NC}"

${OBJ_DIR}%.o : %.c ${LIBFT} $(OBJF) Makefile
	@echo "${BLUE}###${NC}Creation du fichier ${@:%.c=%.o}${BLUE}###${ORANGE}"
	${CC} ${FLAGS} ${MLXFLAGS} -c $< -o $@
	@echo "${NC}"

${SOFT_NAME} : ${NAME}
	@echo "${BLUE}###${NC}Creation du fichier ${SOFT_NAME}${BLUE}###${ORANGE}"
	${CC} ${NAME} ${FLAGS} ${MLXFLAGS} -o ${SOFT_NAME}
	@echo "${NC}"

bonus : ${SOFT_BONUS}

${SOFT_BONUS} : ${BOBJ}
	@echo "${BLUE}###${NC}Creation du fichier ${SOFT_BONUS}${BLUE}###${ORANGE}"
	${CC} ${BOBJ} ${LIBFT} ${FLAGS} ${MLXFLAGS} -o ${SOFT_BONUS}
	@echo "${NC}"

clean : 
	${FCLIB}
	${CMLX}
	@echo "${RED}###${NC}Nettoyage des fichiers .o${RED}###"
	${RM} -rf ${OBJ_DIR} ${OBJF}
	@echo "${GREEN}###${NC}Nettoyage OK${GREEN}###${NC}\n"

fclean : clean
	@echo "${RED}###${NC}Nettoyage d'archives et de Softs${RED}###"
	${RM} -f ${NAME} ${NAME_BONUS} ${SOFT_NAME} ${SOFT_BONUS}
	@echo "${GREEN}###${NC}Nettoyage OK${GREEN}###${NC}\n"

re : fclean all

norm :
	${MAKE} norm -C libs/libft
	@norminette $(NORM) | grep -v OK! || true

-include ${DEPS} ${DEPSB}
