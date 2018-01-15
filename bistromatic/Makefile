NAME = calc
NAME_TESTS = test_suite

SRC = stack.c \
		read_arith_expr.c \
		read_arith_expr2.c \
		parser_utils.c \
		tokenize_arith_expr.c \
		eval_arith_expr.c \
		\
		ops/add_op.c \
		ops/sub_op.c \
		ops/mult_op.c \
		ops/div_op.c \
		ops/mod_op.c \
		ops/bsm_ops.c \
		ops/convert.c \
		\
		fsm_parser/fsm_parse_arith_expr.c \
		fsm_parser/fsm_parse_arith_expr2.c \
		fsm_parser/get_new_event.c \
		\
		fsm_parser/action_procedures/action_end_of_data.c \
		fsm_parser/action_procedures/action_init_state_add.c \
		fsm_parser/action_procedures/action_init_state_close_bracket.c \
		fsm_parser/action_procedures/action_init_state_digit.c \
		fsm_parser/action_procedures/action_init_state_eof.c \
		fsm_parser/action_procedures/action_init_state_op.c \
		fsm_parser/action_procedures/action_init_state_open_bracket.c \
		fsm_parser/action_procedures/action_init_state_sub.c \
		\
		fsm_parser/action_procedures/action_parse_error.c \
		\
		fsm_parser/action_procedures/action_read_close_bracket_close_bracket.c \
		fsm_parser/action_procedures/action_read_close_bracket_digit.c \
		fsm_parser/action_procedures/action_read_close_bracket_eof.c \
		fsm_parser/action_procedures/action_read_close_bracket_op.c \
		fsm_parser/action_procedures/action_read_close_bracket_open_bracket.c \
		fsm_parser/action_procedures/action_read_open_bracket_add.c \
		fsm_parser/action_procedures/action_read_open_bracket_close_bracket.c \
		fsm_parser/action_procedures/action_read_open_bracket_digit.c \
		fsm_parser/action_procedures/action_read_open_bracket_eof.c \
		fsm_parser/action_procedures/action_read_open_bracket_op.c \
		fsm_parser/action_procedures/action_read_open_bracket_open_bracket.c \
		fsm_parser/action_procedures/action_read_open_bracket_sub.c \
		\
		fsm_parser/action_procedures/action_read_operand_close_bracket.c \
		fsm_parser/action_procedures/action_read_operand_digit.c \
		fsm_parser/action_procedures/action_read_operand_eof.c \
		fsm_parser/action_procedures/action_read_operand_op.c \
		fsm_parser/action_procedures/action_read_operand_open_bracket.c \
		\
		fsm_parser/action_procedures/action_read_operator_add.c \
		fsm_parser/action_procedures/action_read_operator_close_bracket.c \
		fsm_parser/action_procedures/action_read_operator_digit.c \
		fsm_parser/action_procedures/action_read_operator_eof.c \
		fsm_parser/action_procedures/action_read_operator_op.c \
		fsm_parser/action_procedures/action_read_operator_open_bracket.c \
		fsm_parser/action_procedures/action_read_operator_sub.c \
		\
		fsm_parser/action_procedures/action_read_sign_add.c \
		fsm_parser/action_procedures/action_read_sign_close_bracket.c \
		fsm_parser/action_procedures/action_read_sign_digit.c \
		fsm_parser/action_procedures/action_read_sign_eof.c \
		fsm_parser/action_procedures/action_read_sign_op.c \
		fsm_parser/action_procedures/action_read_sign_open_bracket.c \
		fsm_parser/action_procedures/action_read_sign_sub.c \
		\
		fsm_parser/action_procedures/action_utils.c \
		fsm_parser/action_procedures/action_utils2.c \

SRC_UNIT_TESTS = unit-tests/src/spec_main.c \
					unit-tests/src/spec_parse_arith_expr.c \
					unit-tests/src/spec_eval_arith_expr.c

SRCDIR = ./src
OBJDIR = ./obj
INCDIR = ./includes

SRCDIR_UNIT_TESTS = ./unit-tests/src
OBJDIR_UNIT_TESTS = ./unit-tests/obj
INCDIR_UNIT_TESTS = ../includes



BSM_TOOLS_INCDIR = ./tools/includes
BSM_TOOLS_DIR = ./tools

BSM_TOOLS_INCDIR_UNIT_TESTS = ../tools/includes
BSM_TOOLS_DIR_UNIT_TESTS = ../tools

BSM_TOOLS_LIB = $(addprefix $(BSM_TOOLS_DIR)/, bsm_tools.a)
BSM_TOOLS_INC = -I $(BSM_TOOLS_INCDIR)
BSM_TOOLS_LNK = -L $(BSM_TOOLS_DIR) -l bsm_tools

BSM_TOOLS_LIB_UNIT_TESTS  = $(addprefix $(BSM_TOOLS_DIR_UNIT_TESTS)/, bsm_tools.a)
BSM_TOOLS_INC_UNIT_TESTS = -I $(BSM_TOOLS_INCDIR_UNIT_TESTS)
BSM_TOOLS_LNK_UNIT_TESTS = -L $(BSM_TOOLS_DIR_UNIT_TESTS) -l bsm_tools

OBJ = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))
OBJ_UNIT_TESTS = $(SRC_UNIT_TESTS:.c=.o)
CC = gcc
FLAGS =	-Wall -Werror -Wextra -g

all: obj $(BSM_TOOLS_LIB) $(NAME)

obj:
	mkdir -p $(OBJDIR)/ops
	mkdir -p $(OBJDIR)/fsm_parser/action_procedures
	mkdir -p $(OBJDIR_UNIT_TESTS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(FLAGS) $(BSM_TOOLS_INC) -I $(INCDIR) -o $@ -c $<

$(OBJDIR_UNIT_TESTS)/%.o: $(SRCDIR_UNIT_TESTS)/%.c
	$(CC) $(FLAGS) $(BSM_TOOLS_INC) -I $(INCDIR) -o $@ -c $<

$(BSM_TOOLS_LIB):
	make -C $(BSM_TOOLS_DIR)

$(NAME): $(OBJ) $(BSM_TOOLS_LIB)
	$(CC) $(FLAGS) $(BSM_TOOLS_INC) -I $(INCDIR) -o obj/main.o -c src/main.c
	$(CC) $(FLAGS) obj/main.o $(OBJ) $(BSM_TOOLS_LNK) -o $(NAME)

unit-tests: $(OBJ_UNIT_TESTS) $(OBJ) $(BSM_TOOLS_LIB) 
	$(CC) $(FLAGS) $(OBJ_UNIT_TESTS) $(OBJ) $(BSM_TOOLS_LNK) -o $(NAME_TESTS)

clean:
	rm -rf $(OBJDIR)
	make -C $(BSM_TOOLS_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(BSM_TOOLS_DIR) fclean

re: fclean all

.PHONY: clean, fclean, re
