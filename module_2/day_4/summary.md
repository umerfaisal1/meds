# Day 4 Summary

## Memory Management

We use dynamic memory alocation to allocate a specific amount of memory at runtime for our use-case. There four dangerous mistakes that can happen when manually dealing with allocating and freeing memory. The biggest mistakes are memory leak, dangling pointer, double free buffer overflow.

## File Management

In C language we can read and write to files. We use the fopen function to open the file, fgets function is used inside a while loop to read the file line by line. It is important to close the file at the end using fclose. This is used in RISC-V memory simulators to load hex files into virtual memory.

## Command line arguments

The main function takes two arguments, argc which is the number of arguments and argv which is a character array that holds all the arguments. We have to parse these arguments in our program and deal with them.

## Debugging

GDB and Valgrind are used to debug a progam. GDB lets you put breakpoints in the program and valgrind shows you error messages about memory leaks.