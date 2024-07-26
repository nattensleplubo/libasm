section .text
	global	ft_write
	extern	__errno_location

ft_write:
	mov		rax, 1 ; 1 is syscall for write.
	syscall

	cmp		rax, 0 ; checks for error
	jl		error
	ret

error:
	neg		rax ; parce que il donne la valeur en negatif donc on la negativise passke sinon c pas bon
	mov		rdi, rax
	call	__errno_location
	mov		[rax], rdi ; mettre entre [] veut dire l'addresse, donc on met rdi dans l'adrresse de errno
	mov		rax, -1
	ret