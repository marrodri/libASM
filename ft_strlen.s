

; start with this exercise

section .text
		global ft_strlen


ft_strlen:
		mov rbx, 0
_loopcount:
		inc rdi
		inc rbx
		mov cl,[rdi]
		cmp cl, 0
		jne _loopcount
		
		mov rax, rbx
		ret
