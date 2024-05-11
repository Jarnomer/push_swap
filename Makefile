# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmertane <jmertane@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/30 15:32:20 by jmertane          #+#    #+#              #
#    Updated: 2024/01/29 15:34:36 by jmertane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	push_swap
BONUSBIN	=	checker
DEBUGBIN 	= 	debug.out
LIBFTDIR 	= 	libft
LIBFTBIN 	= 	libft.a
ERRORTXT 	= 	error.txt
BONUS		=	.bonus
DEBUG		=	.debug

RM 			= 	rm -rf
AR			=	ar -rcs
CC 			= 	cc
CFLAGS 		= 	-Wall -Werror -Wextra

SRCS 		:=	push_swap.c \
				chk_error.c \
				chk_split.c \
				cmd_push.c \
				cmd_swap.c \
				cmd_rotate.c \
				cmd_reverse.c \
				sort_prep_a.c \
				sort_prep_b.c \
				sort_push.c \
				stack_init.c \
				stack_sort.c \
				stack_util.c

SRCS_BNS 	:=	$(BONUSBIN).c \
				$(filter-out $(NAME).c, $(SRCS))

SRCS_DEBUG 	:=	$(SRCS_BNS)

OBJSDIR 	= 	build
DEPSDIR 	= 	.deps
DEPS 		= 	$(SRCS:%.c=$(DEPSDIR)/%.d)
OBJS 		= 	$(SRCS:%.c=$(OBJSDIR)/%.o)
OBJS_BNS 	= 	$(SRCS_BNS:%.c=$(OBJSDIR)/%.o)
OBJS_DEBUG 	= 	$(SRCS_DEBUG:%.c=$(OBJSDIR)/%.o)
DEPFLAGS 	=	-c -MT $@ -MMD -MP -MF $(DEPSDIR)/$*.d
DEBUGFLAGS 	=	-g -fsanitize=address,undefined,integer \
				-fdiagnostics-color=always -fansi-escape-codes

FILL		=	======================================
BOLD		=	\033[1m
RESET		=	\033[0m
GREEN		=	\033[32m
VIOLET		=	\033[35m
CYAN		=	\033[36m
RED			=	\033[31m
YELLOW		=	\033[33m

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFTDIR) all
	@$(CC) $(CFLAGS) $^ $(LIBFTDIR)/$(LIBFTBIN) -o $@
	@echo "$(GREEN)$(BOLD)\n$(FILL)$(CYAN)\nFINISHED!$(RESET)\n"
	@echo "$(VIOLET)Compiled $(GREEN)$(SUCCESS)$(VIOLET) object file(s).$(RESET)\n"
	@echo "$(VIOLET)Using compiler $(GREEN)$(CC)$(VIOLET) with flags: $(GREEN)$(CFLAGS)$(RESET)\n"
	@echo "$(VIOLET)Successfully compiled binary: $(GREEN)$(BOLD)$(NAME)$(RESET)\n"

$(OBJSDIR)/%.o: %.c | $(OBJSDIR) $(DEPSDIR)
	@if ! $(CC) $(CFLAGS) $(DEPFLAGS) $< -o $@ 2> $(ERRORTXT); then \
		echo "$(RED)$(BOLD)\nMAKEFILE TERMINATED!\n$(FILL)$(RESET)\n"; \
		echo "$(VIOLET)Unable to create object file: $(RED)$(BOLD)$@$(RESET)\n"; \
		echo "$(RED)$(BOLD)ERROR>>>>>>>>>>>>>>>$(RESET)$(YELLOW)\n"; \
		sed '$$d' $(ERRORTXT); \
		echo "$(RED)$(BOLD)\n$(FILL)\nExiting...$(RESET)\n"; \
		exit 1; fi
	@if [ $(SUCCESS) ]; then \
		$(eval SUCCESS=$(shell echo $$(($(SUCCESS)+1)))) \
		echo "$(RESET)$(VIOLET)$<$(RESET) -> $(GREEN)$(BOLD)$@$(RESET)"; else \
		echo "$(GREEN)$(BOLD)$(CYAN)\nMAKE START!\n$(GREEN)$(FILL)$(RESET)\n \
		\n$(VIOLET)$<$(RESET) -> $(GREEN)$(BOLD)$@$(RESET)"; fi

bonus: $(BONUS)

$(BONUS): $(OBJS_BNS)
	@make -C $(LIBFTDIR)
	@$(CC) $(CFLAGS) $^ $(LIBFTDIR)/$(LIBFTBIN) -o $(BONUSBIN)
	@echo "$(GREEN)$(BOLD)\n$(FILL)$(CYAN)\nFINISHED!$(RESET)\n"
	@echo "$(VIOLET)Compiled $(GREEN)$(SUCCESS)$(VIOLET) object file(s).$(RESET)\n"
	@echo "$(VIOLET)Using compiler $(GREEN)$(CC)$(VIOLET) with flags $(GREEN)$(CFLAGS)$(RESET)\n"
	@echo "$(VIOLET)Successfully compiled binary: $(GREEN)$(BOLD)$(BONUSBIN)$(RESET)\n"
	@touch $(BONUS)

debug: $(DEBUG)

$(DEBUG): $(OBJS_DEBUG)
	@make -C $(LIBFTDIR)
	@$(CC) $(CFLAGS) $^ $(LIBFTDIR)/$(LIBFTBIN) -o $(DEBUGBIN)
	@echo "$(GREEN)$(BOLD)\n$(FILL)$(CYAN)\nFINISHED!$(RESET)\n"
	@echo "$(VIOLET)Compiled $(GREEN)$(SUCCESS)$(VIOLET) object file(s).$(RESET)\n"
	@echo "$(VIOLET)Using compiler $(GREEN)$(CC)$(VIOLET) with flags $(GREEN)$(CFLAGS) $(DEBUGFLAGS)$(RESET)\n"
	@echo "$(VIOLET)Successfully compiled binary: $(GREEN)$(BOLD)$(DEBUGBIN)$(RESET)\n"
	@touch $(DEBUG)

clean:
	@echo "$(GREEN)$(BOLD)$(CYAN)\nCLEAN START!\n$(GREEN)$(FILL)$(RESET)\n"
	@echo "$(VIOLET)Removing object and dependency file(s) for $(GREEN)$(BOLD)$(LIBFTBIN)$(RESET)"
	@make -C $(LIBFTDIR) clean
	@echo "\n$(VIOLET)Removing object and dependency file(s) for $(GREEN)$(BOLD)$(NAME)$(RESET)\n"
	@$(RM) $(OBJSDIR) $(DEPSDIR) $(ERRORTXT) $(DEBUG) $(BONUS)
	@echo "$(GREEN)$(BOLD)$(FILL)$(CYAN)\nFINISHED!$(RESET)"

fclean: clean
	@echo "$(GREEN)$(BOLD)$(CYAN)\nFCLEAN START!\n$(GREEN)$(FILL)$(RESET)\n"
	@echo "$(VIOLET)Removing all binary file(s) for $(GREEN)$(BOLD)$(LIBFTBIN)$(RESET) \
	$(VIOLET)and $(GREEN)$(BOLD)$(NAME)$(RESET)"
	@$(RM) $(OBJSDIR) $(DEPSDIR) $(ERRORTXT) $(DEBUG) $(BONUS)
	@echo "$(GREEN)$(BOLD)\n$(FILL)$(CYAN)\nFINISHED!$(RESET)"
	@$(RM) $(NAME) $(BONUSBIN) $(DEBUGBIN) $(LIBFTDIR)/$(LIBFTBIN)

re: fclean all

$(OBJSDIR) $(DEPSDIR):
	@mkdir -p $@

$(DEPS):
	include $(wildcard $(DEPS))

.PHONY: all bonus debug clean fclean re
