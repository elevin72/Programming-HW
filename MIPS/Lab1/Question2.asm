.data 
call: .word  10
floor: .word -99
ceiling: .word 99


.text

addi $a1, $a1, -99
addi $a2, $a2, 99

Loop:
#addi $v0, $v0, 1
#syscall
li $v0, 5
syscall
beq $v0, $zero, End
#blt $v0, $a1, Else
slt $t0, $v0, $a1
bne $t0, $zero, Else
#bgt $v0, $a2, Else
sgt $t0, $v0, $a2 
bne $t0, $zero, Else
add $a0, $a0, $v0
Else:
j Loop
End:
li $v0, 1
syscall

