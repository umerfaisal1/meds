# Day 3 Summary

We can implement if/else, for loop and while loop in assembly using conditional
branch instructions.

There are also unconditional jumps that will jump the program always without
depending on any conditon.

### Exercise 1

.data posMsg: .asciz "Positive\n"

negMsg: .asciz "Negative\n"

zeroMsg: .asciz "Zero\n"

.text main:

    li a7, 5
    ecall 
    mv t0, a0
    beq t0, x0, zero
    blt t0, x0, negative

    positive: 
    la a0, posMsg 
    li a7, 4 
    ecall
    j end

    negative: 
    a a0, negMsg 
    li a7, 4 
    ecall
    j end

    zero: 
    la a0, zeroMsg 
    li a7, 4 
    ecall

    end: 
    li a7, 10 
    ecall

### Exercise 2

.text main: # Read N li a7, 5 ecall mv t0, a0 # t0 = N

    li t1, 1           # result = 1

loop: beq t0, x0, done # if N == 0, finish

    mul t1, t1, t0     # result *= N
    addi t0, t0, -1    # N--
    j loop

done: mv a0, t1 # print result li a7, 1 ecall

    li a7, 10          # exit
    ecall

### Exercise 3

.data array: .word 10, 20, 30, 40, 50, 60 size: .word 6 space: .asciz " "

.text main: # Load array address la t0, array

    # Load size
    la t1, size
    lw t2, 0(t1)          # t2 = size

    # left = 0
    li t3, 0

    # right = size - 1
    addi t4, t2, -1

reverse_loop: bge t3, t4, print_array

    # Address of array[left]
    slli t5, t3, 2
    add t5, t0, t5

    # Address of array[right]
    slli t6, t4, 2
    add t6, t0, t6

    # Swap
    lw t1, 0(t5)
    lw t2, 0(t6)

    sw t2, 0(t5)
    sw t1, 0(t6)

    # left++
    addi t3, t3, 1

    # right--
    addi t4, t4, -1

    j reverse_loop

print_array: la t0, array li t3, 0

    # Reload size
    la t1, size
    lw t2, 0(t1)

print_loop: bge t3, t2, exit

    slli t4, t3, 2
    add t5, t0, t4
    lw a0, 0(t5)

    li a7, 1          # print integer
    ecall

    la a0, space
    li a7, 4          # print string
    ecall

    addi t3, t3, 1
    j print_loop

exit: li a7, 10 ecall

### Exercise 4:

.data array: .word 5, 10, 15, 20, 25, 30, 35, 40 size: .word 8

.text main: # Read target li a7, 5 ecall mv t0, a0 # t0 = target

    la t1, array       # base address of array

    la t2, size
    lw t2, 0(t2)       # t2 = size

    li t3, 0           # low = 0
    addi t4, t2, -1    # high = size - 1

search: bgt t3, t4, not_found

    # mid = (low + high) / 2
    add t5, t3, t4
    srai t5, t5, 1

    # Load array[mid]
    slli t6, t5, 2
    add t6, t1, t6
    lw t2, 0(t6)

    beq t2, t0, found
    blt t2, t0, go_right

    # high = mid - 1
    addi t4, t5, -1
    j search

go_right: # low = mid + 1 addi t3, t5, 1 j search

found: mv a0, t5 # print index li a7, 1 ecall j exit

not_found: li a0, -1 li a7, 1 ecall

exit: li a7, 10 ecall
