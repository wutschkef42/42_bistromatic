
# Starfleet Project 0: Bistromatic

## Introduction
This is the first project of the Starfleet curriculum at 42. Bistromatic is a
calculator that reads an arithmetic expression in infix notation from stdin and
it receives the input size and a charset as command-line arguments.
It writes the result to standard output.

## Requirements 
* Infinite input size
* Arbitrary base; base-size is defined through size of provided charset
* Input  base = Output base

## REMAINING TASKS
* norminette
* dry memory leaks
* unit test evaluation 
* error handling (invalid input/ syntax errors)
	* input shorter than expected -> evaluate normally
	* input longer than expected -> evaluate up to the length specfied in the
	  second command line argument
	* base charset contains duplicate characters -> deny execution
	* base charset is empty or has only 1 element -> deny execution
	* arithmetic expression bad syntax -> syntax error

