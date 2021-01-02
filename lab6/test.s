# CBLOCK BEGIN	
#	I'm level 1 test.
# CBLOCK END
# CLINE START: No more compilation error.

	.text
	.section	.rodata
STR0:
	.string "%c"
STR1:
	.string "%c\n"
STR2:
	.string "a is: %d\n"
STR3:
	.string "result is: %d\n"
STR4:
	.string "Have fun: %d\n"

	.text
	.globl	main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	movl	$0, -4(%ebp)
	subl	$4, %esp
	movl	$0, -8(%ebp)
	subl	$4, %esp
	pushl	$10
	popl	%eax
	movl	%eax, -4(%ebp)
	pushl	$10
	popl	%eax
	movl	%eax, -8(%ebp)
	movl	$0, -12(%ebp)
	subl	$4, %esp
	leal	-12(%ebp), %eax
	pushl	%eax
	subl	$12, %ebp
	pushl	$STR0
	call	scanf
	addl	$12, %ebp
	addl	$8, %esp
	pushl	-12(%ebp)
	subl	$12, %ebp
	pushl	$STR1
	call	printf
	addl	$12, %ebp
	addl	$8, %esp
WBG0:
	pushl	-4(%ebp)
	pushl	$0
	popl	%eax
	popl	%ebx
	cmpl	%eax, %ebx
	jle	IFL0
	pushl	$1
	jmp	IFL1
IFL0:
	pushl	$0
IFL1:
	pushl	-4(%ebp)
	pushl	$10
	popl	%eax
	popl	%ebx
	cmpl	%eax, %ebx
	jge	IFL2
	pushl	$1
	jmp	IFL3
IFL2:
	pushl	$0
IFL3:
	popl	%eax
	popl	%ebx
	addl	%eax, %ebx
	movl	$2, %eax
	cmpl	%ebx, %eax
	jne	IFL4
	pushl	$1
	jmp	IFL5
IFL4:
	pushl	$0
IFL5:
	pushl	-4(%ebp)
	pushl	$100
	popl	%ebx
	popl	%eax
	cltd
	idivl	%ebx
	pushl	%edx
	pushl	$0
	popl	%eax
	popl	%ebx
	cmpl	%eax, %ebx
	jne	IFL6
	pushl	$1
	jmp	IFL7
IFL6:
	pushl	$0
IFL7:
	popl	%eax
	popl	%ebx
	addl	%eax, %ebx
	movl	$0, %eax
	cmpl	%ebx, %eax
	je	IFL8
	pushl	$1
	jmp	IFL9
IFL8:
	pushl	$0
IFL9:
	popl	%eax
	cmpl	$1, %eax
	jne	WED0
	pushl	$1
	popl	%ebx
	subl	%ebx,-4(%ebp)
	pushl	-4(%ebp)
	subl	$12, %ebp
	pushl	$STR2
	call	printf
	addl	$12, %ebp
	addl	$8, %esp
	movl	$0, -16(%ebp)
	subl	$4, %esp
	pushl	$10
	popl	%eax
	movl	%eax, -16(%ebp)
	pushl	-16(%ebp)
	popl	%ebx
	addl	%ebx,-8(%ebp)
	pushl	-8(%ebp)
	pushl	$120
	popl	%eax
	popl	%ebx
	cmpl	%eax, %ebx
	jge	IFL10
	pushl	$1
	jmp	IFL11
IFL10:
	pushl	$0
IFL11:
	popl	%eax
	cmp	$1, %eax
	jne	IEL00
	pushl	-8(%ebp)
	subl	$16, %ebp
	pushl	$STR3
	call	printf
	addl	$16, %ebp
	addl	$8, %esp
	movl	$0, -20(%ebp)
	subl	$4, %esp
	pushl	$10
	popl	%eax
	movl	%eax, -20(%ebp)
	pushl	$0
	popl	%eax
	movl	%eax, -24(%ebp)
FBG0:
	subl	$4, %esp
	pushl	-24(%ebp)
	pushl	-20(%ebp)
	popl	%eax
	popl	%ebx
	cmpl	%eax, %ebx
	jge	IFL12
	pushl	$1
	jmp	IFL13
IFL12:
	pushl	$0
IFL13:
	popl	%eax
	cmpl	$1, %eax
	jne	FED0
	pushl	-24(%ebp)
	subl	$24, %ebp
	pushl	$STR4
	call	printf
	addl	$24, %ebp
	addl	$8, %esp
	pushl	$1
	popl	%ebx
	addl	%ebx,-24(%ebp)
	jmp	FBG0
FED0:
	addl	$4, %esp
	addl	$4, %esp
IEL00:
	addl	$4, %esp
	jmp	WBG0
WED0:
	addl	$4, %esp
	addl	$4, %esp
	addl	$4, %esp
	popl	%ebp
	movl	$0, %eax
	ret
	.section	.note.GNU-stack,"",@progbits

