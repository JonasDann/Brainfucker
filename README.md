brainfuck
=========

Brainfuck interpreter implemented in C

Usage
-----

The programm has one argument that is the file which contains the brainfuck code to implement.

Brainfuck
---------

Brainfuck is an esoteric programming language noted for its extreme minimalism. The language consists of only eight simple commands and an instruction pointer. It is a Turing tarpit, designed to challenge and amuse programmers, and was not made to be suitable for practical use. It was created in 1993 by Urban Müller.

Code:

| token | meaning |
| ----- | ------- |
| > | increment the data pointer (to point to the next cell to the right). |
| < | decrement the data pointer (to point to the next cell to the left). |
| + | increment (increase by one) the byte at the data pointer. |
| - | decrement (decrease by one) the byte at the data pointer. |
| . | output the byte at the data pointer. |
| , | accept one byte of input, storing its value in the byte at the data pointer. |
| [ | if the byte at the data pointer is zero, then instead of moving the instruction pointer forward to the next command, jump it forward to the command after the matching ] command. |
| ] | if the byte at the data pointer is nonzero, then instead of moving the instruction pointer forward to the next command, jump it back to the command after the matching [ command. |

Compilation
-----------

**Linux:**

To compile under linux you have to link it with the ncurses libary (gcc main_linux.c -lncurses) that has to be installed on the computer.

**Windows:**

To compile under windows just compile the main_windows.c. The windows version uses the standard conio.h header.

Planned features:
-----------------

 - Ook interpreter
 - Ook to brainfuck compiler and other way around
