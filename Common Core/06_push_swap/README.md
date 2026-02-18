# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    README.md                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmtur <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/07 16:36:28 by dmtur             #+#    #+#              #
#    Updated: 2026/01/07 16:40:37 by dmtur            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

This project has been created as part of the 42 curriculum by dmtur.

push_swap
Description

push_swap is a sorting algorithm project from the 42 curriculum.
The goal is to sort a stack of integers in ascending order using a limited set of stack operations, while producing the smallest possible number of moves.

The program works with two stacks:

Stack A: initially contains all input numbers

Stack B: starts empty and is used as auxiliary storage

Only specific operations are allowed (swap, push, rotate, reverse rotate), and the program must output the sequence of operations required to sort the stack.

This implementation:

Handles small inputs with specialized logic

Uses radix sort based on index assignment for larger inputs

Validates input strictly (duplicates, invalid integers, overflow)

Instructions
Compilation

To compile the project, run:

make

Usage
./push_swap 3 2 1


Example with more numbers:

./push_swap 5 2 8 1 9 3


Count the number of operations:

./push_swap 5 2 8 1 9 3 | wc -l

Cleaning
make clean     # removes object files
make fclean    # removes objects and executable
make re        # recompiles everything

Project Structure
push_swap/
├── main.c
├── parse/
│   ├── parse_args.c
│   ├── split_args.c
│   └── validate_numbers.c
├── stack/
│   ├── stack_init.c
│   ├── stack_node.c
│   ├── stack_utils.c
│   └── stack_free.c
├── operations/
│   ├── operation_swap.c
│   ├── operation_push.c
│   ├── operation_rotate.c
│   └── operation_rev_rotate.c
├── sort/
│   ├── sort_small.c
│   ├── sort_big.c
│   ├── indexing.c
│   └── sort_dispatcher.c
├── utils/
│   ├── is_sorted.c
│   └── errors.c
├── libft/
├── push_swap.h
├── Makefile
└── README.md

Resources
Articles & Documentation

42 Subject PDF – push_swap

Push_swap overview and basic strategy:
https://www.youtube.com/watch?v=XiuSW_mEn7g

Push_swap full playlist (step-by-step explanations):
https://www.youtube.com/watch?v=rO-JjtgpX2U&list=PLdqJJidIgFEjLfbSaqLlZr70DLgx5IFLF

Radix sort explained in depth:
https://www.youtube.com/watch?v=OaG81sDEpVk&t=2945s

Advanced push_swap optimization discussion:
https://www.youtube.com/watch?v=wRvipSG4Mmk&t=2042s

AI Usage Disclosure

AI tools (ChatGPT) were used during this project for:

Understanding algorithmic concepts (radix sort, stack strategies)

Debugging logic and Makefile issues

Code review and refactoring discussions

Assistance in structuring and writing this README

All code was written, tested, and understood by the author.
AI was used strictly as a learning and assistance tool, similar to documentation or peer discussion.

Author

Login: dmtur

Campus: 42 Barcelona

Project: push_swap

License

This project is part of the 42 school curriculum and is intended for educational purposes only.
