

#include <stdio.h>
#include <string.h>
#include "../../includes/bsm.h"
#include "../spec.h"


void	print_test_stats(int green_tests, int red_tests)
{
	printf("----------------------------------------------------------------\n");
	printf(FGREEN BBLACK"%d Tests Passed\t\t"NONE, green_tests);
	printf(FRED BBLACK"%d Tests Failed\t\t"NONE, red_tests);
	printf(FPURPLE BBLACK"%.2f%% Coverage\n"NONE, green_tests * 100.0 / (green_tests + red_tests));
	printf("----------------------------------------------------------------\n\n");
}

int	main(void)
{
	int		green_tests_parse;
	int		red_tests_parse;

	int		green_tests_eval;
	int		red_tests_eval;

	green_tests_parse = 0;
	red_tests_parse = 0;

	green_tests_eval = 0;
	red_tests_eval = 0;
	
	printf("\n\nBISTROMATIC UNIT TESTS\n");

	/*
	**	PARSER UNIT TESTS
	*/
	printf("----------------------------------------------------------------\n\n\n");
	printf(FYELLOW BBLACK"* PARSER UNIT TESTS *\t\t\tparse_arith_expr()\n"NONE);
	printf("----------------------------------------------------------------\n\n");

	run_parse_spec("1+2+3", "1 2 + 3 +", 5, 1, &green_tests_parse, &red_tests_parse);
	run_parse_spec("1*2/3", "1 2 * 3 /", 5, 2, &green_tests_parse, &red_tests_parse);
	run_parse_spec("3--5", "3 5 # -", 4, 3, &green_tests_parse, &red_tests_parse);
	run_parse_spec("3-5", "3 5 -", 3, 4, &green_tests_parse, &red_tests_parse);
	run_parse_spec("3-+++----5", "3 5 # # # # -", 10, 5, &green_tests_parse, &red_tests_parse);
	run_parse_spec("3-5", "3 5 -", 3, 6, &green_tests_parse, &red_tests_parse);
	run_parse_spec("3*-5", "3 5 # *", 4, 7, &green_tests_parse, &red_tests_parse);
	run_parse_spec("(-123)*((-5))", "123 # 5 # *", 13, 8, &green_tests_parse, &red_tests_parse);
	run_parse_spec("-123*((-5))", "123 # 5 # *", 11, 9, &green_tests_parse, &red_tests_parse);
	run_parse_spec("(1-3)*((-5))/(7+23)", "1 3 - 5 # * 7 23 + /", 19, 10, &green_tests_parse, &red_tests_parse);
	run_parse_spec("", "", 0, 11, &green_tests_parse, &red_tests_parse);
	run_parse_spec("(((((5)))))", "5", 11, 12, &green_tests_parse, &red_tests_parse);
	run_parse_spec("(((((5)))))*-5", "5 5 # *", 14, 13, &green_tests_parse, &red_tests_parse);
	run_parse_spec("---(3-1)*2", "3 1 - # # # 2 *", 10, 14, &green_tests_parse, &red_tests_parse);
	run_parse_spec("2---(3-1)*2", "2 3 1 - # # 2 * -", 11, 15, &green_tests_parse, &red_tests_parse);
	// run_parse_spec("--++-6(12)", "(null)", 10, 16, &green_tests_parse, &red_tests_parse);
	run_parse_spec("--++-6*12", "6 # # # 12 *", 9, 17, &green_tests_parse, &red_tests_parse);
	run_parse_spec("1--++-6*12", "1 6 # # 12 * -", 10, 18, &green_tests_parse, &red_tests_parse);
	run_parse_spec("-(12-(4*32))", "12 4 32 * - #", 12, 19, &green_tests_parse, &red_tests_parse);
	// run_parse_spec("-(12-(4*32)", "syntax error", 11, 20, &green_tests_parse, &red_tests_parse);	
	run_parse_spec("-(x@-(;*\!@))", "x@ ; \!@ * - #", 13, 21, &green_tests_parse, &red_tests_parse);
	run_parse_spec("(4*32)", "4 32 *", 6, 22, &green_tests_parse, &red_tests_parse);
	// run_parse_spec("(4*32))", "syntax error", 7, 23, &green_tests_parse, &red_tests_parse);
	run_parse_spec("-834*-938", "834 # 938 # *", 9, 24, &green_tests_parse, &red_tests_parse);
	run_parse_spec("f++f+f", "f f + f +", 6, 25, &green_tests_parse, &red_tests_parse);
	run_parse_spec("-834*-938", "834 # 938 # *", 9, 26, &green_tests_parse, &red_tests_parse);
	run_parse_spec("((-834)*((-938)))", "834 # 938 # *", 17, 27, &green_tests_parse, &red_tests_parse);
	// run_parse_spec("((-834)/*((-938)))", "syntax error", 18, 28, &green_tests_parse, &red_tests_parse);
	// run_parse_spec("((-834)+*((-938)))", "syntax error", 18, 29, &green_tests_parse, &red_tests_parse);
	run_parse_spec("((-834)*+((-938)))", "834 # 938 # *", 18, 30, &green_tests_parse, &red_tests_parse);
	run_parse_spec("", "", 0, 31, &green_tests_parse, &red_tests_parse);
	run_parse_spec("1+1", "1 1 +", 3, 32, &green_tests_parse, &red_tests_parse);
	// run_parse_spec(")1+2", "syntax error", 4, 33, &green_tests_parse, &red_tests_parse);
	run_parse_spec("+-----++++------(((((1+2)))))", "1 2 + # # # # # # # # # # #", 29, 34, &green_tests_parse, &red_tests_parse);
	// run_parse_spec("1+*1", "syntax error", 4, 35, &green_tests_parse, &red_tests_parse);
	// run_parse_spec("((1+2)*2", "syntax error", 4, 36, &green_tests_parse, &red_tests_parse);
	// run_parse_spec("(((-4-+-22)))*123+", "syntax error", 18, 37, &green_tests_parse, &red_tests_parse);
	run_parse_spec("(((-4-+-22)))*123", "4 # 22 # - 123 *", 17, 38, &green_tests_parse, &red_tests_parse);
	// run_parse_spec("((-4-+-22)))*123", "syntax error", 16, 39, &green_tests_parse, &red_tests_parse);
	// run_parse_spec("(()", "syntax error", 3, 40, &green_tests_parse, &red_tests_parse);
	run_parse_spec("((()))", "", 6, 41, &green_tests_parse, &red_tests_parse);
	run_parse_spec("(((---+++--(--(5+10)))))", "5 10 + # # # # # # #", 24, 42, &green_tests_parse, &red_tests_parse);
	// run_parse_spec("*1+2", "syntax error", 4, 43, &green_tests_parse, &red_tests_parse);
	// run_parse_spec("(12)3", "syntax error", 5, 44, &green_tests_parse, &red_tests_parse);
	run_parse_spec("(12)*(12)", "12 12 *", 9, 45, &green_tests_parse, &red_tests_parse);
	run_parse_spec("(1+2)/(3-4)", "1 2 + 3 4 - /", 11, 46, &green_tests_parse, &red_tests_parse);
	run_parse_spec("123456789123456789123456789+3", "123456789123456789123456789 3 +", 29, 47, &green_tests_parse, &red_tests_parse);
	run_parse_spec("1%-2", "1 2 # %", 4, 48, &green_tests_parse, &red_tests_parse);
	run_parse_spec("1", "1", 1, 49, &green_tests_parse, &red_tests_parse);
	run_parse_spec("-1", "1 #", 2, 50, &green_tests_parse, &red_tests_parse);

	// input shorter than expected
	run_parse_spec("-1", "1 #", 5, 51, &green_tests_parse, &red_tests_parse);
	// input longer than expected
	// run_parse_spec("1+2+3", "syntax error", 4, 52, &green_tests_parse, &red_tests_parse);
	run_parse_spec("1+2+3", "1 2 +", 3, 53, &green_tests_parse, &red_tests_parse);
	run_parse_spec("1+1", "1 1 +", 10, 54, &green_tests_parse, &red_tests_parse);
	run_parse_spec("", "", 10, 55, &green_tests_parse, &red_tests_parse);
	run_parse_spec("123", "", 0, 56, &green_tests_parse, &red_tests_parse);
	run_parse_spec("(1+2)\n", "1 2 +", 5, 57, &green_tests_parse, &red_tests_parse);
	//	echo "" | ./calc "" 0				EMPTY STRING+BASE SEGFAULT
	//	echo "" | ./calc "sfesfs" 0			EMPTY STRING SEGFAULT
	//	echo "s" | ./calc "ss" 1            DUPLICATE SYMBOLS IN BASE
	//	echo "\na" | ./calc "\na" 2

	/*
	**	EVAL UNIT TESTS
	*/

	printf(FYELLOW BBLACK"\n\n* EVAL UNIT TESTS *\t\t\teval_arith_expr()\n"NONE);
	printf("----------------------------------------------------------------\n\n");

	run_eval_spec("1 1 +", "2", "0123456789", 1, &green_tests_eval, &red_tests_eval);
	run_eval_spec("123 456 *", "56088", "0123456789", 2, &green_tests_eval, &red_tests_eval);
	run_eval_spec("123456789123456789987654321 123456789123456789987654321 *", "15241578780673678759487883219326322200731595789971041", "0123456789", 3, &green_tests_eval, &red_tests_eval);
	run_eval_spec("2 3 + 10 *", "50", "0123456789", 4, &green_tests_eval, &red_tests_eval);
	run_eval_spec("2 1 - 3 + 10 *", "40", "0123456789", 5, &green_tests_eval, &red_tests_eval);
	run_eval_spec("1 10 - #","9", "0123456789", 6, &green_tests_eval, &red_tests_eval);
	run_eval_spec("1 100 -", "-99", "0123456789", 7, &green_tests_eval, &red_tests_eval);
	run_eval_spec("500 100 %", "0", "0123456789", 8, &green_tests_eval, &red_tests_eval);
	run_eval_spec("387483 487834 29384 * - 2 +", "-14334126771", "0123456789", 9, &green_tests_eval, &red_tests_eval);
	run_eval_spec("1 5 # 302938 / 34 % +", "1", "0123456789", 10, &green_tests_eval, &red_tests_eval);
	run_eval_spec("1 ff *", "ff", "0123456789abcdef", 11, &green_tests_eval, &red_tests_eval);
	run_eval_spec("1000 1000 * ", "1000000", "01", 12, &green_tests_eval, &red_tests_eval);
	run_eval_spec("10 3 %", "1", "0123456789", 14, &green_tests_eval, &red_tests_eval);
	run_eval_spec("10 3 /", "3", "0123456789", 15, &green_tests_eval, &red_tests_eval);
	run_eval_spec("1 2 - 3 + 10 *", "20", "0123456789", 16, &green_tests_eval, &red_tests_eval);
	run_eval_spec("1 2 +", "3", "0123456789", 17, &green_tests_eval, &red_tests_eval);
	run_eval_spec("3 6 +", "9", "0123456789", 18, &green_tests_eval, &red_tests_eval);
	run_eval_spec("6 12 # # #", "syntax error", "0123456789", 19, &green_tests_eval, &red_tests_eval);
	run_eval_spec("6 # # 12 *", "72", "0123456789", 20, &green_tests_eval, &red_tests_eval);
	run_eval_spec("--++-6(12)", "syntax error", "0123456789", 21, &green_tests_parse, &red_tests_parse);

	
	printf(FYELLOW BBLACK"\n* SUMMARY PARSER UNIT TESTS *\n"NONE);
	print_test_stats(green_tests_parse, red_tests_parse);

	printf(FYELLOW BBLACK"\n* SUMMARY EVAL UNIT TESTS *\n"NONE);
	print_test_stats(green_tests_eval, red_tests_eval);
	

	
	return (0);
}
