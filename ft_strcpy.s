

section .text
		global ft_strcpy

ft_strcpy:

_loopcopy:
		inc rdi ; dest
		inc rsi ; src
		;just in case:change cl for another reg. 
		mov cl,[rdi]
		mov [rsi], cl
		cmp cl, 0
		jne _loopcopy

		mov rax, rsi
		ret