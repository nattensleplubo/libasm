global ft_strcpy
; rdi => dest
; rsi => source

ft_strcpy:
    xor rcx, rcx

loop:
    mov al, [rsi + rcx]
	mov byte [rdi + rcx], al
    cmp al, 0
    jz  return
    inc rcx
    jmp loop

return:
    mov rax, rdi
    ret