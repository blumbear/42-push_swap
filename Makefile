NAME = push_swap
NAME_BONUS = checker

LIBAMOA = libamoa/libamoa.a

CC = cc

CFLAGS =	-Wall -Wextra -Werror -g \
			-Iinclude

LFLAGS =	-Llibamoa \
			-lamoa

FILES = algo fill_stack ft_opti instruction main print_and_error research_fonction \
rules set utils
FILES_BONUS = checker

OBJ_DIR = obj/
SRC_DIR = src/
BONUS_DIR = bonus/
SRCS = $(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))
OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))
SRCS_BONUS = $(addprefix $(BONUS_DIR), $(addsuffix .c, $(FILES_BONUS)))
OBJS_BONUS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES_BONUS))) $(filter-out $(OBJ_DIR)main.o, $(OBJS))

all: $(NAME)

bonus: $(NAME_BONUS)

clean :
	rm -rf $(OBJ_DIR)
	make fclean -C libamoa

fclean : clean
	rm -rf $(NAME)
	rm -rf $(NAME_BONUS)
	make fclean -C libamoa

re: fclean all

$(NAME): $(OBJ_DIR) $(OBJS) $(LIBAMOA)
	$(CC) -o $@ $(OBJS) $(LFLAGS)

$(NAME_BONUS): $(OBJ_DIR) $(OBJS_BONUS) $(LIBAMOA)
	$(CC) -o $@ $(OBJS_BONUS) $(LFLAGS)

$(LIBAMOA):
	make -C libamoa

$(OBJ_DIR):
	mkdir $@

obj/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

obj/%.o: bonus/%.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re bonus