
#include <stdio.h>
#include <string.h>
#include "../../includes/bsm.h"
#include "../spec.h"

void	run_parse_spec(char *input, char *expected_output, int input_size, int test_number, int *green_tests, int *red_tests)
{
	printf("Test Number\t\t\t\t%03d\n", test_number);
	printf("----------------------------------------------------------------\n");
	printf("Input\t\t\t\t\t%s\n", input);
	printf("Expected Output\t\t\t\t%s\n", expected_output);
	printf("Actual Output\t\t\t\t%s\n", bsm_infix_to_rpn(input, input_size));
	if (strcmp(bsm_infix_to_rpn(input, input_size), expected_output) == 0)
	{
		printf("\nResult");
		printf(FGREEN BBLACK"\t\t\t\t\tSUCCESS\n"NONE);
        (*green_tests)++;
    }
	else
	{
		printf("\nResult");
		printf(FRED BBLACK"\t\t\t\t\tERROR\n"NONE);
        (*red_tests)++;
    }
	printf("----------------------------------------------------------------\n\n");	
}
