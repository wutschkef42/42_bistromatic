NAME = libbsm_tools.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c99

SRCDIR = ./src
OBJDIR = ./obj
INCDIR = ./includes

SRCS = 	conversion_tools.c \
		str_tools.c \
		mem_tools.c \
		neg_str_tools.c

OBJS = $(addprefix $(OBJDIR)/,$(SRCS:.c=.o))

all: obj $(NAME)
	
obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) -I $(INCDIR) -o $@ -c $<

$(NAME): $(OBJS) $(OBJDIR)
	ar -rcs $(NAME) $(OBJS)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re