#################################################################################
#                           ▗▄▄▖ ▗▄▖ ▗▖    ▗▄▖ ▗▖  ▗▖ ▗▄▄▖                      #
#                          ▐▌   ▐▌ ▐▌▐▌   ▐▌ ▐▌▐▛▚▖▐▌▐▌                         #
#                           ▝▀▚▖▐▌ ▐▌▐▌   ▐▌ ▐▌▐▌ ▝▜▌▐▌▝▜▌                      #
#                          ▗▄▄▞▘▝▚▄▞▘▐▙▄▄▖▝▚▄▞▘▐▌  ▐▌▝▚▄▞▘                      #
#################################################################################

#──────────────────────────────────── Bases ─────────────────────────────────────
NAME		= so_long
CC         	= cc
CFLAGS     	= -Wall -Werror -Wextra -g
RM         	= rm -rf
LIBS_DIR	= libs

#─────────────────────────────────── Mlx Files ───────────────────────────────────
MLX_DIR		= $(LIBS_DIR)/mlx
MLX			= $(MLX_DIR)/libmlx.a
MLX_INCS	= -I$(MLX_DIR)
MLX_ADD		= -L$(MLX_DIR) -lmlx -lXext -lX11

#────────────────────────────────── MyLib Files ──────────────────────────────────
MYLIB_DIR	= $(LIBS_DIR)/mylib
MYLIB		= $(MYLIB_DIR)/libmylib.a
MYLIB_INCS	= -I$(MYLIB_DIR)/include
MYLIB_ADD	= -L$(MYLIB_DIR) -lmylib

#────────────────────────────────── Main Files ───────────────────────────────────
SRCS 		= mandatory/src/main/main.c \
			  mandatory/src/error/error.c \
			  mandatory/src/map/get_map.c \
			  mandatory/src/map/parse_map.c \
			  mandatory/src/map/util.c \
			  mandatory/src/event/keys.c \
			  mandatory/src/event/move.c \
			  mandatory/src/graphic/sprites.c \
			  mandatory/src/graphic/window.c

INCS		= $(MLX_INCS) \
			  $(MYLIB_INCS) \
			  -Imandatory/include \
			  -Imandatory/include/graphic
OBJS_DIR	= .objs
OBJS		= $(SRCS:%.c=$(OBJS_DIR)/%.o)
#────────────────────────────────── Bonus Files ───────────────────────────────────
BONUS	= so_long_bonus
B_SRCS	= mandatory/src/main/main.c \
		  mandatory/src/error/error.c \
		  mandatory/src/map/get_map.c \
		  mandatory/src/map/parse_map.c \
		  mandatory/src/map/util.c \
		  mandatory/src/event/keys.c \
		  bonus/src/event/move_bonus.c \
		  bonus/src/graphic/counter_bonus.c \
		  bonus/src/graphic/sprites_bonus.c \
		  bonus/src/graphic/window_bonus.c

B_INCS		= $(MLX_INCS) \
			  $(MYLIB_INCS) \
			  -Imandatory/include \
			  -Ibonus/include
B_OBJS_DIR	= .objs/bonus
B_OBJS		= $(B_SRCS:%.c=$(B_OBJS_DIR)/%.o)

#────────────────────────────────── MFA Files ────────────────────────────────────
mfa_dir				= $(OBJS_DIR)/makefile
mfa_header			= $(mfa_dir)/mfa_header
mfa_footer			= $(mfa_dir)/mfa_footer
mfa_bonus_header	= $(mfa_dir)/mfa_bonus_header
mfa_bonus_footer	= $(mfa_dir)/mfa_bonus_footer
mfa_name_compiling	= $(mfa_dir)/mfa_name_compiling
mfa_bonus_compiling	= $(mfa_dir)/mfa_bonus_compiling
mfa_h_len			= 76
debug_on			= .debug_on

#─────────────────────────────────── Main Rules ──────────────────────────────────
all: $(mfa_header) $(NAME) $(mfa_footer)

$(NAME): $(MLX) $(MYLIB) $(mfa_name_compiling) $(OBJS)
	@if [ -f "$(debug_on)" ]; then \
		echo "$(CC) $(CFLAGS) $(OBJS) -o $@ $(MLX_ADD) $(MYLIB_ADD)"; \
		$(CC) $(CFLAGS) $(OBJS) -o $@ $(MLX_ADD) $(MYLIB_ADD); \
	else \
		$(CC) $(CFLAGS) $(OBJS) -o $@ $(MLX_ADD) $(MYLIB_ADD); \
		make mfa_object mfa_name="$(green)>>> $(reset)$(NAME)" mfa_symbol="$(green)[✔]" --no-print-directory; \
	fi
	@make mfa_success --no-print-directory

$(OBJS_DIR)/%.o: %.c
	@if [ -f "$(debug_on)" ]; then \
    		echo "mkdir -p $(dir $@)"; \
      		mkdir -p $(dir $@); \
      		echo "$(CC) $(CFLAGS) -c $< -o $@ $(INCS)"; \
    		$(CC) $(CFLAGS) -c $< -o $@ $(INCS); \
    	else \
    		mkdir -p $(dir $@); \
    		$(CC) $(CFLAGS) -c $< -o $@ $(INCS); \
    		make mfa_object mfa_name="$(notdir $@)" mfa_symbol="$(green)[✔]" --no-print-directory; \
    	fi

clean: mfa_clean_header mlx_clean mylib_clean
	@printf "\n"
	@make mfa_removing mfa_name="$(NAME)" --no-print-directory
	@if [ -f "$(debug_on)" ]; then \
		echo "$(RM) $(OBJS_DIR)"; \
		$(RM) $(OBJS_DIR); \
	else \
		if [ -d "$(OBJS_DIR)" ]; then \
			$(RM) $(OBJS_DIR); \
			make mfa_object mfa_name="$(NAME) objects" mfa_symbol="$(pink)[✔]" --no-print-directory; \
		else \
			printf "Nothing to be removed\n"; \
		fi; \
	fi
	@make mfa_success --no-print-directory
	@make mfa_clean_header --no-print-directory

fclean: mfa_clean_header mlx_clean mylib_fclean
	@printf "\n"
	@make mfa_removing mfa_name="$(NAME)" --no-print-directory
	@if [ -f "$(debug_on)" ]; then \
		echo "$(RM) $(OBJS_DIR)"; \
		$(RM) $(OBJS_DIR); \
		echo "$(RM) $(NAME)"; \
		$(RM) $(NAME); \
		echo "$(RM) $(BONUS)"; \
        $(RM) $(BONUS); \
	else \
		if [ -f "$(NAME)" ] || [ -d "$(OBJS_DIR)" ] || [ -f "$(BONUS)" ]; then \
			if [ -d "$(OBJS_DIR)" ]; then \
				$(RM) $(OBJS_DIR); \
				make mfa_object mfa_name="$(NAME) objects" mfa_symbol="$(pink)[✔]" --no-print-directory; \
			fi; \
			if [ -f "$(NAME)" ]; then \
				$(RM) $(NAME); \
				make mfa_object mfa_name="$(green)>>> $(reset)$(NAME)" mfa_symbol="$(pink)[✔]" --no-print-directory; \
			fi; \
			if [ -f "$(BONUS)" ]; then \
				$(RM) $(BONUS); \
				make mfa_object mfa_name="$(green)>>> $(reset)$(BONUS)" mfa_symbol="$(pink)[✔]" --no-print-directory; \
			fi; \
		else \
			printf "Nothing to be removed\n"; \
		fi; \
	fi
	@make mfa_success --no-print-directory
	@make mfa_clean_header --no-print-directory

re: fclean all

#──────────────────────────────────── Bonus Rule ─────────────────────────────────────
bonus: $(mfa_bonus_header) $(BONUS) $(mfa_bonus_footer)

$(BONUS): $(MLX) $(MYLIB) $(mfa_bonus_compiling) $(B_OBJS)
	@if [ -f "$(debug_on)" ]; then \
		echo "$(CC) $(CFLAGS) $(OBJS) -o $@ $(MLX_ADD) $(MYLIB_ADD)"; \
		$(CC) $(CFLAGS) $(B_OBJS) -o $@ $(MLX_ADD) $(MYLIB_ADD); \
	else \
		$(CC) $(CFLAGS) $(B_OBJS) -o $@ $(MLX_ADD) $(MYLIB_ADD); \
		make mfa_object mfa_name="$(green)>>> $(reset)$@" mfa_symbol="$(green)[✔]" --no-print-directory; \
	fi
	@make mfa_success --no-print-directory

$(B_OBJS_DIR)/%.o: %.c
	@if [ -f "$(debug_on)" ]; then \
  			echo "mkdir -p $(dir $(OBJS_DIR))"; \
            mkdir -p $(dir $(OBJS_DIR)); \
    		echo "mkdir -p $(dir $@)"; \
      		mkdir -p $(dir $@); \
      		echo "$(CC) $(CFLAGS) -c $< -o $@ $(B_INCS)"; \
    		$(CC) $(CFLAGS) -c $< -o $@ $(B_INCS); \
    	else \
    		mkdir -p $(dir $(OBJS_DIR)); \
    		mkdir -p $(dir $@); \
    		$(CC) $(CFLAGS) -c $< -o $@ $(B_INCS); \
    		make mfa_object mfa_name="$(notdir $@)" mfa_symbol="$(green)[✔]" --no-print-directory; \
    	fi

#──────────────────────────────────── Mlx Rule ─────────────────────────────────────
$(MLX):
	@printf "\n"
	@make mfa_compiling mfa_name="mlx" --no-print-directory
	@if [ -f "$(debug_on)" ]; then \
		make -C $(MLX_DIR) all V=1; \
	else \
		make -C $(MLX_DIR) all --no-print-directory > /dev/null 2>&1; \
		make mfa_object mfa_name="$(green)>>> $(reset)libmlx.a" mfa_symbol="$(green)[✔]" --no-print-directory; \
		make mfa_object mfa_name="$(green)>>> $(reset)libmlx_Linux.a" mfa_symbol="$(green)[✔]" --no-print-directory; \
	fi
	@make mfa_success --no-print-directory; \

mlx_clean:
	@printf "\n"
	@make mfa_removing mfa_name="mlx" --no-print-directory
	@if [ -f "$(debug_on)" ]; then \
		make -C $(MLX_DIR) clean; \
	else \
		if [ -f "$(MLX)" ]; then \
			make -C $(MLX_DIR) clean --no-print-directory > /dev/null 2>&1; \
			make mfa_object mfa_name="mlx objects" mfa_symbol="$(pink)[✔]" --no-print-directory; \
			make mfa_object mfa_name="$(green)>>> $(reset)libmlx.a" mfa_symbol="$(pink)[✔]" --no-print-directory; \
			make mfa_object mfa_name="$(green)>>> $(reset)libmlx_Linux.a" mfa_symbol="$(pink)[✔]" --no-print-directory; \
		else \
			printf "Nothing to be removed\n"; \
		fi; \
	fi
	@make mfa_success --no-print-directory; \

#────────────────────────────────── MyLib Rules ────────────────────────────────────
$(MYLIB):
	@if [ -f "$(debug_on)" ]; then \
		make -C $(MYLIB_DIR) all mfa_h_len=$(mfa_h_len) V=1; \
	else \
		make -C $(MYLIB_DIR) all mfa_h_len=$(mfa_h_len) --no-print-directory; \
	fi

mylib_clean:
	@if [ -f "$(debug_on)" ]; then \
  		echo "-C $(MYLIB_DIR) clean"; \
		make -C $(MYLIB_DIR) clean mfa_h_len=$(mfa_h_len); \
	else \
		make -C $(MYLIB_DIR) clean mfa_h_len=$(mfa_h_len) --no-print-directory; \
	fi

mylib_fclean:
	@if [ -f "$(debug_on)" ]; then \
		make -C $(MYLIB_DIR) fclean mfa_h_len=$(mfa_h_len); \
	else \
		make -C $(MYLIB_DIR) fclean mfa_h_len=$(mfa_h_len) --no-print-directory; \
	fi

#─────────────────────────────────── Color Codes ───────────────────────────────────
yellow 	= \033[1m\033[38;2;255;248;147m
pink	= \033[1m\033[38;2;231;133;190m
green	= \033[1m\033[38;2;129;223;164m
reset	= \033[0m

#──────────────────────────────────── MFA Rules ────────────────────────────────────
$(mfa_dir):
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(mfa_dir)

$(mfa_header):
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(mfa_dir)
	@printf "$(yellow)\n"
	@make mfa_line_message mfa_name2="\n" mfa_line="▒" --no-print-directory
	@printf "                                                                           \n"
	@printf "▒▒▒▒▒▒▒╗ ▒▒▒▒▒▒╗       ▒▒╗      ▒▒▒▒▒▒╗ ▒▒▒╗   ▒▒╗ ▒▒▒▒▒▒╗                 \n"
	@printf "▒▒╔════╝▒▒╔═══▒▒╗      ▒▒║     ▒▒╔═══▒▒╗▒▒▒▒╗  ▒▒║▒▒╔════╝                 \n"
	@printf "▒▒▒▒▒▒▒╗▒▒║   ▒▒║      ▒▒║     ▒▒║   ▒▒║▒▒╔▒▒╗ ▒▒║▒▒║  ▒▒▒╗                \n"
	@printf "╚════▓▓║▓▓║   ▓▓║      ▓▓║     ▓▓║   ▓▓║▓▓║╚▓▓╗▓▓║▓▓║   ▓▓║                \n"
	@printf "▓▓▓▓▓▓▓║╚▓▓▓▓▓▓╔╝▓▓▓▓▓╗▓▓▓▓▓▓▓╗╚▓▓▓▓▓▓╔╝▓▓║ ╚▓▓▓▓║╚▓▓▓▓▓▓╔╝                \n"
	@printf "╚══════╝ ╚═════╝ ╚════╝╚══════╝ ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝ by joao-almeida!\n"
	@printf "$(reset)"
	@touch $(mfa_header)

$(mfa_footer):
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(mfa_dir)
	@printf "$(yellow)\n"
	@make mfa_line_message mfa_name2="\n" mfa_line="▒" --no-print-directory
	@printf "$(reset)\n"
	@touch $(mfa_footer)

mfa_clean_header:
	@printf "$(pink)\n"
	@make mfa_line_message mfa_name2="\n" mfa_line="▒" --no-print-directory
	@printf "$(reset)"

$(mfa_name_compiling):
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(mfa_dir)
	@printf "\n"
	@make mfa_line_message mfa_name1="$(yellow)Compiling [$(NAME)] /" mfa_name2="$(reset)\\n" mfa_line="─" --no-print-directory
	@touch $(mfa_name_compiling)

$(mfa_bonus_header):
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(mfa_dir)
	@printf "$(yellow)\n"
	@make mfa_line_message mfa_name2="\n" mfa_line="▒" --no-print-directory
	@printf "$(reset)"
	@touch $(mfa_bonus_header)

$(mfa_bonus_compiling):
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(mfa_dir)
	@printf "\n"
	@make mfa_line_message mfa_name1="$(yellow)Compiling [$(NAME)_bonus] /" mfa_name2="$(reset)\\n" mfa_line="─" --no-print-directory
	@touch $(mfa_bonus_compiling)

$(mfa_bonus_footer):
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(mfa_dir)
	@printf "$(yellow)\n"
	@make mfa_line_message mfa_name2="\n" mfa_line="▒" --no-print-directory
	@printf "$(reset)\n"
	@touch $(mfa_bonus_footer)

mfa_compiling:
	@make mfa_line_message mfa_name1="$(yellow)Compiling [$(mfa_name)] /" mfa_name2="$(reset)\\n" mfa_line="─" --no-print-directory

mfa_object:
	@make mfa_line_message mfa_name1="$(mfa_name)" mfa_name2="$(mfa_symbol)$(reset)\\n" mfa_line=" " --no-print-directory

mfa_removing:
	@make mfa_line_message mfa_name1="$(pink)Removing [$(mfa_name)] /" mfa_name2="$(reset)\\n" mfa_line="─" --no-print-directory

mfa_success:
	@make mfa_line_message mfa_name1="$(green)" mfa_name2="/ Success$(reset)\\n" mfa_line="─" --no-print-directory

mfa_line_message:
	@name1_len=$$(echo -n "$(mfa_name1)" | sed -E 's/\x1b\[[0-9;]*m//g' | wc -m); \
		name2_len=$$(($(shell echo -n "$(mfa_name2)" | sed -E 's/\x1b\[[0-9;]*m//g' | wc -m) )); \
		line_len=$$(($(mfa_h_len) - $$name1_len - $$name2_len)); \
		printf "$(mfa_name1)"; \
		for i in $$(seq 1 $$line_len); do \
			$(if $(mfa_line), printf "$(mfa_line)", printf " "); \
		done; \
		printf "$(mfa_name2)";

debug:
	@make -C $(MYLIB_DIR) debug --no-print-directory
	@if [ ! -f "$(debug_on)" ]; then \
		touch $(debug_on); \
		make mfa_line_message mfa_name1="$(green)Debug Mode /" mfa_name2="/ ON$(reset)\\n" mfa_line="─" --no-print-directory; \
	else \
	  	$(RM) $(debug_on); \
	  	make mfa_line_message mfa_name1="$(pink)Debug Mode /" mfa_name2="/ OFF$(reset)\\n" mfa_line="─" --no-print-directory; \
	fi

#────────────────────────────────── Phony Targets ───────────────────────────────
.PHONY: all clean fclean re
