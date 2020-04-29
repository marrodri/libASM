section .text
		global ft_write
ft_write:
		mov rax, 1
		syscall
		cmp rax,0
		jl _error
		mov rax, rdx
		ret
_error:
		mov rax, -1
		ret
