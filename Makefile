#nom de l'executable
NAME =  minishell

#compiler ; compilateur, flag de debogue, flag d'exigence
CC = cc
CFLAGS = -Wall -Werror -Wextra -g3

#include
INCL = -Linc/libft/ -Linc/minilibx-linux -Llib -lmlx_Linux -lXext -lX11 -lm

#fichiers sources
SRCS = src/main.c


#objets
OBJS = $(SRCS:.c=.o)
#les fichiers obj prennent le nom des fichiers sources "*.c"
%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $ $(<:.c=.o)

${NAME}: ${OBJS}
	make -sC inc/libft/
	make -sC inc/minilibx-linux/
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(INCL)

all : $(NAME)

clean :
	rm -rf $(OBJS)
	make -C inc/libft/ clean
	# make -C inc/minilibx-linux/ clean

fclean : clean
	rm -rf $(NAME)
	make -C inc/libft/ fclean
	# make -C inc/minilibx-linux/ fclean

re : fclean all
