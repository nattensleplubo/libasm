global ft_strlen

ft_strlen:
    xor rcx, rcx

loop:
    cmp byte [rdi + rcx], 0
    jz  return
    inc rcx
    jmp loop

return:
    mov rax, rcx
    ret