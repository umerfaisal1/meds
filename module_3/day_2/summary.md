# Day 2

## R type instructions

In r type instructions an arithematic operation is performed on data in two
registers and the result is also stored in a register.

## I type instructions

I type instruction uses a 12-bit signed immediate. You do an arithematic
operation between a regitser and an immediate value and store the result in a
register.

## Load/Store instructions

You can use lw and sw to load and store data in the data memory.

## Little Endian

Little Endian means that the least significant byte is stored at the lower
address. RISC-V is byte addressable.

## Exercises

# Exercise 1

    li t0, 12 # b = 12
    li t1, 64 # c = 64

    slli t2, t0, 3     # t2 = b * 8
    srli t3, t1, 2     # t3 = c / 4

    sub t4, t2, t3     # t4 = (b*8) - (c/4)

# Exercise 2

    li t0, 0xDEADBEEF      # Original value

    # -------------------------
    # Lower byte (0xEF)
    # -------------------------
    andi t1, t0, 0xFF

    li a0, 1               # print integer
    mv a1, t1
    ecall

    # -------------------------
    # Second byte (0xBE)
    # -------------------------
    srli t2, t0, 8
    andi t2, t2, 0xFF

    li a0, 1
    mv a1, t2
    ecall

    # -------------------------
    # Upper half-word (0xDEAD)
    # -------------------------
    srli t3, t0, 16
    li t4, 0xFFFF
    and t3, t3, t4

    li a0, 1
    mv a1, t3
    ecall

    # Exit
    li a0, 10
    ecall

# Exercise 3

.data array: .word 5, 10, 15, 20, 25, 30, 35, 40

.text .globl main

main: la t0, array # Address of the array li t1, 8 # Number of elements li t2, 0

# Sum = 0

loop: beq t1, zero, done

    lw t3, 0(t0)      # Load current element
    add t2, t2, t3    # sum += element

    addi t0, t0, 4    # Move to next word (4 bytes)
    addi t1, t1, -1   # Decrement counter
    j loop

done:

    li a0, 1 # Print integer mv a1, t2 ecall

    li a0, 10         # Exit
    ecall
