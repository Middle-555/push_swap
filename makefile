# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/09 14:56:40 by kpourcel          #+#    #+#              #
#    Updated: 2024/04/15 19:14:20 by kpourcel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the program
NAME    =    push_swap

# Flags
CC		=	cc
CFLAGS		=	-Wall -Werror -Wextra -g

# Directories
VPATH		=	src  src/error_handling src/move src/utils
SRC_DIR		=	src/
OBJ_DIR		=	obj/
LIB_DIR		=	libraries/

# .c and .o files
ERROR		= 	error_utils.c error.c free.c
UTILS		= 	utils.c test.c
MOVE		=	movement.c
SRC		=	main.c $(ERROR) $(UTILS) $(MOVE)
OBJ		=	$(SRC:%.c=$(OBJ_DIR)%.o)

# .a files
LIBFT		=	$(LIB_DIR)libraries.a

# The main rule
all                :	$(NAME)

# The name rule
$(NAME)            :    $(OBJ) $(LIBFT)
	@echo "\033[0;33mCompiling the whole project -> ⏳\033[0m"
	@$(CC) $(OBJ) $(LIBFT) -o $@ -I include/
	@echo "\033[0;32mProject successfuly compiled -> ✅\033[0m\n"

# The libft rule
$(LIBFT)        :    $(LIB_DIR)
	@echo "\033[0;33mCompiling my libft -> ⏳\033[0m"
	@make all -sC $<
	@echo "\033[0;32mLibft successfuly compiled -> ✅\033[0m\n"

# Create the obj directory
$(OBJ_DIR)        :
	@mkdir -p $@

# Compile .c to .o files
$(OBJ_DIR)%.o    :    %.c | $(OBJ_DIR)
	@echo "\033[0;33mCompiling project src -> ⏳\033[0m"
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)
	@echo "\033[0;32mSrc's project successfuly compiled -> ✅\033[0m\n"


# Clean, fclean and re rules
clean            :
	@echo "\033[0;31mCleaning obj files -> 🗑️\033[0m"
	@if [ -d "$(OBJ_DIR)" ]; then rm -rf $(OBJ_DIR); fi
	@make clean -sC $(LIB_DIR)
	@echo "\033[0;32mDone -> ✅\033[0m\n"

fclean            :    clean
	@echo "\033[0;31mCleaning program -> 🗑️\033[0m"
	@rm -rf $(NAME)
	@make fclean -sC $(LIB_DIR)
	@echo "\033[0;32mDone -> ✅\033[0m\n"

re                :    fclean all