SRCS	=

OBJS	= ${SRCS:.c=.o}

NAME	= cub3D

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

RM		= rm -f

%.o:
			${CC} ${CFLAGS} -o $@ -c $< -I.

all:		${NAME}

${NAME}:	${OBJS}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all
