.data
list: .byte 2,4,6,8
str1: .asciiz "\nd = "
str2: .asciiz "\nq = "
str3: .asciiz "\nNot a progression"

.text
la $a0 list
li $a1 4 # $a1 = size
lb $t0, ($a0) #load first byte in list
lb $t1, 1($a0) # load second byte in list
addi  $a0, $a0, 1 #increment array pointer up by 1
addi  $a1, $a1, -2
###### List of s resisters uses ########
# $s0 = isArithemtic (0 = true, 1 = false)
# $s1 = difference 
# $s2 = isGeometric (0 = true, 1 = false)
# $s3 = quotient
  
sub $s1, $t1, $t0
div $t1, $t0
mfhi $t2
bne $t2, $0, notGeometric # if division created remainder then quotient if it exists is not an integer and we dont have to check for that
mflo $s3 #if division without remainder then store quotient in $s3 and move onto loop
j loop

notGeometric:
addi $s2, $0, 1

loop:
beq $a1, $a2, print # $a2 = counter. size == counter?
lb $t0, ($a0) #load next 2 bytes
lb $t1, 1($a0)

ArithmeticCheck:
bne $s0, $0, GeoCheck
sub $t2, $t1, $t0 #get current difference
# if currentDifference == difference then its still arithemtic
beq $t2, $s1, GeoCheck
addi $s0, $s0, 1 # sequence is not arithemtic and don't check next time(s)

GeoCheck:
bne $s2, $0, continue #if is not geometric then don't do check
div $t1, $t0 #divide next 2 numbers
mfhi $t2 #check if there is a remainder
bne $t2, $0, notGeometric2 # if division created remainder then quotient if it exists is not an integer and we dont have to check for that
mflo $t2 #get the current quotient
# if currentQuotient == quotient then it's still geometric
beq $t2, $s3, continue 
notGeometric2:
addi $s2, $s2, 1 #sequence is not geometric

continue:
addi $a0, $a0, 1 # array pointer goes up one
addi $a2, $a2, 1 # counter goes up one
j loop

print:

bne $s0, $0, printQ #if it's arithemtic
li $v0, 4
la $a0, str1
syscall
li $v0, 1
addi $a0, $s1, 0
syscall

printQ:
bne $s2, $0, notEither # if it's geometric
li, $v0, 4
la $a0, str2
syscall
li $v0, 1
addi $a0, $s3, 0
syscall

notEither:
beq $s0, $0, end #check both types of sequences
beq $s2, $0, end
li $v0, 4
la $a0, str3 # not a progression
syscall

end:

