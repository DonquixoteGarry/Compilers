    .bss
    .align  4
i:
    .zero   4

    .align  4
n:
    .zero   4

    .align  4
f:
    .zero   4

    .section    .rodata
STR0:
    .string "%d"
STR1:
    .string "%d\n"
#   main    
    .text
    .global main
    .type   main,@function
main:
#   scanf("%d",&n);
    pushl   $n
    pushl   $STR0
    call    scanf
    addl    $8,%esp
#   i=2;f=1;
	movl	$1, f
	movl	$2, i
#   i<=n?
jud:
    movl    i,%eax
    movl    n,%edx
    cmpl    %eax,%edx
    # edx<eax ->> out of bound 
    jl      out_bound
#   f=f*i;i=i+1;
normal:
    movl	i,%eax
    movl    f,%edx
	imull	%eax, %edx
	addl	$1,%eax
    movl    %eax,i
    movl    %edx,f
    jmp     jud
#   printf("%d\n",f);
out_bound:
    pushl   f
    pushl   $STR1
    call    printf
    addl    $8,%esp
    movl    $0,%eax
    ret

    .section    .note.GNU-stack,"",@progbits
