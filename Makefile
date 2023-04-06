NAME		= so_long

CC			= gcc

CFLAGS 		= -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3

LINKS 		= -Lmlx_linux -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

SRCDIR		= ./srcs/

SRCS		= $(SRCDIR)so_long.c \
				$(SRCDIR)errors.c \
				$(SRCDIR)free.c \
				$(SRCDIR)display.c \
				$(SRCDIR)valid2.c \
				$(SRCDIR)sprites.c \
				$(SRCDIR)get_map.c \
				$(SRCDIR)set_data.c \
				$(SRCDIR)valid.c \
				$(SRCDIR)playable.c

OBJS		= $(SRCS:.c=.o)

LIBFTPATH	= lib/libft/

LIBFTMAKE	= $(MAKE) -C $(LIBFTPATH)

LIBFT		= -L$(LIBFTPATH) -lft


all: $(NAME)

$(NAME): $(OBJS)
	@echo $(CURSIVE)$(GRAY) "     - Making libft..." $(NONE)
	$(LIBFTMAKE)
	@echo $(CURSIVE)$(GRAY) "     - Compiling $(NAME)..." $(NONE)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LINKS) $(LIBFT)
	@echo $(GREEN)"- Compiled -"$(NONE)

.c.o:
	@echo $(CURSIVE)$(GRAY) "     - Making object files..." $(NONE)
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

clean:
	@echo $(CURSIVE)$(GRAY) "     - Removing object files..." $(NONE)
	$(LIBFTMAKE) clean
	$(RM) $(OBJS)

fclean: clean
	@echo $(CURSIVE)$(GRAY) "     - Removing $(NAME)..." $(NONE)
	$(LIBFTMAKE) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

NONE='\033[0m'
GREEN='\033[32m'
YELLOW='\033[33m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'