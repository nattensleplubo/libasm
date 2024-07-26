section .text
	global	ft_strdup
	extern	malloc
	extern	ft_strlen
	extern	ft_strcpy
	extern	__errno_location

ft_strdup:
	call	ft_strlen	; en gros va faire ft_strlen(rdi) ou ducoup rdi est encore *s
	push	rdi			; rdi contient *s, on la push dans la pile pour pas la perdre
	inc		rax			; rax contient la valeur de retour de ft_strlen, on l'increment pour le '\0'
	mov		rdi, rax	; rdi sera envoye a malloc donc on donne a rdi la valeur de retour de strlen
	call	malloc		; -> equivalant de malloc(rdi) ou rdi est la valeur de retour de ft_strlen
	cmp		rax, 0		; rax est la valeur de retour donc on regarde si c'est 0 ou pas
	jz		error		; Jump If Zero -> On va dans la partie error si ca fail
	mov		rdi, rax	; Sinon on met rax dans rdi pour l'utiliser dans ft_strcpy
	pop		rsi			; on met *s dans rsi (rsi est le deuxieme argument)
	call	ft_strcpy	; ducoup vient copier rsi dans rdi
	ret					; return rax

error:
	neg		rax
	mov		rdi, rax	; On met la valeur de retour dans rdi pour errno_location
	call	__errno_location
	mov		[rax], rdi
	mov		rax, -1
	ret
