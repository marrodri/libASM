
%include "linux64.inc"

section .data
		text1 db "iteratin",10,0
		text2 db "diff",10,0
		text3 db "ENTER!!",10,0
		text4 db "finish!!",10,0

section .text
		global ft_strcmp
;rdi is the first param
;rsi is the second param

ft_strcmp:
		mov rax, 0
		; push rdi
		; push rsi
		mov r14b, [rdi]
		cmp r14b, 0
		je _diff
		; mov r9, [rdi]
		mov r15b, [rsi]
		cmp r15b, 0
		je _diff
_loopcomp:
		inc rsi
		inc rdi 
		mov r14b, [rdi]
		cmp r14b, 0
		je _diff

		mov r15b, [rsi]
		cmp r15b, 0
		je _diff

		cmp r14b, r15b
		je _loopcomp
_diff:
		mov r14b, [rdi]
		mov r15b, [rsi]
		cmp r14b, r15b
		je _equal
		jg _great
		jl _less 
_equal:
		mov rax, 0
		ret
_less:
		mov rax, -1
		ret
_great:
		mov rax, 1
		ret