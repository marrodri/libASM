

section .text
		global ft_strcpy

ft_strcpy:
		; mov rax, [rdi]
		push rdi ;save the dest parameter
_loopcopy:
		;just in case:change cl for another reg. 
		mov cx,[rsi]
		mov [rdi], cx
		inc rdi ; dest
		inc rsi ; src
		cmp cx, 0
		jnz _loopcopy
		pop rax
		; mov rax, rdi
		; mov rax, rdi
_exit:
		ret