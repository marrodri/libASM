

section .text
		global ft_write
		extern ___error

ft_write:
		mov rax, 1
		syscall
		cmp rax,0
		jl _error_handling
		mov rax, rdx
		ret
_error_handling:
		call ___error
		mov rax, -1
		ret