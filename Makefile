CLIENT = client
SERVER = server

CC 		= gcc
FLAGS 	= -Wall -Wextra -Werror
LIB		= ./libft/libft.a
INC		= -I ./libft
RM		= rm -rf

HEAD_SRCS	=	client.h server.h client_bonus.h server_bonus.h
HEAD_DIR	=	include/
HEAD		=	$(addprefix $(HEAD_DIR), $(HEAD_SRCS))

CLIENT_SRCS = mandatory/client.c 			  
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

SERVER_SRCS = mandatory/server.c 
SERVER_OBJS = $(SERVER_SRCS:.c=.o)

BONUS_CLIENT_SRCS = bonus/client_bonus.c 			  
BONUS_CLIENT_OBJS = $(BONUS_CLIENT_SRCS:.c=.o)

BONUS_SERVER_SRCS = bonus/server_bonus.c 
BONUS_SERVER_OBJS = $(BONUS_SERVER_SRCS:.c=.o)


all:		$(CLIENT) $(SERVER)

bonus : 	$(BONUS_CLIENT_OBJS) $(BONUS_SERVER_OBJS)
			@${RM} $(CLIENT_OBJS) $(SERVER_OBJS)
			@make -s -C libft
			@${CC} $(FLAGS) -o ${CLIENT} $(BONUS_CLIENT_OBJS) ${LIB}
			@${CC} $(FLAGS) -o ${SERVER} $(BONUS_SERVER_OBJS) ${LIB}

$(CLIENT):	$(CLIENT_OBJS)
			@make -s -C libft
			@${CC} ${FLAGS} -o ${CLIENT} $^ ${LIB}
	
$(SERVER):	$(SERVER_OBJS)
			@make -s -C libft
			@${CC} ${FLAGS} -o ${SERVER} $^ ${LIB}
	
%.o:		%.c $(HEAD)
			@$(CC) $(FLAGS) ${INC} -o $@ -c $<

clean:
			@make clean -C libft
			@${RM}  $(CLIENT_OBJS) $(SERVER_OBJS) $(BONUS_CLIENT_OBJS) $(BONUS_SERVER_OBJS)

fclean:		clean
			@make fclean -C libft
			@${RM} $(SERVER) $(CLIENT)

re:			fclean all

PHONY:		all clean fclean re