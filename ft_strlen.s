

; start with this exercise

section .text
		global ft_strlen


ft_strlen:
		mov rbx, 0
		; mov cl, [rdi]
		; cmp cl, 0
_loopcount:
		mov cl, [rdi]
		cmp cl, 0
		je _exit
		inc rdi
		inc rbx
		jmp _loopcount
_exit:
		mov rax, rbx
		ret
