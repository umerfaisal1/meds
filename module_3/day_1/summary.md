### Module 3 Day 1

## About RISC-V

RISC-V has a small clean base ISA with only a few instructions that are very
easy to implement in hardware. It is also open source so no need for icensing
and NDAs.

## Rigister File

The register file has 32 registers. They are used for function arguments, stack
pointer, temporary variables, saved values, etc.

## Venus Simulator

It is a simulator in which we write our RISC-V code and we can run it and see
the values of the registers and also the value of the memory.

## ECALL

The ecall command is use to different things like printiint g something to the
console, exiting the program, etc.

### Exercise 1

    li a0, 42          # a0 = 42
    li a1, 58          # a1 = 58

    add a1, a0, a1     # a1 = 42 + 58 = 100

    li a0, 1           # ecall 1 = print integer
    ecall

    li a0, 10          # exit
    ecall

### Exercise 2

    li a0, 5           # read integer
    ecall
    add t0, a0, zero          # save first number

    li a0, 5
    ecall
    add t1, a0, zero          # save second number

    add a1, t0, t1     # sum

    li a0, 1           # print integer
    ecall

    li a0, 10
    ecall

### Exercise 3

.data msg: .asciiz "Hello MEDS!"

.text main:

    la a1, msg # address of string

    li a0, 4           # print string
    ecall

    li a0, 10
    ecall

### Exercise 4

.text main:

    li ra, 1
    li sp, 2 
    li gp, 3
    li tp, 4

    li t0, 5
    li t1, 6
    li t2, 7

    li s0, 8
    li s1, 9

    li a0, 10
    li a1, 11
    li a2, 12
    li a3, 13
    li a4, 14
    li a5, 15
    li a6, 16
    li a7, 17

    li s2, 18
    li s3, 19
    li s4, 20
    li s5, 21
    li s6, 22
    li s7, 23
    li s8, 24
    li s9, 25
    li s10, 26
    li s11, 27

    li t3, 28
    li t4, 29
    li t5, 30
    li t6, 31

    li t0, 123
    mv x0, t0          # attempt to change x0 (has no effect)

    li a0, 10
    ecall

### Exercise 5

.text main:

    li a0, 5 # Read N ecall

    mv t0, a0         # t0 = N

    addi t1, t0, 1    # t1 = N + 1
    mul t2, t0, t1    # t2 = N * (N + 1)
    srli t2, t2, 1    # Divide by 2 (logical right shift by 1)

    mv a0, t2         # Move result to a0

    li a0, 1          # Print integer
    ecall

    li a0, 10         # Exit
    ecall
