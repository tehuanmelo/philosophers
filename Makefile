NAME = philo
SRCFILES =\
ft_atoi_v2.c\
ph_actions.c\
ph_call_philos.c\
ph_create_philos.c\
ph_main.c\
ph_print_status.c\
ph_set_table.c\
ph_timers.c
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