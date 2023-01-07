# 42_push_swap

## Description

This project involves sorting data on a stack, with a limited set of instructions, and the smallest number of moves. To make this happen, you will have to manipulate various sorting algorithms and choose the most appropriate solution(s) for optimized data sorting.

## Keywords
* Sorting algorithms
* Battery concept and handling elements
* Algorithm implementation

## Skills

* Imperative programming
* Rigor
* Unix
* Algorithms & AI

# Push_swap
Because Swap_push isn’t as natural

Summary: This project will make you sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed you’ll have to manipulate various
types of algorithms and choose the one (of many) most appropriate solution for an optimized data sorting.

Version: 5

## Introduction

The Push_swap project is a very simple and highly effective algorithm project: data will need to be sorted. You have at your disposal a set of int values, 2 stacks and a set of instructions to manipulate both stacks. Your goal ? Write a program in C called push_swap which calculates and displays on the standard output the smallest program using Push_swap instruction language that sorts the integer arguments received.
Easy?
We’ll see about that...

## Goals

To write a sorting algorithm is always a very important step in a coder’s life, because it is often the first encounter with the concept of complexity. Sorting algorithms, and their complexities are part of the classic questions discussed during job interviews. It’s probably a good time to look at these concepts because you’ll have to face them at one point. The learning objectives of this project are rigor, use of C and use of basic algorithms. Especially looking at the complexity of these basic algorithms. Sorting values is simple. To sort them the fastest way possible is less simple, especially because from one integers configuration to another, the most efficient sorting algorithm can differ.

## General Instructions
* This project will only be corrected by actual human beings. You are therefore free to organize and name your files as you wish, although you need to respect some requirements listed below.
* The executable file must be named push_swap.
* You must submit a Makefile. That Makefile needs to compile the project and must contain the usual rules. It can only recompile the program if necessary.
* If you are clever, you will use your library for this project, submit also your folder libft including its own Makefile at the root of your repository. Your Makefile will have to compile the library, and then compile your project.
* Global variables are forbidden.
* Your project must be written in C in accordance with the Norm.
* You have to handle errors in a sensitive manner. In no way can your program quit in an unexpected manner (Segmentation fault, bus error, double free, etc).
* Neither program can have any memory leaks.

### Within your mandatory part you are allowed to use the following functions:
* write
* read
* malloc
* free
* exit

## Mandatory part
### Game rules
* The game is composed of 2 stacks named a and b.
* To start with:
  - the stack a contains a random amount of negative and/or positive numbers which cannot be duplicated.
  - b is empty
* The goal is to sort in ascending order numbers into stack a.
* To do this you have the following operations at your disposal:

sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).

sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).

ss : sa and sb at the same time.

pa : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.

pb : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.

ra : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.

rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.

rr : ra and rb at the same time.

rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.

rrb : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.

rrr : rra and rrb at the same time.

### Example
To illustrate the effect of some of these instructions, let’s sort a random list of integers. In this example, we’ll consider that both stack are growing from the right.

### The “push_swap” program
* You have to write a program named push_swap which will receive as an argument the stack a formatted as a list of integers. The first argument should be at the top of the stack (be careful about the order).
* The program must display the smallest list of instructions possible to sort the stack a, the smallest number being at the top.
* Instructions must be separated by a ’\n’ and nothing else.
* The goal is to sort the stack with the minimum possible number of operations. During defence we’ll compare the number of instructions your program found with a maximum number of operations tolerated. If your program either displays a list too big or if the list isn’t sorted properly, you’ll get no points.
* If no parameters are specified, the program must not display anything and give the prompt back
* In case of error, you must display Error followed by a ’\n’ on the standard error. Errors include for example: some arguments aren’t integers, some arguments are bigger than an integer, and/or there are duplicates.

During the defence we’ll provide a binnary to properly check your program. It will work as follows:
```
$>ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
6
$>ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG
OK
$>
```
If the program checker_OS displays KO, it means that your push_swap came up with a list of instructions that doesn’t sort the list. The checker_OS program is available in the resources of the project on the intranet. You can find in the bonus section of this document a description of how it works.

# Bonus part
We will look at your bonus part if and only if your mandatory part is EXCELLENT. This means that your must complete the mandatory part, beginning to end, and your error management needs to be flawless, even in cases of twisted or bad usage. If that’s not the case, your bonuses will be totally IGNORED. The Push_swap project lends itself little to the creation of bonus due to its simplicity. However, how about creating your own checker?

## The “checker” program
* Write a program named checker, which will get as an argument the stack a formatted as a list of integers. The first argument should be at the top of the stack (be careful about the order). If no argument is given checker stops and displays nothing.
* checker will then wait and read instructions on the standard input, each instruction will be followed by ’\n’. Once all the instructions have been read, checker will execute them on the stack received as an argument.
* If after executing those instructions, stack a is actually sorted and b is empty, then checker must display "OK" followed by a ’\n’ on the standard output. In every other case, checker must display "KO" followed by a ’\n’ on the standard output.
* In case of error, you must display Error followed by a ’\n’ on the standard error. Errors include for example: some arguments are not integers, some arguments are bigger than an integer, there are duplicates, an instruction don’t exist and/or is incorrectly formatted.

> Thanks to the checker program, you will be able to check if the list of instructions you’ll generate with the program push_swap is actually sorting the stack properly.

> You DO NOT have to reproduce the exact same behavior as the binary we are giving to you. It is mandatory to manage the errors but it is up to you how you decide to parse the arguments.

# Submission and peer correction
Submit your work on your GiT repository as usual. Only the work on your repository will be graded. Good luck to all!
