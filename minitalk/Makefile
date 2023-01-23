# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aamhal <aamhal@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/19 22:51:21 by aamhal            #+#    #+#              #
#    Updated: 2023/01/19 23:06:50 by aamhal           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra
CC = cc
CLIENT = client
SERVER = server
CLIENT_BONUS = clientbonus
SERVER_BONUS = serverbonus


all: $(CLIENT) $(SERVER)

$(CLIENT) : client.c
		$(CC) $(CFLAGS) client.c minitalkutils.c -o client

$(SERVER) : server.c
		$(CC) $(CFLAGS) server.c minitalkutils.c -o server

bonus: $(CLIENT_BONUS) $(SERVER_BONUS)

$(CLIENT_BONUS) : clientbonus.c
		$(CC) $(CFLAGS) clientbonus.c minitalkutils.c -o clientbonus

$(SERVER_BONUS) : serverbonus.c
		$(CC) $(CFLAGS) serverbonus.c minitalkutils.c -o serverbonus
clean:
	rm -rf $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)
	
fclean:
	rm -rf $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)

re:	fclean all