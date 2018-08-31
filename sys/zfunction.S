	.text
	.globl zfunction
zfunction:
	pushl	%ebp
	movl	%esp, %ebp
	movl	8(%ebp), %eax
	andl	$0xFFC03FFF, %eax
	shll	$4, %eax
	popl	%ebp
	ret
	
