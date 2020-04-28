

section .text
		global ft_strcpy

ft_strcpy:
		push rsi ;save the first pointer of the src param
		push rdi ;save the first pointer of the dst param
_loopcopy: 
		mov cx,[rsi]
		mov [rdi], cx
		cmp cx, 0
		je _exit
		inc rdi ; dest
		inc rsi ; src
		jmp _loopcopy
_exit:
		pop rdi
		pop rsi
		mov rax, rdi
		ret