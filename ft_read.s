
section .text
		global ft_read
ft_read:
		mov rax, 0
		syscall
		cmp rax, 0
		jl _error
		ret
_error:
		mov rax, -1
		ret