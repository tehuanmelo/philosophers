NAME = philo
SRCFILES =\
main.c\
ph_actions.c
vpath %.c src
OBJPATH = obj/
SRCPATH = src/
SRC = $(addprefix $(SRCPATH), $(SRCFILES))
OBJ = $(patsubst $(SRCPATH)%.c, $(OBJPATH)%.o, $(SRC))
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address

.SILENT:

all:	$(OBJPATH) $(NAME)

$(OBJPATH):
	mkdir $(OBJPATH)

$(NAME):	$(OBJ)
	$(CC) $(CFLAGS) $^ -o $@
	echo "\033[30;43;1;3mCompilation done successfully!\033[0m"

$(OBJPATH)%.o:	%.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJPATH)

fclean: clean
	rm -f $(NAME)

re:		fclean all