.data
arr: .word 8,4,7,5,10,3,2,1,9,6
space: .byte ' '

.text
li $a1 10 # array size
la $a0 arr #array location

addi $s2 $a1 -1 #Limit of loop is 1 less than array size
loopStart:
beq $s0 $s2 print #s0 is j, (outer loop)
bne $s1 $s2 swapTest #s1 is i, (inner loop)
addi $s0 $s0 1 # j++
addi $s1 $0 0 # i = 0 (restart inner loop)
j loopStart
swapTest:
sll $s1, $s1, 2
add $t0, $a0, $s1 # pointer arithmetic. $t0 now contains address of (arr+i)
lw $t1, 0($t0) #load current number in array
lw $t2, 4($t0) #load next number in array
slt $t3, $t2, $t1 #are they in the right order?
bne $t3, $0, swap
increment:
srl $s1, $s1, 2
addi $s1, $s1, 1
j loopStart

swap: #store the numbers in the opposite way they came in
sw $t2 ($t0)
sw $t1 4($t0)
j increment #return to increment the loop before looping again

print:
addi $s0, $a0, 0 # save array location in $s1. $a0 needs to be used for syscall-ing
printLoop:
beq $a1, $a2, end # if size == counter then branch to end
lw $a0, ($s0) #load current word of array
addi $s0, $s0, 4 #increment array
li $v0, 1 #set $v0 to print integer
syscall 
li $v0, 4 # set $v0 to print string
la $a0, space #load address of space
syscall
addi $a2, $a2, 1 #increment counter
j printLoop
end:



