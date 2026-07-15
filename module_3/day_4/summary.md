# Day 3

In day 3 I learned how to implement functions and call the functions in assembly
language. Regsters a0-a7 are used for the arguments of the function and the
return value of is stored in a0.

I also learned how to do encoding and decoding of instructions in hex format.

## Exercise 1

.data array: .word 10, 20, 30, 40, 50

.text .globl main

main:

#testing the max function li a0, 15 li a1, 25 jal ra, max

    # test sum_array function
    la a0, array       # Pointer to array
    li a1, 5           # Number of elements
    jal ra, sum_array




    li a7, 10
    ecall

max: bge a0, a1, max_done mv a0, a1 max_done: ret

sum_array: mv t0, a0 # t0 = array pointer mv t1, a1 # t1 = size li t2, 0 # index
li t3, 0 # sum

loop: bge t2, t1, finish lw t4, 0(t0) add t3, t3, t4 addi t0, t0, 4 addi t2, t2,
1 j loop

finish: mv a0, t3 ret

## Exercise 2

.data

.text .globl main

main: li a0, 10 # Compute fib(10) jal ra, fib

    # Print result (55)
    li a7, 1           # Print integer
    ecall

    # Exit
    li a7, 10
    ecall

# --------------------------------------

# fib(n)

# Input : a0 = n

# Output: a0 = fib(n)

# --------------------------------------

fib: # Base cases li t0, 1 ble a0, t0, base_case

    # Create stack frame
    addi sp, sp, -16
    sw ra, 12(sp)
    sw a0, 8(sp)

    # fib(n-1)
    addi a0, a0, -1
    jal ra, fib
    sw a0, 4(sp)       # Save fib(n-1)

    # fib(n-2)
    lw a0, 8(sp)       # Restore n
    addi a0, a0, -2
    jal ra, fib

    # fib(n-1) + fib(n-2)
    lw t1, 4(sp)
    add a0, a0, t1

    # Restore and return
    lw ra, 12(sp)
    addi sp, sp, 16
    ret

base_case: ret

## Exercise 3

.data

.text .globl main

main: li a0, 5 jal ra, funcA

    # Print returned value
    li a7, 1
    ecall

    # Exit
    li a7, 10
    ecall

# --------------------------------

# funcA

# Calls funcB

# Returns funcB(a0) + 5

# --------------------------------

funcA: addi sp, sp, -8 sw ra, 4(sp) sw s0, 0(sp)

    li s0, 100          # Save a value in s0

    jal ra, funcB       # Nested call

    addi a0, a0, 5

    lw s0, 0(sp)
    lw ra, 4(sp)
    addi sp, sp, 8
    ret

# --------------------------------

# funcB

# Returns a0 * 2

# --------------------------------

funcB: addi sp, sp, -8 sw ra, 4(sp) sw s0, 0(sp)

    li s0, 200          # Modify s0 locally

    slli a0, a0, 1      # a0 = a0 * 2

    lw s0, 0(sp)
    lw ra, 4(sp)
    addi sp, sp, 8
    ret

## Exercise 4

sub x1, x2, x3 → 0x403100B3 ori x5, x6, 0xFF → 0x0FF36293 sw x7, 8(x8) →
0x00742423 beq x1, x2, +16 → 0x00208863

## Exercise 5

0x00A28233 → add x4, x5, x10 0x00500113 → addi x2, x0, 5 0xFE209CE3 → bne x1,
x2, -8
