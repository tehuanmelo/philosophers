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
OBJ = $(patsubst %.c, $(OBJPATH)%.o, $(SRCFILES))
CC = gcc
CFLAGS = -Wall -Werror -Wextra -pthread

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