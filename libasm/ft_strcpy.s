;char	*ft_strcpy(char *dest, char *src)
;{
;	int iterator;
;
;	iterator = 0;
;	while (*(src + iterator) != 0)
;	{
;		*(dest + iterator) = *(src + iterator);
;		iterator++;
;	}
;	*(dest + iterator) = 0;
;	return (dest);
;}

		section .text
		global _ft_strcpy

_ft_strcpy:
			xor		rcx, rcx					; azzero "iteratore"		
			cmp		rsi, 0						;confronto src con 0
			jz		_return						;se sono uguali ritorno
			jmp		_copy						;se non lo sono salta al ciclo di copia
_incrementa:
			inc		rcx							;incremento "iteratore"
_copy:
			mov		r10b, BYTE [rsi + rcx]		;salvo il char in 1BYTE r10b
			mov		BYTE [rdi + rcx], r10b		;copio il char salvato in BYTE r10b in rdi posizionato in posizione iteratore
			cmp		r10b, 0						; confronto il char storato in 1BYTE con 0
			jnz		_incrementa					; se non sono uguali ricomincio il ciclo incrementando
_return:
			mov		rax, rdi					;return dst
			ret
