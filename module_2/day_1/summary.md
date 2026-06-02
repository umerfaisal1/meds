# Module 2

## Day 1 Summary

I learned about the C programming language ad the gcc compiler and the different
flags that can be used with gcc while compiling a program. Different modules and
instructions of RISC-V can be implemented in C.

While working with hardware we should aleays use fixed width integer types, such
as uint32_t, and not use int and float because their size is platform dependent.

For hardware related work it is also neccessary to understand bitiwse operations
in C.

gcc first expands the C code, then it converts to assembly, then it creates
object files. Then it links the object files togther to create a binary.
