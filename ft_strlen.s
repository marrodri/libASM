
section .text
		global ft_strlen

ft_strlen:
		push rdi
		mov rbx, 0
_loopcount:
		mov cl, [rdi]
		cmp cl, 0
		je _exit
		inc rdi
		inc rbx
		jmp _loopcount
_exit:
		pop rdi
		mov rax, rbx
		ret
