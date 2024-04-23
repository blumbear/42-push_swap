NAME = push_swap

LIBAMOA = libamoa/libamoa.a

CC = cc
CFLAGS += -Wall -Wextra -Werror -g -Iinclude

LFLAGS = -Llibamoa

FILES = main utils print_and_error rules instruction

OBJ_DIR = obj/
SRC_DIR = src/
SRCS = $(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))
OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

.PHONY: all clean fclean re bonus

all: $(NAME)

bonus: all

clean:
	@echo "\033[32m✔ Suppression des fichiers sources...\033[37m"
	rm -rf $(OBJ_DIR)
	make clean -C libamoa
	@echo "\033[32m✔ Suppression effectuer...\033[37m"

fclean: clean
	@echo "\033[32m✔ Suppression de l'éxécutable...\033[37m"
	rm -rf $(NAME)
	make fclean -C libamoa
	@echo "\033[32m✔ Suppression effectuer...\033[37m"

re: fclean all

$(LIBAMOA) :
	make -C libamoa

$(NAME): $(OBJ_DIR) $(OBJS) $(LIBAMOA)
	@echo "\033[32m✔ Compilation des fichiers objets...\033[37m"
	$(CC) -o $@ $(OBJS) $(LIBAMOA) $(LFLAGS)
	@echo "\033[32m✔ executable crée...\033[37m"

$(OBJ_DIR):
	@echo "\033[32m✔ création du repertoire obj...\033[37m"
	mkdir $@
	@echo "\033[32m✔ repertoire obj crée...\033[37m"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@
