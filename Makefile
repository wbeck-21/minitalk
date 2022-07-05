CLIENT = client
SERVER = server

CC 		= gcc
FLAGS 	= -Wall -Wextra -Werror
LIB		= ./libft/libft.a
INC		= -I ./libft
HEADERS	= client.h server.h
RM		= rm -rf

CLIENT_SRCS = mandatory/client.c 			  
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

SERVER_SRCS = mandatory/server.c 
SERVER_OBJS = $(SERVER_SRCS:.c=.o)


all:		$(CLIENT) $(SERVER)

$(CLIENT):	$(CLIENT_OBJS)
			@make -s -C libft
			@${CC} ${FLAGS} -o ${CLIENT} $^ ${LIB}
	
$(SERVER):	$(SERVER_OBJS)
			@make -s -C libft
			@${CC} ${FLAGS} -o ${SERVER} $^ ${LIB}
	
%.o:		%.c $(HEADERS)
			@$(CC) $(FLAGS) ${INC} -o $@ -c $<

clean:
			@make clean -C libft
			@${RM}  $(CLIENT_OBJS) $(SERVER_OBJS)

fclean:		clean
			@make fclean -C libft
			@${RM} $(SERVER) $(CLIENT)

re:			fclean all

PHONY:		all clean fclean re