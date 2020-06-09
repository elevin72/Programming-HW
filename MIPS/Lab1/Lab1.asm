#Lab 1 for Comp Architecture
#Eli Levin 341318228

# Question 1:

.data
source: .word -47,8,16, 14,0
target: .space 32

.text
 la $a0, source
 la $a1, target
 loopstart:
 lw $t0, 0($a0)
 sw $t0, 0($a1)
 beq $t0, $zero, Else
 addi $v0, $v0, 1
 addi $a0, $a0, 4
 addi $a1, $a1, 4
 j loopstart
 Else:

# *****END QUESTION 1*****



#Question 2:

.data 
call: .word  10
floor: .word -99
ceiling: .word 99

.text

addi $a1, $a1, -99
addi $a2, $a2, 99

Loop:
li $v0, 5
syscall
beq $v0, $zero, End
slt $t0, $v0, $a1
bne $t0, $zero, Else
sgt $t0, $v0, $a2 
bne $t0, $zero, Else
add $a0, $a0, $v0
Else:
j Loop
End:
li $v0, 1
syscall

# ******* END QUESTION 2********

