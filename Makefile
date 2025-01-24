
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = ./libft
GNL_DIR = ./get_next_line
PRINTF_DIR = ./ft_printf

SRCS = $(LIBFT_DIR)/ft_atoi.c $(LIBFT_DIR)/ft_bzero.c $(LIBFT_DIR)/ft_calloc.c $(LIBFT_DIR)/ft_isalnum.c $(LIBFT_DIR)/ft_isalpha.c \
       $(LIBFT_DIR)/ft_isascii.c $(LIBFT_DIR)/ft_isdigit.c $(LIBFT_DIR)/ft_isprint.c $(LIBFT_DIR)/ft_itoa.c $(LIBFT_DIR)/ft_memchr.c \
       $(LIBFT_DIR)/ft_memcmp.c $(LIBFT_DIR)/ft_memcpy.c $(LIBFT_DIR)/ft_memmove.c $(LIBFT_DIR)/ft_memset.c $(LIBFT_DIR)/ft_putchar_fd.c \
       $(LIBFT_DIR)/ft_putendl_fd.c $(LIBFT_DIR)/ft_putnbr_fd.c $(LIBFT_DIR)/ft_putstr_fd.c $(LIBFT_DIR)/ft_split.c $(LIBFT_DIR)/ft_strchr.c \
       $(LIBFT_DIR)/ft_strdup.c $(LIBFT_DIR)/ft_striteri.c $(LIBFT_DIR)/ft_strjoin.c $(LIBFT_DIR)/ft_strlcat.c $(LIBFT_DIR)/ft_strlcpy.c \
       $(LIBFT_DIR)/ft_strlen.c $(LIBFT_DIR)/ft_strmapi.c $(LIBFT_DIR)/ft_strncmp.c $(LIBFT_DIR)/ft_strnstr.c $(LIBFT_DIR)/ft_strrchr.c \
       $(LIBFT_DIR)/ft_strtrim.c $(LIBFT_DIR)/ft_substr.c $(LIBFT_DIR)/ft_tolower.c $(LIBFT_DIR)/ft_toupper.c $(LIBFT_DIR)/flood_fill.c \
	   $(LIBFT_DIR)/flood_fill_target.c $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c $(PRINTF_DIR)/format_check.c \
	   $(PRINTF_DIR)/ft_printf.c $(PRINTF_DIR)/ft_putchar.c $(PRINTF_DIR)/ft_putnbr.c $(PRINTF_DIR)/ft_strlen2.c \
	   $(PRINTF_DIR)/printf_hexadecimal.c


OBJS = $(SRCS:.c=.o)
NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re







