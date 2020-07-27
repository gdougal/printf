NAME 		= libftprintf.a

CC			= gcc

CFLAGS		= #-Wall -Wextra -Werror

HEADER_DIR  = includes/

LIBFT_DIR   = libft/

OBJ_DIR     = obj/

PROC_DIR	= processor/

SRC_PRINTF  = ft_printf.c
OBJ_PRINTF  = $(addprefix $(OBJ_DIR), $(SRC_PRINTF:.c=.o))
HEAD_PRINTF = $(addprefix $(HEADER_DIR), ft_printf.h)

SRC_PARSE   = ft_parser.c
OBJ_PARSE   = $(addprefix $(OBJ_DIR), $(SRC_PARSE:.c=.o))
HEAD_PARSE  = $(addprefix $(HEADER_DIR), ft_parser.h)

SRC_PROC    = ft_processor.c	ft_cymboll.c	ft_hex.c	ft_integer.c	ft_percent.c	ft_pointer.c \
			  ft_string.c		ft_unsigned.c
OBJ_PROC    = $(addprefix $(OBJ_DIR), $(SRC_PROC:.c=.o))
HEAD_PROC   = $(addprefix $(HEADER_DIR), ft_proc.h)


.PHONY: all
all: $(NAME)

$(NAME): $(OBJ_DIR) obj
		@make -C $(LIBFT_DIR)
		@cp $(LIBFT_DIR)libft.a $(NAME)
		@ar rcs $(NAME) $(OBJ_DIR)*.o

$(OBJ_DIR):
		@mkdir $(OBJ_DIR)

.PHONY: obj
obj: $(OBJ_PRINTF) $(OBJ_PARSE) $(OBJ_PROC)

$(OBJ_PRINTF): $(OBJ_DIR)%.o: %.c $(HEAD_PRINTF)
		$(CC) $(CFLAGS) -I $(HEADER_DIR) -I $(LIBFT_DIR) -c $< -o $@

$(OBJ_PARSE): $(OBJ_DIR)%.o: %.c $(HEAD_PARSE)
		$(CC) $(CFLAGS) -I $(HEADER_DIR) -I $(LIBFT_DIR) -c $< -o $@

$(OBJ_PROC): $(OBJ_DIR)%.o: $(PROC_DIR)%.c $(HEAD_PROC)
		$(CC) $(CFLAGS) -I $(HEADER_DIR) -I $(LIBFT_DIR) -c $< -o $@

.PHONY: clean
clean:
		rm -rf $(OBJ_DIR)
		make -C $(LIBFT_DIR) clean

.PHONY: fclean
fclean: clean
		rm -f $(NAME)
		make -C $(LIBFT_DIR) fclean

.PHONY: re
re: fclean all