##### Exercise 1 #######
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

######## Exercise 2 #########

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

