NAME = philo
SRCFILES =\
actions.c\
check_death.c\
create_philos.c\
end_dinner.c\
ft_atoi_v2.c\
init_join_threads.c\
main.c\
philo_routine.c\
print_status.c\
set_table.c\
timers.c\
check_input.c
vpath %.c src
OBJPATH = obj/
SRCPATH = src/
SRC = $(addprefix $(SRCPATH), $(SRCFILES))
OBJ = $(patsubst $(SRCPATH)%.c, $(OBJPATH)%.o, $(SRC))
CC = gcc
# CFLAGS = -Wall -Werror -Wextra -pthread
CFLAGS = -Wall -Werror -Wextra -pthread -g3
# CFLAGS = -Wall -Werror -Wextra -pthread -g3 -fsanitize=address
# CFLAGS = -Wall -Werror -Wextra -pthread -g3 -fsanitize=thread

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