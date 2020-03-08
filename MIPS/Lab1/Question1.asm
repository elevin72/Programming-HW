.data
source: .word -47,8,16,0
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