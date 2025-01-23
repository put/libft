# All my mandatory files that need to be compiled
SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
	   ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
	   ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
	   ft_calloc.c ft_strdup.c ft_toupper.c ft_tolower.c \
	   ft_strchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
	   ft_strnstr.c ft_atoi.c ft_strrchr.c ft_substr.c \
	   ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
	   ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
	   ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
# All my bonus files that need to be compiled
SRCSB = ft_lstnew_bonus.c ft_lstadd_front_bonus.c \
	ft_lstsize_bonus.c ft_lstlast_bonus.c \
	ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
	ft_lstclear_bonus.c ft_lstiter_bonus.c \
	ft_lstmap_bonus.c
PRINTF_DIR = printf/src/
PRINTF_SRCS = $(addprefix $(PRINTF_DIR), \
    ft_printf.c \
    cleanup.c handlers.c more_helpers.c numeric_converts.c other_converts.c strreading.c)
GNL_DIR = gnl/src/
GNL_SRCS = $(addprefix $(GNL_DIR), \
	get_next_line.c \
	get_next_line_utils.c)
# All my object files
OBJS = ${SRCS:.c=.o}
OBJSB = ${SRCSB:.c=.o}
PRINTF_OBJS = $(PRINTF_SRCS:.c=.o)
GNL_OBJS = $(GNL_SRCS:.c=.o)
INCLUDES = -I. -I$(PRINTF_DIR) -I$(GNL_DIR)
# The name of the library file
NAME = libft.a
# Archive command to make the library (r=insert, c=create, s=symbol stuff)
LIBC = ar rcs
# The C compiler command
CC = cc
# The command to remove files
RM = rm -f
# The C compiler flags
CFLAGS = -Wall -Wextra -Werror -fPIC

${NAME}: ${OBJS} ${PRINTF_OBJS} ${GNL_OBJS}
	${LIBC} ${NAME} $^
# Instruct make on how to compile .c files to .o files
%.o: %.c
	${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@
$(PRINTF_DIR)%.o: $(PRINTF_DIR)%.c
	${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@
$(GNL_DIR)%.o: $(GNL_DIR)%.c
	${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@
# Specific all command, compiles both mandatory and bonus functions
all: ${NAME} ${OBJSB}
	${LIBC} ${NAME} ${OBJSB}
# Bonus command, compiles with only the bonus files
bonus: ${OBJSB}
	${LIBC} ${NAME} ${OBJSB}
# Clean command can be used after compiling, removes all individual object files that won't be used anymore (keeps compiled library)
clean:
	${RM} ${OBJS} ${OBJSB} ${PRINTF_OBJS} ${GNL_OBJS}
# Fclean command can be used to remove ALL object files, including the compiled library.
fclean: clean
	${RM} ${NAME}
# Re command to recompile, first deletes ALL object files, then recompiles the whole project
re: fclean all
# Marks these as command labels rather than files, or something :-)
.PHONY : all bonus clean fclean re