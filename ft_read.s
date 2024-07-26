global	ft_read
extern	__errno_location

ft_read:
	mov		rax, 0 ; 0 est le syscall pour read
	syscall

	cmp rax, 0 ; pour check l'erreur
	jl error
	ret

error:
	neg		rax
	mov		rdi, rax
	call	__errno_location
	mov		[rax], rdi
	mov		rax, -1
	ret