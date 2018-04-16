# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/28 16:56:20 by awajsbro          #+#    #+#              #
#    Updated: 2018/04/15 15:03:30 by awajsbro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMEPS		= push_swap

NAMECHECK	= checker

SRCCOM		=	src/ft_get_arg.c \
				src/setting.c \
				src/ft_init.c \
				src/ft_rule.c \
				src/ft_error.c \
				src/ft_del.c \
				\
				src/debug.c \

SRCPS		=	src/main_push_swap.c \
				src/ft_solve.c \

SRCCHECK	=	src/main_checker.c \
				src/ft_command.c \

SRC			=	$(SRCCOM) $(SRCPS) $(SRCCHECK)

OBJCOM		=	$(notdir $(SRCCOM:.c=.o))

OBJPS		=	$(notdir $(SRCPS:.c=.o))

OBJCHECK	=	$(notdir $(SRCCHECK:.c=.o))

OBJ			=	$(OBJPS) $(OBJCHECK) $(OBJCOM)

OBJDIR		=	obj/

LIB_DIR 	=	./libft/

LIBFT 		=	./libft/libft.a

all :
	@$(MAKE) -C $(LIB_DIR)
	@mkdir -p $(OBJDIR)
	@gcc -Wextra -Wall -Werror -c $(SRC)
	@mv $(OBJ) $(OBJDIR)
	@gcc -Wall -Werror -Wextra $(addprefix $(OBJDIR), $(OBJPS) $(OBJCOM)) $(LIBFT) -o $(NAMEPS)
	@gcc -Wall -Werror -Wextra $(addprefix $(OBJDIR), $(OBJCHECK) $(OBJCOM)) $(LIBFT) -o $(NAMECHECK)
	@echo "\033[36m	PUSH_SWAP\033[33m ====\033[1m> \033[32;1mREADY TO USE\033[0m"
	@echo "\033[36m	CHECKER\033[33m   ====\033[1m> \033[32;1mREADY TO USE\033[0m"

$(NAMEPS) :
	@$(MAKE) -C $(LIB_DIR)
	@mkdir -p $(OBJDIR)
	@gcc -Wextra -Wall -Werror -c $(SRCCOM) $(SRCPS)
	@mv $(OBJCOM) $(OBJPS) $(OBJDIR)
	@gcc -Wall -Werror -Wextra $(addprefix $(OBJDIR), $(OBJPS) $(OBJCOM)) $(LIBFT) -o $(NAMEPS)
	@echo "\033[36m	PUSH_SWAP\033[33m ====\033[1m> \033[32;1mREADY TO USE\033[0m"

$(NAMECHECK) :
	@$(MAKE) -C $(LIB_DIR)
	@mkdir -p $(OBJDIR)
	@gcc -Wextra -Wall -Werror -c $(SRCCHECK) $(SRCCOM)
	@mv $(OBJCOM) $(OBJCHECK) $(OBJDIR)
	@gcc -Wall -Werror -Wextra $(addprefix $(OBJDIR), $(OBJCHECK) $(OBJCOM)) $(LIBFT) -o $(NAMECHECK)
	@echo "\033[36m	CHECKER\033[33m  ====\033[1m> \033[32;1mREADY TO USE\033[0m"

clean :
	@$(MAKE) clean -C $(LIB_DIR)
	@rm -f $(addprefix $(OBJDIR), $(OBJ))
	@echo "\033[31;1m	CLEANING DONE\033[0m"

fclean : clean
	@$(MAKE) fclean -C $(LIB_DIR)
	@echo "\033[36m	CHECKER\033[33m   ====\033[1m> \033[31;1mDELETED\033[0m"
	@echo "\033[36m	PUSH_SWAP\033[33m ====\033[1m> \033[31;1mDELETED\033[0m"

re : fclean all
