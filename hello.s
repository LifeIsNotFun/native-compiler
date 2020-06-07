.text
.globl	_main
_main:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$16, %rsp
	movl	$0, -4(%rbp)
	leaq	str(%rip), %rdi
	callq	_puts
	xorl	%ecx, %ecx
	movl	%eax, -8(%rbp)
	movl	%ecx, %eax
	addq	$16, %rsp
	popq	%rbp
	retq

str:
	.asciz	"Hello, world!"
