		section .text
		global _ft_strlen

_ft_strlen:
		mov rax, 0 			; i = 0

_start:	
		cmp BYTE [rdi + rax], 0	; str[i] == 0 ?
		je _exit				; se si, jump su exit
		inc rax					; se non uguale, incrementa di 1
		;inc rdi				; incremento valore puntatore
		jmp _start				; richiamo la funzione start

_exit:
		ret