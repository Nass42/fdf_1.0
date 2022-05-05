# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: namohamm <namohamm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/19 00:25:32 by namohamm          #+#    #+#              #
#    Updated: 2022/03/19 13:20:39 by namohamm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minitalk
CLIENT	=	client
SERVER	=	server

CLIENT_BONUS	= client_bonus
SERVER_BONUS	= server_bonus

SRC_CLIENT	=	client.c
OBJ_CLIENT	=	$(SRC_CLIENT:%.c=%.o)
SRC_SERVER	=	server.c
OBJ_SERVER	=	$(SRC_SERVER:%.c=%.o)

SRC_CLIENT_BONUS	=	client_bonus.c
OBJ_CLIENT_BONUS	=	$(SRC_CLIENT:%.c=%.o)
SRC_SERVER_BONUS	=	server_bonus.c
OBJ_SERVER_BONUS	=	$(SRC_SERVER:%.c=%.o)

RM		= rm -f
GCCF = gcc -Wall -Wextra -Werror

all:			$(NAME)

$(NAME):		$(CLIENT) $(SERVER)

.c.o:
				$(GCCF) $(CFLAGS) -c $< -o $(<:.c=.o)

$(CLIENT):		$(OBJ_CLIENT)
					$(GCCF) $(OBJ_CLIENT) -o $@
$(SERVER):		$(OBJ_SERVER)
					$(GCCF) $(OBJ_SERVER) -o $@

bonus: $(CLIENT_BONUS) $(SERVER_BONUS)
				
$(CLIENT_BONUS):		$(OBJ_CLIENT_BONUS)
						$(GCCF) $(OBJ_CLIENT_BONUS) -o $@
$(SERVER_BONUS):		$(OBJ_SERVER_BONUS)
						$(GCCF) $(OBJ_SERVER_BONUS) -o $@

clean:
		${RM} ${OBJ_CLIENT} ${OBJ_SERVER} ${OBJ_CLIENT_BONUS} ${OBJ_SERVER_BONUS}
		
fclean:	clean
		${RM} ${CLIENT} ${SERVER} ${CLIENT_BONUS} ${SERVER_BONUS}

re:		fclean all