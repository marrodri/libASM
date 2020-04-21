

section .text
		global ft_strcpy

ft_strcpy:
		push rdi ;save the dest parameter
_loopcopy:
		;just in case:change cl for another reg. 
		mov cx,[rsi]
		mov [rdi], cx
		cmp cx, 0
		je _exit
		inc rdi ; dest
		inc rsi ; src
		jmp _loopcopy
_exit:
		pop rax
		ret