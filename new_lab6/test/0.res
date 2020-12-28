# COMMENT: int a = 1
# COMMENT: int b = 2;
# COMMENT: if(!2==3){
# COMMENT:     int a=2;
# COMMENT:     a=a+2;
# COMMENT: }
# COMMENT: while(a==b){
# COMMENT:     printf("%d", a);
# COMMENT: }

	.text
	.section	.rodata
STR0:
	.string "b"
STR1:
	.string "a"
	.text
	.globl	main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	$10
	popl	%eax
	movl	%eax, -4(%ebp)
	subl	$4, %esp
	pushl	-4(%ebp)
	popl	%eax
	cmpl	$0, %eax
	je	.BB0
	pushl	$1
	jmp	.BB1
.BB0:
	pushl	$0
.BB1:
	popl	%eax
	cmpl	$0, %eax
	je	.BB2
	pushl	$1
	jmp	.BB3
.BB2:
	pushl	$0
.BB3:
	popl	%eax
	cmp	$1, %eax
	jne	LB00
	subl	$4, %ebp
	pushl	$STR0
	call	printf
	addl	$4, %ebp
	addl	$4, %esp
	jmp	LB10
LB00:
	subl	$4, %ebp
	pushl	$STR1
	call	printf
	addl	$4, %ebp
	addl	$4, %esp
LB10:
	addl	$4, %esp
	popl	%ebp
	movl	$0, %eax
	ret
	.section	.note.GNU-stack,"",@progbits

# 0	program					child: 1
# 1	function				child: 2 3 4 9
# 2	type		VOID		child:
# 3	variable	main			child:
# 4	statement	DECL		child: 5 6
# 5	type		INTEGER		child:
# 6	assign					child: 7 8
# 7	variable	b			child:
# 8	constint	10			child:
# 9	statement	IF			child: 10 12 14
# 10	op			!			child: 11
# 11	variable	b			child:
# 12	statement	PRINTF		child: 13
# 13	conststr	b			child:
# 14	statement	PRINTF		child: 15
# 15	conststr	a			child:
