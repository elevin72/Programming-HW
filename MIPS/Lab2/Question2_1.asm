.data
arr: .byte -47,27,17,49,-36,1,-23,48

.text 
#load information about the array
la $s0, arr # $t0 will be out array pointer
li $s2, 8 # $s2 = size
lb $a0, ($s0) # 0 not important(???) $a0 = max
li $s3, 1 # $s3 = counter
loop:
# we always want our counter less than or equal to $s2. if $as2 is less than counter($s3), stop loop.
slt $t0, $s2, $s3
bne $t0, $zero, end
addi $s3, $s3, 1 #increment the counter by 1
addi $s0, $s0, 1 #increment array pointer
lb $t1, 0($s0) #take next val in array
slt $t0, $a0, $t1 #is current max less than next val?
beq $zero, $t0, loop #if no, branch to beginning of loop
addi $a0, $t1, 0  # if yes, set max to new value in $t1
j loop
end:
addi $v0, $0, 1
syscall




