section .text
		global ft_strdup
		extern malloc
		extern error
		extern ft_strlen
		extern ft_strcpy
ft_strdup:
		call ft_strlen ;the string is called in rdi then the val is returned to rax
		push rdi ;push the string in to the stack
		mov r8, rax ;store the the strlen val to r8
		inc r8  ; increment by 1 to the strlen val for null byte
		mov rdi, r8 ;store the strlen val to rdi for the malloc first param
		call malloc ;calling malloc based from the rdi val
		mov rdi, rax ;copy the allocated string to rdi reg( the first param of ft_strcpy) 
		cmp rax, 0
		jle _strdup_error ;jump if the rax is less or equal to 0
		pop rsi ; pop the string to the rsi reg(the second param of ft_strcpy)
		call ft_strcpy
		ret
_strdup_error:
		xor rax, rax
		call error
		ret
