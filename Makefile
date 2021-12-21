SRCS			=	ft_printf.c print_stroka.c print_hex_pointer.c
OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME			= libftprintf.a

all:			$(NAME)

$(NAME):
	$(CC) $(CFLAGS) -I . -c $(SRCS)  
	ar cr $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
				$(RM) $(OBJS) 

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

bonus:			$(OBJS) 
				ar rcs $(NAME) $(OBJS) 

.PHONY:			all clean fclean re