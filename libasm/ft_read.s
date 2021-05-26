		section .text
		global _ft_read
		extern ___error

_ft_read:
		mov rax, 0x2000003
		syscall
		jc _errore
		ret

_errore:
		mov r10, rax 
		call ___error
		mov [rax], r10
		mov rax, -1
		ret