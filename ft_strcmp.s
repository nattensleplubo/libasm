section .text
	global ft_strcmp

ft_strcmp:
	xor	rcx, rcx

loop:
	movzx	rax, byte [rdi + rcx]
	movzx	rdx, byte [rsi + rcx]
	cmp		al, dl
	jnz		return
	test	al, al					; teste si al == 0 -> comme cmp al, 0
	jz		check_end
	inc		rcx
	jmp		loop

check_end:
	test	dl, dl
	jnz		return
	xor		rax, rax
	ret

return:
	sub rax, rdx
	ret