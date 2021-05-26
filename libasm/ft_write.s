		section .text
		global _ft_write
		extern ___error

_ft_write:
		mov rax, 0x2000004 		; inserisco il codice di richiamo della funzione  da chiamare write in rax
		syscall					; chiamo la funzione di sistema inserita in rax
		jc _errore				; jump condizionato se non va a buon fine la funzione 
		ret

_errore:
		push rax
		call ___error
		pop r10
		mov [rax], r10
		mov rax, -1
		ret


